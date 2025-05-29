README — Projeto Bueiro Inteligente com Alerta via SMS

🚀 Descrição do Projeto
O projeto consiste em um bueiro inteligente, desenvolvido para monitorar o nível de resíduos dentro de seu compartimento. O sistema utiliza um sensor ultrassônico para medir a altura dos resíduos e, quando atinge um limite previamente definido, envia um SMS de alerta para o responsável pela manutenção, utilizando o módulo GSM SIM800L.

Este projeto visa prevenir o entupimento dos bueiros, facilitando a manutenção preventiva e reduzindo alagamentos urbanos.

🧠 Funcionamento
O sensor ultrassônico HC-SR04 mede a distância entre o topo do bueiro e o nível do lixo.

Quando a distância é menor ou igual a 10 cm, significa que o bueiro está cheio.

Nesse momento, o sistema ativa um alerta:

No protótipo: som de um buzzer e mensagem no display LCD.

Na aplicação real: envio de SMS via módulo GSM SIM800L, informando que o bueiro precisa de esvaziamento.

🔧 Componentes Utilizados
🎛️ No protótipo (imagem do simulador):
1x Arduino Uno

1x Sensor Ultrassônico HC-SR04

1x Display LCD 16x2 + módulo I2C (opcional, mas recomendado)

1x Buzzer Piezoelétrico

1x Protoboard

Cabos jumpers macho-macho e macho-fêmea

🔗 Componentes adicionais para o envio de SMS (não disponíveis no simulador):
1x Módulo GSM GPRS SIM800L

1x Fonte de alimentação externa (4V a 4.2V — fundamental para o SIM800L)

Capacitores de desacoplamento (1000uF, opcional para estabilidade)

Regulador de tensão ou divisor de tensão para comunicação dos pinos RX/TX com o Arduino (pois o SIM800L opera com 3.3V nos pinos de sinal)

🔌 Esquemático de Conexões (Protótipo do Simulador)
Componente	Pino no Arduino	Descrição
HC-SR04 - Trig	D9	Disparo do ultrassônico
HC-SR04 - Echo	D10	Recepção do sinal
HC-SR04 - VCC	5V	Alimentação
HC-SR04 - GND	GND	Terra
Buzzer	D8	Alerta sonoro
LCD RS	D12	Comunicação
LCD E	D11	Comunicação
LCD D4-D7	D5-D2	Comunicação
LCD VCC/GND	5V/GND	Alimentação

📡 Conexão do Módulo GSM SIM800L
Módulo SIM800L	Pino no Arduino	Descrição
VCC	Fonte externa (4V)	⚠️ Nunca ligar direto no 5V do Arduino
GND	GND	Terra
TX	D7 (RX Arduino)	Comunicação serial
RX	D6 (TX Arduino, com divisor de tensão)	Comunicação serial

🔋 Observação: O SIM800L precisa de alimentação estável entre 4.0V e 4.2V, com pelo menos 2A de corrente. Uma fonte dedicada é indispensável.

📨 Lógica do Envio de SMS
Quando o nível do lixo atingir ou ultrapassar o limite (distância ≤ 10 cm), o Arduino envia comandos AT para o SIM800L, que realiza o envio do SMS com a seguinte mensagem:

📲 “Atenção! O bueiro localizado em [local] está cheio. Favor realizar a manutenção.”

📷 Imagens do Projeto
✅ Protótipo no simulador:
(./assets/img/print-tinkercad.png)

✅ Módulo GSM SIM800L:
(./assets/img/Modulo-Gsm.png)

