<h1 align="center">
  <img alt="ALT logo" src="https://github.com/alexminator/ALT_nano/blob/master/img/ALT_logo.png" width="300px"/><br/><strong>Another Level Tank</strong>
  
  <a href="https://github.com/alexminator/ALT_nano/blob/master/README_es.md">
    <img height="20px" src="https://img.shields.io/badge/ES-flag.svg?color=555555&style=flat-square&logo=data:image/svg+xml;base64,PHN2ZyB4bWxucz0iaHR0cDovL3d3dy53My5vcmcvMjAwMC9zdmciIHZpZXdCb3g9IjAgMCA3NTAgNTAwIj4NCjxwYXRoIGZpbGw9IiNjNjBiMWUiIGQ9Im0wLDBoNzUwdjUwMGgtNzUweiIvPg0KPHBhdGggZmlsbD0iI2ZmYzQwMCIgZD0ibTAsMTI1aDc1MHYyNTBoLTc1MHoiLz4NCjwvc3ZnPg0K">
  </a>
  <a href="https://github.com/alexminator/ALT_nano/blob/master/README.md">
    <img height="20px" src="https://img.shields.io/badge/EN-flag.svg?color=555555&style=flat-square&logo=data:image/svg+xml;base64,PHN2ZyB3aWR0aD0iMTIwMCIgeG1sbnM9Imh0dHA6Ly93d3cudzMub3JnLzIwMDAvc3ZnIiB2aWV3Qm94PSIwIDAgNjAgMzAiIGhlaWdodD0iNjAwIj4NCjxkZWZzPg0KPGNsaXBQYXRoIGlkPSJ0Ij4NCjxwYXRoIGQ9Im0zMCwxNWgzMHYxNXp2MTVoLTMwemgtMzB2LTE1enYtMTVoMzB6Ii8+DQo8L2NsaXBQYXRoPg0KPC9kZWZzPg0KPHBhdGggZmlsbD0iIzAwMjQ3ZCIgZD0ibTAsMHYzMGg2MHYtMzB6Ii8+DQo8cGF0aCBzdHJva2U9IiNmZmYiIHN0cm9rZS13aWR0aD0iNiIgZD0ibTAsMGw2MCwzMG0wLTMwbC02MCwzMCIvPg0KPHBhdGggc3Ryb2tlPSIjY2YxNDJiIiBzdHJva2Utd2lkdGg9IjQiIGQ9Im0wLDBsNjAsMzBtMC0zMGwtNjAsMzAiIGNsaXAtcGF0aD0idXJsKCN0KSIvPg0KPHBhdGggc3Ryb2tlPSIjZmZmIiBzdHJva2Utd2lkdGg9IjEwIiBkPSJtMzAsMHYzMG0tMzAtMTVoNjAiLz4NCjxwYXRoIHN0cm9rZT0iI2NmMTQyYiIgc3Ryb2tlLXdpZHRoPSI2IiBkPSJtMzAsMHYzMG0tMzAtMTVoNjAiLz4NCjwvc3ZnPg0K">
  </a>
</h1>

<a name="readme-top"></a>

<h1 align="center">
  
[![GitHub repo size](https://img.shields.io/github/repo-size/alexminator/ALT_nano?logo=github&style=plastic)](https://github.com/alexminator/ALT_nano/)
[![GitHub License](https://img.shields.io/github/license/alexminator/ALT_nano.svg?logo=github&style=plastic&colorB=68B7EB)](https://github.com/alexminator/ALT_nano/blob/master/LICENSE) 
[![GitHub stars](https://img.shields.io/github/stars/alexminator/ALT_nano.svg?style=plastic&logo=github&color=yellow)](https://github.com/alexminator/ALT_nano/stargazers) 
[![GitHub forks](https://img.shields.io/github/forks/alexminator/ALT_nano.svg?logo=github&color=teal&style=plastic)](https://github.com/alexminator/ALT_nano/network/members)
[![GitHub top language](https://img.shields.io/github/languages/top/alexminator/ALT_nano?logo=github&style=plastic&color=blueviolet)](https://github.com/alexminator/ALT_nano/)
[![GitHub contributors](https://img.shields.io/github/contributors/alexminator/ALT_nano?logo=github&style=plastic)](https://github.com/alexminator/ALT_nano/)
[![Watchers](https://img.shields.io/github/watchers/alexminator/ALT_nano?logo=github&color=teal&style=plastic)](https://github.com/alexminator/ALT_nano/watchers)  
</h1> 

<h4 align="center">:star: Dame una estrella — me motivará a seguir mejorándolo!</h4>

<!-- TABLE OF CONTENTS -->
<details>
  <summary>Tabla de Contenido</summary>
  <ol>
    <li>
      <a href="#sobre-el-proyecto">Sobre el proyecto</a>
      <ul>
        <li><a href="#metas">Metas</a></li>
      </ul>
    </li>
    <li>
      <a href="#comencemos">Comencemos</a>
      <ul>
        <li><a href="#componentes">Componentes</a></li>
        <li><a href="#instalación">Instalación</a></li>
        <li><a href="#diagrama">Diagrama</a></li>
        <li><a href="#compilar-y-cargar">Compilar y cargar</a></li>
      </ul>
    </li>
    <li><a href="#calibración-y-configuración">Calibración y configuración</a></li>
    <li><a href="#funcionamiento">Funcionamiento</a></li>
    <li><a href="#solución-de-problemas">Solución de problemas</a></li>
    <li><a href="#por-hacer">Por hacer</a></li>
    <li><a href="#colaboradores">Colaboradores</a></li>
    <li><a href="#licencia">Licencia</a></li>
    <li><a href="#contacto">Contacto</a></li>
    <li><a href="#programas">Programas</a></li>
    <li><a href="#agradecimientos">Agradecimientos</a></li>
  </ol>
</details>

<!-- ABOUT THE PROJECT -->
## Sobre el proyecto

ALT_nano es un monitor de nivel de tanque basado en Arduino. Un sensor ultrasónico mide la distancia de aire sobre el agua y una pantalla LCD de 20×4 muestra el nivel y volumen estimados. Un zumbador avisa de las alarmas configurables de nivel bajo y alto; el botón silencia una alarma activa o enciende la retroiluminación. Este proyecto es una ayuda de monitoreo, no un sistema certificado de prevención de desbordamientos.

**Puedes ver una demo [aqui](https://wokwi.com/projects/356392498196222977).**
> **Warning** :
En Wokwi, pulsa **Start** y haz clic en el sensor ultrasónico para cambiar la distancia simulada. El firmware acepta actualmente lecturas entre **20 y 104 cm** (`DEAD_ZONE` y `DIST_TOPE`). Con 104 cm el tanque se considera vacío; con 20 cm esta configuración marca el 100 %. La documentación del JSN-SR04T especifica una zona ciega nominal de 25 cm, por lo que los 20 cm configurados son un valor empírico para este montaje y no garantizan lecturas fiables en todos los sensores o instalaciones. Comprueba las mediciones en tu tanque y aumenta el mínimo si son inestables. El 100 % es una escala del software, no una garantía contra desbordamientos.

### Metas 

- **_Monitoreo 24/7 del nivel de tanque_**
- **_Evitar derramamiento de agua por desbordamiento_**
- **_Evitar que el tanque quede vacio y deje la casa sin suminsitro de agua_**

<a href="#readme-top"><img align="right" border="0" src="https://github.com/alexminator/ALT_nano/blob/master/img/up_arrow.png" width="22" ></a>

---

<!-- GETTING STARTED -->
## Comencemos

[![Arduino](https://img.shields.io/badge/Arduino-Project-teal.svg?colorA=teal&colorB=red&style=for-the-badge)](https://github.com/alexminator/ALT_nano/)

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
### Componentes

Este proyecto usa un Arduino Nano, una pantalla LCD paralela de 20×4, un sensor ultrasónico de distancia, un zumbador y un botón. El hardware de ejemplo utiliza un sensor **JSN-SR04T** resistente al agua. Si usas otro sensor, verifica su voltaje, alcance, temporización y distancia mínima fiable antes de conectarlo.

Los componentes necesarios son:

- **Arduino Nano**
- **Pantalla LCD 20x4**
- **Botón**
- **Zumbador**
- **Resistencia de 10 kΩ** (pull-up del botón)
- **Potenciómetro de 10 kΩ** (contraste del LCD)
- **Sensor ultrasónico a prueba de agua [JSN-SR04T](https://naylampmechatronics.com/img/cms/Datasheets/JSN-SR04T-2-0.pdf)**

<a href="#readme-top"><img align="right" border="0" src="https://github.com/alexminator/ALT_nano/blob/master/img/up_arrow.png" width="22" ></a>

---

### Instalación 

*A continuación se muestra el diagrama de conexiones y una tabla con los pines que se conectarán.*

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
|  5-  `D5`    |   `ECHO`    |
|   VCC(5v)    |    VCC      |
|    GND       |    GND      |

**Configuración del LCD:** Conecta `R/W` (pin 5 del LCD) a GND. Conecta `V0` (pin 3, contraste) al terminal central de un potenciómetro de 10 kΩ y los extremos del potenciómetro a 5 V y GND. Ajústalo hasta que los caracteres sean visibles.

> **Cableado del botón:** El firmware configura D3 como `INPUT` (no `INPUT_PULLUP`). Conecta el botón y la resistencia pull-up externa de 10 kΩ según el diagrama; comprueba que la entrada esté en HIGH en reposo y LOW al pulsar. No conectes la retroiluminación del LCD directamente si consume más corriente de la permitida por el pin del Arduino; usa un transistor/driver adecuado si hace falta.

### Diagrama

![Diagram](https://github.com/alexminator/ALT_nano/blob/master/img/diagrama.jpg?raw=true)

> ### :point_right: Puede encontrar el esquema [aquí](https://github.com/alexminator/ALT_nano/blob/master/img/ALT-UNO.fzz). :star:

<a href="#readme-top"><img align="right" border="0" src="https://github.com/alexminator/ALT_nano/blob/master/img/up_arrow.png" width="22" ></a>
---

## Compilar y cargar

Este es un proyecto de PlatformIO para **Arduino Nano ATmega328P**. Instala [VS Code](https://code.visualstudio.com/) y la extensión [PlatformIO IDE](https://platformio.org/install/ide?install=vscode), abre este repositorio como proyecto y permite que PlatformIO instale las dependencias declaradas en `platformio.ini`. Selecciona el perfil de placa Nano ATmega328P (y la variante de procesador/bootloader correcta si tu placa la requiere).

Desde la terminal de PlatformIO, compila y carga el firmware con:

```sh
pio run
pio run --target upload
```

Selecciona el puerto serie correcto en PlatformIO si no se detecta automáticamente. También puedes instalar PlatformIO Core y ejecutar los mismos comandos desde la carpeta del proyecto.

## Código y depuración

La librería `Tank` dibuja la animación; `LiquidCrystal` controla una pantalla paralela de 20×4 y `NewPing` lee el sensor ultrasónico. Los demás archivos gestionan alarmas, sonido, caracteres personalizados y diagnóstico. El firmware actual usa una **pantalla LCD paralela**, no un adaptador I2C. Para cambiar a I2C hay que modificar la librería, el cableado y la inicialización.

Para activar los mensajes de diagnóstico por serie, cambia la definición al inicio de `src/main.cpp`:

```cpp
#define DEBUGLEVEL DEBUGLEVEL_DEBUGGING
// #define DEBUGLEVEL DEBUGLEVEL_NONE
```

El monitor serie está configurado a **9600 baudios**. Los niveles de detalle disponibles están definidos en `src/debug.h`.

El sensor mide la distancia vacía desde su cara hasta la superficie del agua. Si el sensor está en la parte superior del tanque, la altura de la columna de agua es aproximadamente **C = H − D**, donde **H** es la distancia desde la referencia del sensor hasta el fondo y **D** es el espacio de aire medido. Si el sensor está instalado por encima del tanque, incluye ese desplazamiento en `DIST_TOPE` o calibra de forma coherente el punto de referencia.

<figure>
  <img src="https://github.com/alexminator/ALT_nano/blob/master/img/fig%202.png" width="500" alt="Relación entre la distancia del sensor y la altura de la columna de agua" />
  <figcaption>Referencia para convertir la distancia de aire medida en altura de la columna de agua.</figcaption>
</figure>

### Calibración y configuración

Los ajustes principales están en `src/main.cpp`:

| Ajuste | Valor actual | Significado |
| --- | ---: | --- |
| `DIST_TOPE` | 104 cm | Distancia del sensor al agua con el tanque vacío; referencia de vacío. |
| `DEAD_ZONE` | 20 cm | Distancia mínima aceptada y valor usado para escalar el nivel hasta 100 %. La especificación del JSN-SR04T indica una zona ciega nominal de 25 cm; los 20 cm configurados son el valor empírico usado en este firmware. Consérvalo solo si el sensor instalado mide de forma estable a esa distancia. |
| `MAX_DISTANCE` | 200 cm | Distancia máxima solicitada a NewPing; debe cubrir el tanque y respetar el alcance del sensor. |
| `NIVEL_BAJO` / `NIVEL_ALTO` | 20 % / 100 % | Umbrales de las alarmas de nivel bajo y alto. |
| `ancho`, `largo`, `tabiqueA`, `tabiqueL` | cm | Dimensiones del tanque rectangular y del tabique central que usa la fórmula de volumen. |

Mide y verifica estos valores con el tanque y el sensor reales. El intervalo de distancia aceptado actualmente es **20–104 cm**. Las lecturas por debajo del mínimo configurado o por encima de `DIST_TOPE` se consideran inválidas. El nivel se limita al rango 0–100 %; alcanzar 100 % significa llegar al máximo de la escala configurada, **no que sea imposible un desbordamiento**. Configura la alarma alta por debajo del punto real de rebose y deja un margen de seguridad.

La fórmula actual de volumen supone un tanque rectangular con un tabique rectangular central que desplaza agua. Para otra forma o tabique, adapta `Sensor::get_volume()`; de lo contrario, el volumen mostrado será incorrecto. La geometría también supone que el agua es una superficie adecuada para el ultrasonido; evita obstáculos, aberturas estrechas, turbulencia y superficies inclinadas cuando sea posible. Compara el volumen mostrado con una cantidad de agua conocida antes de confiar en la medición.

### Funcionamiento

- La pantalla muestra nivel (%), distancia del sensor (cm), volumen estimado (L) y un gráfico de llenado.
- Las alarmas de nivel bajo/alto se confirman tras **10 lecturas válidas consecutivas** en el umbral. Las lecturas inválidas se filtran; después de **3 lecturas inválidas consecutivas**, la pantalla indica un error del sensor.
- Mantén pulsado el botón para silenciar una alarma activa. La alarma puede volver a sonar si la condición desaparece y luego reaparece.
- Pulsar el botón enciende la retroiluminación. Se apaga automáticamente tras aproximadamente **60 segundos**; una alarma la vuelve a encender.

### Solución de problemas

| Síntoma | Comprobaciones |
| --- | --- |
| Aparece `ERROR` en la pantalla | Revisa alimentación del sensor, GND común, TRIG en D2, ECHO en D5, orientación del sensor y que la distancia esté entre `DEAD_ZONE` y `DIST_TOPE`. |
| El nivel o el volumen no parecen correctos | Vuelve a medir `DIST_TOPE` y las dimensiones del tanque; confirma las unidades en cm y que la forma del tanque coincide con la fórmula de `get_volume()`. |
| Las lecturas saltan cerca del agua | Orienta el sensor perpendicular a una superficie tranquila; verifica la distancia mínima fiable y aumenta `DEAD_ZONE` si es necesario. |
| La alarma no coincide con el nivel deseado | Ajusta `NIVEL_BAJO` / `NIVEL_ALTO`; recuerda que se requieren 10 lecturas consecutivas. |
| La pantalla está apagada o ilegible | Comprueba alimentación/contraste del LCD, el cableado paralelo y el circuito de retroiluminación; verifica también la placa y el puerto al cargar el firmware. |

Este proyecto es una ayuda de monitoreo, no un sistema certificado de seguridad o prevención de desbordamientos. Si un rebose pudiera causar daños, usa además un interruptor de flotador independiente u otro mecanismo a prueba de fallos. Instala el sensor, cableado y electrónica en un entorno debidamente protegido.

<figure>
  <img src="https://github.com/alexminator/ALT_nano/blob/master/img/fig%202.png" width="500" alt="Relación entre la distancia del sensor y la altura de la columna de agua" />
  <figcaption>Referencia para convertir la distancia de aire medida en altura de la columna de agua.</figcaption>
</figure>

<a href="#readme-top"><img align="right" border="0" src="https://github.com/alexminator/ALT_nano/blob/master/img/up_arrow.png" width="22" ></a>

---

## Por hacer

Las siguientes ideas son mejoras futuras; **no están implementadas en el firmware actual**.

*Hacer una versión universal del proyecto que incluya las siguientes características.*

**_Por la parte del software:_**

+ Incluir un menú para configurar **TODAS** las variables posibles.
  - Tipo de tanque. Para un calculo preciso del volumen de agua.
      * Cilíndrico o rectangular.
  - Dimensiones del tanque. La altura del tanque puede ser introducida tanto de forma manual como automática. 
  - Nivel para activar la alarma por bajo y por alto.
  - Elección del modo de trabajo del dispositivo.  
      * Manual, el usuario toma las decisiones.  
      * Automático, al alcanzar el bajo nivel del tanque se medirá el nivel en la cisterna si es suficiente se activará la bomba y se llenará el tanque.
  - Elección del tono de alarma.
  - Incluir el flujo de agua entrante a mostrar en la pantalla.
  - Elección de la información a mostrar en pantalla.

**_Por la parte del hardware:_**

+ Poder usar diferentes pantallas.  
     - LCD.
     - OLED
+ Aumentar la cantidad de botones a 3, para una fácil navegación por el menú.
+ Agregar modulo relé para control de la bomba de llenado del tanque.
+ Agregar un sensor de flujo para protección de la bomba de llenado y contabilizar las cantidades de agua que entra al tanque.
+ Agregar un segundo sensor ultrasónico para medir el nivel de la cisterna y que el llenado sea automático al alcanzarse el bajo nivel. 
+ Y por último si el tiempo me alcanza hacer una versión con esp32 que incluya una web embebida y hacer todo el control desde su móvil.

<a href="#readme-top"><img align="right" border="0" src="https://github.com/alexminator/ALT_nano/blob/master/img/up_arrow.png" width="22" ></a>

---

## Colaboradores

<table style="width:100%">
  <tr>
    <th><b>Alexminator</b></th>
    <th><b>20-EverGreen-2</b></th>
    
  </tr>
  <tr>
    <td align="center"><a href="https://github.com/alexminator"><img src="https://avatars.githubusercontent.com/u/9116486?s=400&v=4" width=150px height=150px alt="alexminator"/></a></td>
    <td align="center"><a href="https://github.com/20-EverGreen-2"><img src="https://avatars.githubusercontent.com/u/84293898?v=4" width="100px;" alt="20-EverGreen-2"></a></td>
    
  </tr>
  <tr>
    <td align="center"><a href="https://twitter.com/alexminator99"><img src="img/twitter-48.png" width="32px" height="32px"></a> <a href="https://www.facebook.com/alexander.rivasalpizar/"><img src="img/facebook-48.png" width="32px" height="32px"></a> <a href="https://www.linkedin.com/in/alexander-rivas-73532037/"><img src="img/linkedin-48.png" width="32px" height="32px"></a><a href="https://t.me/Alexminator"><img src="img/telegram-app-48.png" width="32px" height="32px"></a></td>
    <td align="center"><a href="https://t.me/Deltatronics"><img src="img/telegram-app-48.png" width="32px" height="32px"></a></td>
    
  </tr>
</table>

## Licencia

Este proyecto se publica bajo la licencia [MIT](LICENSE). Consulta el archivo `LICENSE` para ver los términos completos.

## Contacto

> **_Necesita ayuda?_** 
**_Contácteme 📨 [alexminator99@gmail.com](mailto:alexminator99@gmail.com?Subject=ALT_nano_issues)_**

[![GitHub followers](https://img.shields.io/github/followers/alexminator.svg?label=Follow%20@alexminator&style=social)](https://github.com/alexminator/) [![Twitter Follow](https://img.shields.io/twitter/follow/alexminator?style=social)](https://twitter.com/alexminator99)

## Programas 
* [VSCODE](https://code.visualstudio.com/) -Editor de código.
* [PlatFormio](https://platformio.org/) - IDE de programación para C/C++, orientado al hardware.

## Agradecimientos 
* _A la comunidad cubana de Arduino._
* _A todo aquel que me brindo su ayuda cuando tenía dudas, en especial a mi hijo._

<a href="#readme-top"><img align="right" border="0" src="https://github.com/alexminator/ALT_nano/blob/master/img/up_arrow.png" width="22" ></a>

---
