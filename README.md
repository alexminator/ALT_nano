# [ALT](https://github.com/alexminator/ALT_nano/) - Another Level Tank.

[![first-timers-only](https://img.shields.io/badge/first--timers--only-friendly-tomato.svg?style=flat&logo=git)](https://github.com/alexminator/ALT_nano/issues?q=is%3Aissue+is%3Aopen+label%3Afirst-timers-only) [![GitHub license](https://img.shields.io/github/license/alexminator/ALT_nano.svg?logo=github)](https://github.com/vinitshahdeo/Water-Monitoring-System/blob/master/LICENSE) [![GitHub stars](https://img.shields.io/github/stars/alexminator/ALT_nano.svg?logo=github)](https://github.com/alexminator/ALT_nano/stargazers) [![GitHub forks](https://img.shields.io/github/forks/alexminator/ALT_nano.svg?logo=github&color=teal)](https://github.com/alexminator/ALT_nano/network/members) [![GitHub top language](https://img.shields.io/github/languages/top/alexminator/ALT_nano?color=yellow&logo=javascript)](https://github.com/alexminator/ALT_nano/) 


*Este proyecto es una versión más de un monitor de nivel de agua para tanque. El sistema de monitoreo de agua es un sistema de medición de nivel de líquido para mantener al usuario alertado en caso de desbordamiento de líquido o cuando el tanque se agota. Se fijará un sensor ultrasónico, que se colocará sobre el tanque apuntando al líquido. El sensor ultrasónico se utiliza para medir, comparar la profundidad del contenedor y el nivel de líquido. El estado del sistema podrá monitorearse mediante una pantalla LCD y un zumbador suena cuando el límite excede la cantidad de llenado permitida o decae por debajo de un límite fijado. Mediante el botón podremos silenciar las alarmas con una pulsación larga y también encender la luz de fondo del LCD para mejor visión con una pulsación corta.*

> **Puedes ver una demo [aqui](https://wokwi.com/projects/356392498196222977).**

*This project is one more version of a tank water level monitor. The water monitoring system is a liquid level measurement system to keep the user alerted in case of liquid overflow or when the tank runs out. An ultrasonic sensor will be fixed, which will be placed on the tank pointing at the liquid. The ultrasonic sensor is used to measure, compare the depth of the container and the liquid level.
System status can be monitored via an LCD display and a buzzer sounds when the limit exceeds the allowable fill amount or falls below a set limit. Through the button we can silence the alarms with a long press and also turn on the LCD backlight for better vision with a short press.*

> **You can view the demo [here](https://wokwi.com/projects/356392498196222977).**

[![ALT](https://img.shields.io/badge/ALT-teal.svg?colorA=teal&colorB=orange&style=for-the-badge)](https://github.com/alexminator/ALT_nano/) [![Arduino](https://img.shields.io/badge/Arduino-Project-teal.svg?colorA=blue&colorB=red&style=for-the-badge)](https://github.com/alexminator/ALT_nano/)

```js
         .8.          8 8888         8888888 8888888888
        .888.         8 8888               8 8888
       :88888.        8 8888               8 8888
      . `88888.       8 8888               8 8888
     .8. `88888.      8 8888               8 8888
    .8`8. `88888.     8 8888               8 8888
   .8' `8. `88888.    8 8888               8 8888
  .8'   `8. `88888.   8 8888               8 8888
 .888888888. `88888.  8 8888               8 8888
.8'       `8. `88888. 8 888888888888       8 8888

```

### Las metas de este proyecto son :

- **_Monitoreo 24/7 del nivel de tanque_**
- **_Evitar derramamiento de agua por desbordamiento_**
- **_Evitar que el tanque quede vacio y deje la casa sin suminsitro de agua_**

### Goals of this project :

- **_24/7 tank level monitoring_**
- **_Avoid spillage of water due to overflow_**
- **_Prevent the tank from being empty and leaving the house without a water supply_**

### Instalación 🔧

Los componentes necesarios son:

- **Arduino Nano**
- **Pantalla LCD 20x4**
- **Botón**
- **Zumbador**
- **Resitencia valor 10K**
- **Sensor ultrasónico a prueba de agua [JSN-SR04T](https://naylampmechatronics.com/img/cms/Datasheets/JSN-SR04T-2-0.pdf)**

*Para este proyecto use un Arduino nano debido a su pequeño tamaño, al cual se le conectara un sensor y actuadores. Para mostrar la información se eligió una pantalla LCD de 20x4 con espacio suficiente para dibujar una animación del llenado del tanque. Un zumbador para la notificación y un botón para control. Para una mayor duración de vida del sensor ultrasónico se escogió el JSN-SR04T el cual es a prueba de agua. Si no posee este sensor y utiliza otro cerciórese de protegerlo contra la humedad.*

### Instalation 🔧

The Arduino(Hardware) components required are:

- **Arduino Nano**
- **LCD screen 20x4**
- **A button**
- **A buzzer**
- **A 10k resistor**
- **A waterproof ultrasonic sensor [JSN-SR04T](https://naylampmechatronics.com/img/cms/Datasheets/JSN-SR04T-2-0.pdf)**

*For this project I used an Arduino nano due to its small size, to which a sensor and actuators will be connected. To display the information, a 20x4 LCD display was chosen with enough space to draw an animation of the tank filling. A buzzer for notification and a button for control.For a longer life of the ultrasonic sensor, the JSN-SR04T was chosen, which is waterproof. If you do not have this sensor and use another, make sure to protect it against moisture.*

| ARDUINO PINS | LCD PINS    |  
| ------------ | ----------- | 
|  12-  `D12`  |   15 - `A`  |
|  11-  `D11`  |   4 - `RS`  |
|  10-  `D10`  |   6 - `E`   |
|  9-  `D9`    |   11 - `D4` |
|  8-  `D8`    |   12 - `D5` |
|  7-  `D7`    |   13 - `D6` |
|  6-  `D6`    |   14 - `D7` |
|    GND       |   16 - `K`  |
|    GND       |   1 - `VSS` |
|   VCC(5v)    |   2 - `VDD` |
| ARDUINO PINS | BUTTON PINS | 
|  3-  `D3`    |   1 - 3     | 
|    GND       |   2 - 4     |  
| ARDUINO PINS | BUZZER PINS |
|  4-  `D4`    |     +       |
|    GND       |     -       |
| ARDUINO PINS | JSN-SR04T   |
|  2-  `D2`    |  `TRIGGER`  |
|  3-  `D5`    |   `ECHO`    |
|   VCC(5v)    |    VCC      |
|    GND       |    GND      |

**NOTA**: **Del pin 1-3 del boton conectar una resistencia de 10 k a VCC (5v).**

**NOTE**: **From pin 1-3 of the button connect a 10k resistor to VCC (5v).**

![Diagram](https://github.com/alexminator/ALT_nano/blob/master/diagrama.jpg?raw=true)

### Build with 🛠️
* [VSCODE](https://code.visualstudio.com/) -A source code editor.
* [PlatFormio](https://platformio.org/) - Open programming IDE for C/C++, hardware oriented.

## Thanks 🎁
* _A cuban maker community._
* _All member of the telegram group [**Arduino**](https://t.me/arduchino)._
