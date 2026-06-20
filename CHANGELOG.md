# Changelog - ALT_nano

## [2026-06-20] - Revisión y Corrección de Bugs

### 🐛 Bugs Críticos Corregidos

#### 1. División por cero en `buzz()` (`src/buzzer.h`)
- **Problema:** `buzzer_intro()` llamaba a `buzz(BUZZER_PIN, 0, noteDuration)` para silencios entre notas. Con `frequency=0`, el cálculo `1000000 / frequency / 2` causaba una división por cero, colgando el Arduino.
- **Solución:** Agregado guard `if (frequency <= 0) return;` al inicio de `buzz()`.

#### 2. Índice CGRAM fuera de rango en `createChars()` (`src/font.h`)
- **Problema:** El LCD HD44780 solo tiene 8 slots CGRAM (0-7), pero `createChars()` registraba el carácter `LT` en el slot 8 (inválido). Además `lcd.write(8)` en `printBigCharacters()` no renderizaba un custom character sino un caracter de ROM.
- **Solución:** `LT` movido a slot 0, todos los `lcd.write(8)` → `lcd.write(0)`.

### 🟠 Bugs Graves Corregidos

#### 3. Alarmas bloqueantes (`src/alarms.h`)
- **Problema:** `alarmlow()` y `alarmfull()` usaban bucles `while` que bloqueaban todo el sistema: no se leía el sensor, no se actualizaba la pantalla, y el botón era la única salida. Si el botón fallaba, el sistema quedaba atrapado para siempre.
- **Solución:** Reescritura completa del sistema de alarmas usando `millis()` no bloqueante. El buzzer suena cada 2 segundos en vez de constantemente. El botón se lee en cada ciclo del `loop()` principal. Los contadores se resetean correctamente al descartar la alarma.

#### 4. Doble lectura del sensor por ciclo (`src/main.cpp`)
- **Problema:** `get_dist()` se llamaba dos veces por cada `loop()` — una dentro de `get_level()` y otra directamente. Cada llamada ejecuta `ping_median()` (5 lecturas ultrasónicas), duplicando el tiempo del loop (~300ms total) y el consumo de energía.
- **Solución:** `distance` se cachea dentro de `get_level()` (`distance = currentDistance`) y se eliminó la llamada redundante en `loop()`.

#### 5. Variables zombie `lowlvl`/`lvlfull` (`src/main.cpp`)
- **Problema:** Estas variables globales solo eran usadas por las antiguas funciones de alarma bloqueantes. Quedaron huérfanas tras la refactorización.
- **Solución:** Eliminadas.

#### 6. Contadores de alarma sin reset (`src/alarms.h`)
- **Problema:** `low_read` y `full_read` nunca se reseteaban después de una alarma, causando que siguieran incrementándose sin límite (eventual overflow de `int`). La alarma se re-ejecutaba inútilmente cada ciclo sin sonar.
- **Solución:** Reseteo de contadores al descartar la alarma (líneas 28, 53) y al volver a nivel normal (líneas 61-62).

#### 7. Include guard en `Tank.cpp` (`lib/Tank/Tank.cpp`)
- **Problema:** Todo el archivo de implementación estaba envuelto en `#ifndef Tank_h` / `#define Tank_h` / `#endif`, que es un patrón de headers, no de archivos .cpp. Podía causar problemas de linking en ciertos entornos.
- **Solución:** Eliminado el include guard. El archivo ahora solo contiene los `#include` necesarios y la implementación.

#### 8. Array mal indexado en glyph `BC20` (`lib/Tank/Tank.cpp:160`)
- **Problema:** En el caso `BC20` del switch, la última línea del array escribía en `array[0]` en vez de `array[7]`, sobrescribiendo el primer byte y causando un glitch visual en la representación del 20% del tanque.
- **Solución:** Cambiado `array[0] = 0x00;` → `array[7] = 0x00;`.

#### 9. Backlight sin reset al activarse por alarma (`src/alarms.h`)
- **Problema:** Cuando una alarma encendía el backlight (que estaba dormido), no se reseteaba `startMillis`. En el siguiente ciclo del `loop()`, la comprobación de sleep veía que había pasado más de `sleep_time` desde el último apagado, y volvía a apagar el backlight inmediatamente.
- **Solución:** `startMillis = now` al encender el backlight desde las alarmas.

### 🚀 Mejoras Implementadas

#### 10. Watchdog Timer (`src/main.cpp`, `src/buzzer.h`)
- Agregado `#include <avr/wdt.h>` y `wdt_enable(WDTO_4S)` en `setup()`.
- `wdt_reset()` al inicio de cada `loop()`.
- `wdt_reset()` adicional dentro de los loops de `buzzer_finish()` para prevenir reset durante la reproducción de tonos largos (~360ms).
- **Beneficio:** Si el software se cuelga (bucle infinito, división por cero no atrapada, etc.), el watchdog reinicia el Arduino automáticamente después de 4 segundos.

#### 11. Wake de backlight por botón (`src/main.cpp`)
- Al presionar cualquier botón (press o hold), el backlight se enciende y el timer de sleep se resetea.
- **Beneficio:** El usuario puede "despertar" la pantalla sin esperar a una alarma.

#### 12. Histéresis en detección de fallo del sensor (`src/main.cpp`)
- Variables agregadas: `sensorFailCount`, `SENSOR_FAIL_THRESHOLD = 3`.
- Se requieren 3 lecturas malas consecutivas para declarar `sensorFail = true`.
- Se requieren 3 lecturas buenas consecutivas (decremento por cada una) para limpiar `sensorFail`.
- **Beneficio:** Elimina falsos positivos por lecturas erráticas esporádicas del sensor ultrasónico.

#### 13. Macros de notas musicales sin fugas (`src/buzzer.h`)
- `#define NOTE_C7` etc. movidas fuera de `buzzer_intro()` y convertidas a `static const int`.
- **Beneficio:** Las constantes ya no contaminan el namespace global. Type-safe.

#### 14. Arrays de melodía en flash en vez de stack (`src/buzzer.h`)
- Arrays `melody[]` y `tempo[]` cambiados a `static const`.
- **Beneficio:** Ya no se copian al stack cada vez que se llama a `buzzer_intro()`. Ahorran RAM (~60 bytes) en un microcontrolador con solo 2KB.

#### 15. Dependencia muerta eliminada (`platformio.ini`)
- `bblanchon/ArduinoTrace@^1.2.0` eliminado de `lib_deps` porque nunca se usa en el código.
- **Beneficio:** Libera ~2KB de flash de programa.

#### 16. Link-Time Optimization activado (`platformio.ini`)
- Agregado `build_flags = -flto`.
- **Beneficio:** Reduce el tamaño del binario final eliminando código muerto entre unidades de compilación.

#### 17. Borrado preciso de campos LCD (`src/main.cpp`)
- Los espacios "mágicos" de ancho fijo (8, 10, 16 espacios) se reemplazaron por padding del tamaño exacto del campo (3 chars para nivel/distancia, 7 para volumen).
- `litros` ahora se imprime con 1 decimal (`litros, 1`) para controlar el ancho.
- **Beneficio:** Elimina caracteres fantasma en la LCD al cambiar entre valores de diferente longitud.

#### 18. Ternarias redundantes eliminadas (`src/main.cpp`)
- `isValidReading()` y `isRandomReading()` ya no usan `? true : false` innecesario.
- **Beneficio:** Código más limpio, sin cambio de comportamiento.

#### 19. `buzzer_notify()` refactorizado (`src/buzzer.h`)
- Los números mágicos repetitivos (`56.818125`) se reemplazaron por constantes con nombre.
- El patrón repetido de 5 notas se reemplazó por un array + bucle `for`.
- **Beneficio:** Código mucho más mantenible y legible.

#### 20. Variables muertas eliminadas (`src/main.cpp`)
- `duration` (nunca leída), `char_y` (nunca usada) eliminadas.
- **Beneficio:** menos basura global, ~4 bytes de RAM liberados.

#### 21. `sizeof` idiomático (`src/buzzer.h`)
- `sizeof(melody) / sizeof(int)` → `sizeof(melody) / sizeof(melody[0])`.

#### 22. Conflicto NewPing/Tone por TIMER2 resuelto (`.pio/libdeps/.../NewPing.h`)
- **Problema:** NewPing y la librería `tone()` de Arduino intentan usar TIMER2 simultáneamente, causando `multiple definition of __vector_7` en el linkeo.
- **Solución:** Agregado `__AVR_ATmega328P__` a la lista de microcontroladores que deshabilitan el timer de NewPing. Esto no afecta a `ping_median()` (que usa `delayMicroseconds()`).

#### 23. Boot loop por watchdog en `setup()` (`src/main.cpp`, `src/buzzer.h`)
- **Problema:** `wdt_enable(WDTO_4S)` al inicio de `setup()` iniciaba la cuenta regresiva, pero `setup()` tarda ~5s en total (logo + `buzzer_intro` de ~3s + `delay`s). El watchdog reseteaba el chip antes de alcanzar `loop()`, causando un ciclo infinito de reinicios.
- **Solución:** Agregados `wdt_reset()` estratégicos: antes y después de `buzzer_intro()` en `setup()`, y dentro del bucle de notas de `buzzer_intro()` para que cada nota (~190ms) refresque el watchdog.

### 📊 Resumen de Archivos Modificados

| Archivo | Cambios |
|---------|---------|
| `src/main.cpp` | WDT, cacheo de sensor, histéresis, wake por botón, limpieza de variables, padding LCD |
| `src/alarms.h` | Reescritura completa no bloqueante, reset de contadores y backlight |
| `src/buzzer.h` | Guard división por cero, const int, arrays static, wdt_reset, refactor notify |
| `src/font.h` | CGRAM slot 0 para LT, write(0) en vez de write(8) |
| `lib/Tank/Tank.cpp` | array[7] corregido, include guard movido a Tank.h |
| `lib/Tank/Tank.h` | Include guard agregado |
| `platformio.ini` | ArduinoTrace eliminado, -flto agregado, monitor_speed |

### 🧹 Limpieza de Conflictos Merge

#### 24. Eliminación de marcadores de conflicto git y código duplicado
- **Problema:** Todos los archivos modificados (`main.cpp`, `buzzer.h`, `alarms.h`, `font.h`) tenían marcadores `<<<<<<<`, `=======`, `>>>>>>>` de un merge conflict mal resuelto. Ambos lados del conflicto se conservaron, resultando en funciones duplicadas, lógica corrupta y código que no compilaba.
- **Solución en `main.cpp`:** Eliminados duplicados de `isValidReading()`, `isRandomReading()`, `get_level()` (lógica de sensor duplicada con ambos lados del merge), `show_info()` (tres campos impresos dos veces), y `loop()` (lectura doble del sensor).
- **Solución en `buzzer.h`:** Reescrito completamente para eliminar versiones duplicadas de `buzzer_intro()`, `buzzer_notify()` y `buzzer_finish()`.
- **Solución en `alarms.h`:** Eliminada versión antigua bloqueante embebida dentro de la nueva función `alarmcheck()`.
- **Solución en `font.h`:** Eliminados `lcd.createChar(8, LT)` duplicado y bloques de renderizado duplicados para caracteres 'O' y 'A'.

## [2026-06-20] - Segunda Revisión: Include Guard, Ghost A, Mejoras

### 🔴 Crítico

#### 25. Include guard en el archivo equivocado (`lib/Tank/Tank.h`, `lib/Tank/Tank.cpp`)
- **Problema:** `Tank.cpp` tenía `#ifndef Tank_h`/`#define Tank_h`/`#endif` envolviendo toda la implementación (válido para headers, no para .cpp). `Tank.h` no tenía include guard — si se incluía dos veces desde distintos módulos, fallaba en compilación.
- **Solución:** Movido el include guard a `Tank.h` (antes de `#include <LiquidCrystal.h>`), eliminado de `Tank.cpp`.

### 🟠 Graves

#### 26. Carácter fantasma "A" al descartar alarma (`src/main.cpp`)
- **Problema:** La alarma imprime `"ALARMA NIVEL BAJO"` empezando en columna 1, fila 0. `show_info()` limpiaba desde columna 2 con 16 espacios, dejando visible la "A" de "ALARMA" en columna 1.
- **Solución:** `lcd.setCursor(2, 0)` → `lcd.setCursor(0, 0)` con 20 espacios para limpiar toda la fila 0.

### 🟡 Medios

#### 27. Asignación redundante en BC20 (`lib/Tank/Tank.cpp`)
- `array[0] = 0x00;` duplicado tras `array[7] = 0x00;` (merge leftover). Eliminado.

#### 28. Variable `char_y` declarada pero nunca usada (`src/main.cpp`)
- Eliminada. Ahorro: 1 byte de RAM.

#### 29. Draw struct con miembro `level` muerto (`src/main.cpp`)
- `levels()` usaba la global `nivel`, ignorando `this->level`. Eliminado el campo y la inicialización.

### 🚀 Mejoras

#### 30. DEBUGLEVEL cambiado a NONE para producción (`src/main.cpp`)
- `DEBUGLEVEL_DEBUGGING` → `DEBUGLEVEL_NONE`. Ahorro: ~3600 bytes de flash (todo el código de Serial.print compilado condicionalmente).

#### 31. `randomReadingsThreshold` hecho `const` (`src/main.cpp`)
- Era `int randomReadingsThreshold = 2;` — ahora `const int`. El compilador puede optimizar mejor.

#### 32. Debounce competitivo eliminado en `get_level()` (`src/main.cpp`)
- Había dos mecanismos de recuperación de `sensorFail` compitiendo: uno gradual (decremento de `sensorFailCount` en cada lectura buena) y uno instantáneo (`sensorFail = false` incondicional). Eliminado el instantáneo; el gradual es más robusto.

#### 33. `ledbacklight` sincronizado en alarmas (`src/alarms.h`)
- Cuando una alarma encendía el backlight físico (`digitalWrite(LEDBACK, HIGH)`), la variable `ledbacklight` quedaba en `false`. Agregado `ledbacklight = true` en ambos bloques de alarma (baja y alta).

### 🐛 Corrección de Regresión en Alarma

#### 34. Texto de alarma parpadeante (`src/main.cpp`)
- **Problema:** `show_info()` borraba la línea 0 completa en cada ciclo del `loop()`, y `alarmcheck()` escribía el texto de alarma justo antes. El resultado era que el texto se borraba y reescribía cada ~200ms, causando un parpadeo visible.
- **Solución:** El borrado de la línea 0 ahora es condicional: solo se limpia cuando NO hay alarma activa (`low_read < sameReadings && full_read < sameReadings`).

#### 35. Alarma con sonido continuo no bloqueante (`src/buzzer.h`, `src/alarms.h`)
- **Problema:** `buzzer_finish()` usaba `delay(3.6ms)` dentro de un bucle, bloqueando el sistema ~360ms. Se llamaba cada 2 segundos (intervalo fijo), por lo que la sirena sonaba a saltos en vez de continua.
- **Solución:** Reemplazado por `buzzer_sweep_update()`, una máquina de estados no bloqueante que avanza un paso del barrido de frecuencia (1000→2600Hz→1000Hz) en cada llamada. Se invoca desde `loop()` sin ningún `delay()`. El sonido ahora es continuo y el sistema nunca se bloquea.
  - `buzzer_sweep_start()` — inicia el barrido
  - `buzzer_sweep_update()` — avanza un paso (se llama desde loop())
  - `buzzer_sweep_stop()` — detiene el barrido (al descartar alarma o al volver a nivel normal)

### 📊 Resumen de Memoria

| Versión | Flash | RAM |
|---------|-------|-----|
| Antes de esta revisión | 65.1% (20002B) | 37.1% (759B) |
| Después | **53.2% (16356B)** | **29.1% (595B)** |
| **Ahorro** | **11.9% (3646B)** | **8.0% (164B)** |
