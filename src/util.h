//#############OBTENCION DEL NIVEL EN PORCIENTO###########################

void get_volume(float distanciaPromedio)
{

  float columnaLiquida = DIST_TOPE - distanciaPromedio;

  float VolumenDinamicoTabique = (tabiqueA * tabiqueL * columnaLiquida); // calculo del volumen del tabique hasta la altura del agua

  debuglnD("Volumen del tabique a una altura de " + String(columnaLiquida) + " cm es de " + String(VolumenDinamicoTabique) + " cm^3.");

  if (columnaLiquida <= 0)
  {
    lcd.setCursor(7, 3);
    lcd.print("        ");
    lcd.setCursor(7, 3);
    lcd.print(0);
  }
  else
  {
    float volumenRealTanque = (ancho * largo * columnaLiquida) - VolumenDinamicoTabique;

    debuglnD("Volumen de agua: " + String(volumenRealTanque) + " cm^3.");
    float litros = volumenRealTanque / 1000.0;

    lcd.setCursor(7, 3);
    lcd.print("        ");
    lcd.setCursor(7, 3);
    lcd.print(litros);
  }
}

void get_level()
{
  distance = get_dist();
  debuglnD("Distancia: " + String(distance));
  debuglnD("________________________________");

  if (distance > 2 && abs(distance - Xe) < 2 && distance < DIST_TOPE)
  { // Descarta errores del sensor, desecha las lecturas malas. Y resta la lectural real con el filtro kalman

    distance = round(Xe); // valor final el del filtro kallman estable
    sensorFail = false;
    debuglnD("________________________________");
    debuglnD("Distancia promedio del filtro: " + String(distance));

    nivel = DIST_TOPE - distance;
    nivel = map(nivel, 0, DIST_TOPE - 25, 0, 100); // 79 cm seria el nivel maximo en % por seguridad del sensor(25cm)

    debuglnD("Nivel en porciento: " + String(nivel));
    debuglnD("________________________________");

    if (nivel < 0)
      nivel = 0;

    // Fixed Text
    lcd.clear();
    lcd.setCursor(0, 1);
    lcd.print("Nivel:");
    lcd.setCursor(10, 1);
    lcd.print("%");
    lcd.setCursor(0, 2);
    lcd.print("Dist.:");
    lcd.setCursor(10, 2);
    lcd.print("cm");
    lcd.setCursor(0, 3);
    lcd.print("Vol. :");
    lcd.setCursor(15, 3);
    lcd.print("L");
    get_volume(distance);
    lcd.setCursor(7, 1);
    lcd.print("   ");
    lcd.setCursor(7, 1);
    lcd.print(nivel);
    lcd.setCursor(7, 2);
    lcd.print("   ");
    lcd.setCursor(7, 2);
    lcd.print(distance);
  }
  else
  {
    // printSleepAtStart = true;
    lcd.clear();
    createChars();
    printBigCharacters(data2, 3, 1);
    buzzer_warning();
    sensorFail = true;
  }
}