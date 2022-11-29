//---------------------- Large LCD Characters ------------------------//  From Michael Pilcher with a few additions by Ben Lipsey
// Nota Solo utilice las letras necesarias
byte LT[8] =
    {
        0x07,
        0x0F,
        0x1F,
        0x1F,
        0x1F,
        0x1F,
        0x1F,
        0x1F};
byte UB[8] =
    {
        0x1F,
        0x1F,
        0x1F,
        0x00,
        0x00,
        0x00,
        0x00,
        0x00};
byte RT[8] =
    {
        0x1C,
        0x1E,
        0x1F,
        0x1F,
        0x1F,
        0x1F,
        0x1F,
        0x1F};
byte LL[8] =
    {
        0x1F,
        0x1F,
        0x1F,
        0x1F,
        0x1F,
        0x1F,
        0x0F,
        0x07};
byte LB[8] =
    {
        0x00,
        0x00,
        0x00,
        0x00,
        0x00,
        0x1F,
        0x1F,
        0x1F};
byte LR[8] =
    {
        0x1F,
        0x1F,
        0x1F,
        0x1F,
        0x1F,
        0x1F,
        0x1E,
        0x1C};
byte UMB[8] =
    {
        0x1F,
        0x1F,
        0x1F,
        0x00,
        0x00,
        0x00,
        0x1F,
        0x1F};
byte LMB[8] =
    {
        0x1F,
        0x00,
        0x00,
        0x00,
        0x00,
        0x1F,
        0x1F,
        0x1F};

void createChars()
{
  lcd.createChar(1, UB);
  lcd.createChar(2, RT);
  lcd.createChar(3, LL);
  lcd.createChar(4, LB);
  lcd.createChar(5, LR);
  lcd.createChar(6, UMB);
  lcd.createChar(7, LMB);
  lcd.createChar(8, LT);
}

void printBigCharacters(char character[], byte x, byte y)
{
  bool foundChar;
  byte charWidth = 0;

  for (byte i = 0; i < strlen(character); i++)
  {

    charWidth = 0;
    foundChar = false;

    if (character[i] == 'A' || character[i] == 'a')
    {
      foundChar = true;
      charWidth = 3;
      lcd.setCursor(x, y);
      lcd.write(8);
      lcd.write(6);
      lcd.write(2);
      lcd.setCursor(x, y + 1);
      lcd.write(255);
      lcd.write(254);
      lcd.write(255);
    }

    if (character[i] == 'E' || character[i] == 'e')
    {
      foundChar = true;
      charWidth = 3;
      lcd.setCursor(x, y);
      lcd.write(255);
      lcd.write(6);
      lcd.write(6);
      lcd.setCursor(x, y + 1);
      lcd.write(255);
      lcd.write(7);
      lcd.write(7);
    }

    if (character[i] == 'L' || character[i] == 'l')
    {
      foundChar = true;
      charWidth = 3;
      lcd.setCursor(x, y);
      lcd.write(255);
      lcd.write(254);
      lcd.write(254);
      lcd.setCursor(x, y + 1);
      lcd.write(255);
      lcd.write(4);
      lcd.write(4);
    }

    if (character[i] == '0' || character[i] == 'O' || character[i] == 'o')
    {
      foundChar = true;
      charWidth = 3;
      lcd.setCursor(x, y);
      lcd.write(8);
      lcd.write(1);
      lcd.write(2);
      lcd.setCursor(x, y + 1);
      lcd.write(3);
      lcd.write(4);
      lcd.write(5);
    }

    if (character[i] == 'R' || character[i] == 'r')
    {
      foundChar = true;
      charWidth = 3;
      lcd.setCursor(x, y);
      lcd.write(255);
      lcd.write(6);
      lcd.write(2);
      lcd.setCursor(x, y + 1);
      lcd.write(255);
      lcd.write(254);
      lcd.write(2);
    }

    if (character[i] == 'T' || character[i] == 't')
    {
      foundChar = true;
      charWidth = 3;
      lcd.setCursor(x, y);
      lcd.write(1);
      lcd.write(255);
      lcd.write(1);
      lcd.setCursor(x, y + 1);
      lcd.write(254);
      lcd.write(255);
      lcd.write(254);
    }

    if (character[i] == 'F' || character[i] == 'f')
    {
      foundChar = true;
      charWidth = 3;
      lcd.setCursor(x, y);
      lcd.write(255);
      lcd.write(6);
      lcd.write(6);
      lcd.setCursor(x, y + 1);
      lcd.write(255);
      lcd.write(254);
      lcd.write(254);
    }

    if (character[i] == 'U' || character[i] == 'u')
    {
      foundChar = true;
      charWidth = 3;
      lcd.setCursor(x, y);
      lcd.write(255);
      lcd.write(254);
      lcd.write(255);
      lcd.setCursor(x, y + 1);
      lcd.write(3);
      lcd.write(4);
      lcd.write(5);
    }

    if (character[i] == 'Y' || character[i] == 'y')
    {
      foundChar = true;
      charWidth = 3;
      lcd.setCursor(x, y);
      lcd.write(3);
      lcd.write(4);
      lcd.write(5);
      lcd.setCursor(x, y + 1);
      lcd.write(254);
      lcd.write(255);
      lcd.write(254);
    }

    if (character[i] == 'P' || character[i] == 'p')
    {
      foundChar = true;
      charWidth = 3;
      lcd.setCursor(x, y);
      lcd.write(255);
      lcd.write(6);
      lcd.write(2);
      lcd.setCursor(x, y + 1);
      lcd.write(255);
      lcd.write(254);
      lcd.write(254);
    }

    if (character[i] == 'M' || character[i] == 'm')
    {
      foundChar = true;
      charWidth = 4;
      lcd.setCursor(x, y);
      lcd.write(8);
      lcd.write(3);
      lcd.write(5);
      lcd.write(2);
      lcd.setCursor(x, y + 1);
      lcd.write(255);
      lcd.write(254);
      lcd.write(254);
      lcd.write(255);
    }

    if (character[i] == 'W' || character[i] == 'w')
    {
      foundChar = true;
      charWidth = 4;
      lcd.setCursor(x, y);
      lcd.write(255);
      lcd.write(254);
      lcd.write(254);
      lcd.write(255);
      lcd.setCursor(x, y + 1);
      lcd.write(3);
      lcd.write(8);
      lcd.write(2);
      lcd.write(5);
    }

    if (foundChar)
    {
      char_x = char_x + charWidth;
      x = x + charWidth;
    }
    else
    {
      lcd.setCursor(x, y);
      lcd.write(254);
      lcd.setCursor(x, y + 1);
      lcd.print(character[i]);
      x = x + 1;
      char_x = char_x + 1;
    }
  }
}