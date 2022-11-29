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
  
  if (distance > 2 && abs(distance - Xe) < 2 && distance < DIST_TOPE)
  { // Descarta errores del sensor, desecha las lecturas malas. Y resta la lectural real con el filtro kalman

    distance = round(Xe); // valor final el del filtro kallman estable
    sensorFail = false;
    
    debuglnD("Distancia promedio del filtro: " + String(distance));
    
    nivel = DIST_TOPE - distance;
    nivel = map(nivel, 0, DIST_TOPE - 25, 0, 100); // 79 cm seria el nivel maximo en % por seguridad del sensor(25cm)

    debuglnD("Nivel en porciento: " + String(nivel));
   
    if (nivel < 0)
      nivel = 0;

    get_volume(distance);
    lcd.setCursor(6, 1);
    lcd.print("    ");
    lcd.setCursor(7, 1);
    lcd.print(nivel);
    lcd.setCursor(6, 2);
    lcd.print("    ");
    lcd.setCursor(7, 2);
    lcd.print(distance);
  }
  else
  {
    lcd.setCursor(2,0);
    lcd.print("ERROR DE LECTURA");
    buzzer_notify();
    sensorFail = true;
  }
}