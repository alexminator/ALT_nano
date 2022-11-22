//#############OBTENCION DEL NIVEL EN PORCIENTO###########################
int ultrasonic_fail = 0;//contador para determinar fallo del sensor ultrasonico

    
void get_volume(float distanciaPromedio){

  float columnaLiquida = DIST_TOPE - distanciaPromedio;
  
  float VolumenDinamicoTabique = (tabiqueA * tabiqueL * columnaLiquida); //calculo del volumen del tabique hasta la altura del agua

  debuglnD("Volumen del tabique a una altura de, " + String(columnaLiquida) + " cm es de " + String(VolumenDinamicoTabique) + " cm^3.");

  if(columnaLiquida <= 0)
  {
    lcd.setCursor(7, 3);
    lcd.print("        ");
    lcd.setCursor(7, 3);
    lcd.print(0);
  }
  else{
    float volumenRealTanque = (ancho * largo * columnaLiquida) - VolumenDinamicoTabique;

    debuglnD("Volumen(cm^3): " + String(volumenRealTanque));
    float litros = volumenRealTanque / 1000.0;
  
    lcd.setCursor(7, 3);
    lcd.print("        ");
    lcd.setCursor(7, 3);
    lcd.print(litros);
  }
}

void get_level() {
  distance = get_dist();
  debuglnD("Distancia: " + String(distance));
  if (distance < 2) ultrasonic_fail++; //se incrementa el contador

  debuglnD("Fail: " + String(ultrasonic_fail));

  if (ultrasonic_fail == 5) { //si llega a 5 veces concecutivas con lecturas a cero es que algo anda mal con el sensor
    lcd.clear();
    createChars();
    printBigCharacters(data2, 3, 1);
    sensorFail = true;
    }

  if (distance > 0 && abs(distance - Xe) < 2 ) {//descarta errores del sensor, desecha las lecturas 0
                                                //Y resta la lectural real con el filtro kalman
    distance = round(Xe);
    sensorFail = false;
    ultrasonic_fail = 0; //se resetea el contador

    debuglnD("Distancia Filtrada: " + String(distance));
    
    
    nivel = DIST_TOPE - distance;
    nivel = map(nivel, 0, DIST_TOPE - 25, 0, 100);//79 cm seria el nivel maximo en % por seguridad del sensor(25cm)
    
    debuglnD("Nivel: " + String(nivel));
    
    if(nivel < 0)
      nivel = 0;

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
    if(distance > DIST_TOPE)
      lcd.print(DIST_TOPE);
    else
      lcd.print(distance);
    lcd.display();
  }
  else
  {
    if(distance > 0){
      ultrasonic_fail = 0; //se resetea el contador
      sensorFail = false;
    }
  }
}