#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

#define SENSOR 14
#define BUZZER 18    // Led e Buzzer
#define BOTAO 5      // emergência
#define BOTAO1 4     // área segura
#define BOTAO2 19    // liga e desliga

void app_main() {

    gpio_set_direction(SENSOR, GPIO_MODE_INPUT);
    gpio_set_direction(BUZZER, GPIO_MODE_OUTPUT);
    gpio_set_direction(BOTAO, GPIO_MODE_INPUT);
    gpio_set_pull_mode(BOTAO, GPIO_PULLUP_ONLY);
    gpio_set_direction(BOTAO1, GPIO_MODE_INPUT);
    gpio_set_pull_mode(BOTAO1, GPIO_PULLUP_ONLY);
    gpio_set_direction(BOTAO2, GPIO_MODE_INPUT);
    gpio_set_pull_mode(BOTAO2, GPIO_PULLUP_ONLY);

    int movimento_detectado = 0;
    int sistema_ativo = 0;
    int botao_anterior = 1;
    int botao1_anterior = 1;
    int botao2_anterior = 1;
    int estado_anterior = 0;

    while (true) {
        int estado = gpio_get_level(SENSOR);
        int botao = gpio_get_level(BOTAO);
        int botao1 = gpio_get_level(BOTAO1);
        int botao2 = gpio_get_level(BOTAO2);

        //BOTAO2 -> liga/desliga sistema
        if (botao2 == 0 && botao2_anterior == 1) {

            sistema_ativo = !sistema_ativo;

            if (sistema_ativo) {
                printf("SISTEMA ATIVADO\n");
                sistema_ativo = 1;
            } else {
                printf("SISTEMA DESATIVADO\n");
                movimento_detectado = 0;
                sistema_ativo = 0;
            }

            vTaskDelay(pdMS_TO_TICKS(200)); // debounce
        }
        botao2_anterior = botao2;

        //Sensor só funciona com sistema ativo
        if (sistema_ativo) {
            if (estado == 1 && estado_anterior == 0) {
                printf("MOVIMENTO DETECTADO!\n");
                movimento_detectado = 1;
            }
        }
        estado_anterior = estado;

        //BOTAO = emergência
        if (botao == 0 && botao_anterior == 1) {
            movimento_detectado = 0;
            printf("ALARME DESATIVADO (EMERGÊNCIA)\n");
        }
        botao_anterior = botao;

        //BOTAO1 = área segura
        if (botao1 == 0 && botao1_anterior == 1) {
            if (sistema_ativo && movimento_detectado) {
                printf("ÁREA SEGURA\n");
                movimento_detectado = 0;
            }
        }
        botao1_anterior = botao1;

        //Buzzer
        if (sistema_ativo && movimento_detectado) {
            gpio_set_level(BUZZER, 1);
        } else {
            gpio_set_level(BUZZER, 0);
        }

        vTaskDelay(pdMS_TO_TICKS(20));
    }
}