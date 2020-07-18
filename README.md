# MicroBit_Arduino_IDE

En este repositorio encontrarás algunos ejemplos para programar la placa de desarrollo MicroBit con el IDE de arduino.

* Acelerometro_megnetometro_temperatura
* Botones
* LED_PWM
* Matriz
* OLED (128x32 I2C SSD1306)
* RADIO

## Instrucciones Para configurar el IDE de Arduino.

*	Conectar la MicroBit a la PC - cargarle "microbit-adv.hex"
*	Abrir IDE ARDUINO
*	Ir a archivos - preferencias - agregar esta URL:
https://sandeepmistry.github.io/arduino-nRF5/package_nRF5_boards_index.json
*	Herramientas - gestor de tarjetas - ir hasta abajo de todo - instalar Nordic Semiconductor nRF Boards
*	Herramientas - placa - BBC Micro bit
*	Soft Device - S110
*	Puerto - seleccionar el que dice COM (BBC micro:bit)
*	Programa - incluir libreria - Gestor de biblioteca
*	Instalar las siguientes librerias en este orden:
1) Adafruit_GFX_Library
2) BLEPeripheral
3) Adafruit_microbit_Library
4) NRF51_Radio_library
