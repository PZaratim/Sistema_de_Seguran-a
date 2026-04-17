# Sistema de Alarme com ESP32

## Descrição

Este projeto apresenta um sistema de alarme desenvolvido com ESP32, utilizando um sensor de movimento (PIR) para detectar presença e um buzzer para emissão de alerta sonoro. A proposta é demonstrar, de forma prática, a integração entre hardware e software em sistemas embarcados voltados à segurança.

## Funcionalidades

* Detecção de movimento em tempo real
* Acionamento de alerta sonoro (buzzer)
* Botão de controle para ligar/desligar o sistema
* Botão de emergência para desativação imediata do alarme
* Botão de área segura para cancelamento do alerta em condições específicas
* Implementação com detecção de borda para maior estabilidade

## Estrutura do Sistema

O sistema é composto por:

* ESP32 (controlador principal)
* Sensor PIR (detecção de movimento)
* Buzzer (alerta sonoro)
* Três botões (controle, emergência e área segura)

## Lógica de Funcionamento

* O sistema pode ser ativado ou desativado por um botão dedicado
* Quando ativo, o sensor PIR monitora o ambiente
* Ao detectar movimento, o buzzer é acionado
* O botão de emergência desativa o alarme imediatamente
* O botão de área segura cancela o alerta apenas quando o sistema está ativo

## Tecnologias Utilizadas

* ESP-IDF
* FreeRTOS
* Linguagem C

## Status do Projeto

Versão Beta

Este projeto está em desenvolvimento e servirá como base para futuras melhorias, como integração com rede, notificações remotas e expansão das funcionalidades de segurança.

## Possíveis Melhorias

* Integração com Wi-Fi
* Envio de notificações (MQTT ou HTTP)
* Interface com LEDs para status do sistema
* Implementação de máquina de estados (FSM)
* Padrões de sirene mais realistas

## Objetivo

Aplicar conceitos de sistemas embarcados, controle de estados e interação com hardware, criando uma base sólida para projetos de automação e segurança.

## Desenvolvido com ESP32
