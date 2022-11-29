void alarmfull()
{
   /*if (aviso)
   {
      lcd.clear();
      createChars();
      printBigCharacters(data3, 4, 1);
   }
   */
   while (lvlfull)
   {
      lcd.clear();
      createChars();
      printBigCharacters(data3, 4, 1);
      buzzer_finish();
   }
}

void alarmlow()
{
   /*if (aviso)
   {
      lcd.clear();
      createChars();
      printBigCharacters(data4, 5, 1);

   }
   */
   while (lowlvl)
   {
      lcd.clear();
      createChars();
      printBigCharacters(data4, 5, 1);
      buzzer_finish();
   }
}

void mute()
{ // ISR function

   if (millis() - startTime > timeThreshold)
   {
      lvlfull = false;
      lowlvl = false;
      aviso = false;
      startTime = millis();
   }
}