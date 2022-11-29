void alarmfull()
{
   if (aviso)
   {
   lcd.clear();
   createChars();
   printBigCharacters(data3, 4, 1);
   }
   while (!lvlfull)
   {
      buzzer_finish();
   }
}

void alarmlow()
{
   if (aviso)
   {
      lcd.clear();
      createChars();
      printBigCharacters(data4, 5, 1);
   }
   while (!lvlfull)
   {
      buzzer_finish();
   }
}

void mute()
{ // ISR function

   if (millis() - startTime > timeThreshold)
   {
      lvlfull = true;
      aviso = false;
      startTime = millis();
   }
}