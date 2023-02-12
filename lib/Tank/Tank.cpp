// Copyright (C) 2023 Alexminator
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.

#ifndef Tank_h
#define Tank_h

#include "Arduino.h"
#include "Tank.h"

Tank::Tank(LiquidCrystal *lcd)
{
  this->lcd = lcd;
}

void Tank::getTank(uint8_t glyphId, unsigned char *array)
{
  switch (glyphId)
  {
  case WLe:
    array[0] = 0x10;
    array[1] = 0x10;
    array[2] = 0x10;
    array[3] = 0x10;
    array[4] = 0x10;
    array[5] = 0x10;
    array[6] = 0x10;
    array[7] = 0x10;
    break;

  case WRe:
    array[0] = 0x01;
    array[1] = 0x01;
    array[2] = 0x01;
    array[3] = 0x01;
    array[4] = 0x01;
    array[5] = 0x01;
    array[6] = 0x01;
    array[7] = 0x01;
    break;

  case WLBe:
    array[0] = 0x10;
    array[1] = 0x10;
    array[2] = 0x10;
    array[3] = 0x10;
    array[4] = 0x10;
    array[5] = 0x10;
    array[6] = 0x08;
    array[7] = 0x07;
    break;

  case WRBe:
    array[0] = 0x01;
    array[1] = 0x01;
    array[2] = 0x01;
    array[3] = 0x01;
    array[4] = 0x01;
    array[5] = 0x01;
    array[6] = 0x02;
    array[7] = 0x1C;
    break;

  case Be:
    array[0] = 0x00;
    array[1] = 0x00;
    array[2] = 0x00;
    array[3] = 0x00;
    array[4] = 0x00;
    array[5] = 0x00;
    array[6] = 0x00;
    array[7] = 0x1F;
    break;

  case BL10:
    array[0] = 0x10;
    array[1] = 0x10;
    array[2] = 0x10;
    array[3] = 0x10;
    array[4] = 0x17;
    array[5] = 0x17;
    array[6] = 0x0F;
    array[7] = 0x07;
    break;

  case BL20:
    array[0] = 0x10;
    array[1] = 0x10;
    array[2] = 0x17;
    array[3] = 0x17;
    array[4] = 0x17;
    array[5] = 0x17;
    array[6] = 0x0F;
    array[7] = 0x07;
    break;

  case BL30:
    array[0] = 0x17;
    array[1] = 0x17;
    array[2] = 0x17;
    array[3] = 0x17;
    array[4] = 0x17;
    array[5] = 0x17;
    array[6] = 0x0F;
    array[7] = 0x07;
    break;

  case BR10:
    array[0] = 0x01;
    array[1] = 0x01;
    array[2] = 0x01;
    array[3] = 0x01;
    array[4] = 0x1D;
    array[5] = 0x1D;
    array[6] = 0x1E;
    array[7] = 0x1C;
    break;

  case BR20:
    array[0] = 0x01;
    array[1] = 0x01;
    array[2] = 0x1D;
    array[3] = 0x1D;
    array[4] = 0x1D;
    array[5] = 0x1D;
    array[6] = 0x1E;
    array[7] = 0x1C;
    break;

  case BR30:
    array[0] = 0x1D;
    array[1] = 0x1D;
    array[2] = 0x1D;
    array[3] = 0x1D;
    array[4] = 0x1D;
    array[5] = 0x1D;
    array[6] = 0x1E;
    array[7] = 0x1C;
    break;

  case BC10:
    array[0] = 0x00;
    array[1] = 0x00;
    array[2] = 0x00;
    array[3] = 0x00;
    array[4] = 0x1F;
    array[5] = 0x1F;
    array[6] = 0x1F;
    array[7] = 0x1F;
    break;

  case BC20:
    array[0] = 0x00;
    array[1] = 0x00;
    array[2] = 0x1F;
    array[3] = 0x1F;
    array[4] = 0x1F;
    array[5] = 0x1F;
    array[6] = 0x1F;
    array[7] = 0x1F;
    break;

  case BC30:
    array[0] = 0x1F;
    array[1] = 0x1F;
    array[2] = 0x1F;
    array[3] = 0x1F;
    array[4] = 0x1F;
    array[5] = 0x1F;
    array[6] = 0x1F;
    array[7] = 0x1F;
    break;

  case WL48:
    array[0] = 0x10;
    array[1] = 0x10;
    array[2] = 0x10;
    array[3] = 0x10;
    array[4] = 0x10;
    array[5] = 0x10;
    array[6] = 0x17;
    array[7] = 0x17;
    break;

  case WL59:
    array[0] = 0x10;
    array[1] = 0x10;
    array[2] = 0x10;
    array[3] = 0x10;
    array[4] = 0x17;
    array[5] = 0x17;
    array[6] = 0x17;
    array[7] = 0x17;
    break;

  case WL61:
    array[0] = 0x10;
    array[1] = 0x10;
    array[2] = 0x17;
    array[3] = 0x17;
    array[4] = 0x17;
    array[5] = 0x17;
    array[6] = 0x17;
    array[7] = 0x17;
    break;

  case WL70:
    array[0] = 0x17;
    array[1] = 0x17;
    array[2] = 0x17;
    array[3] = 0x17;
    array[4] = 0x17;
    array[5] = 0x17;
    array[6] = 0x17;
    array[7] = 0x17;
    break;

  case WR48:
    array[0] = 0x01;
    array[1] = 0x01;
    array[2] = 0x01;
    array[3] = 0x01;
    array[4] = 0x01;
    array[5] = 0x01;
    array[6] = 0x1D;
    array[7] = 0x1D;
    break;

  case WR59:
    array[0] = 0x01;
    array[1] = 0x01;
    array[2] = 0x01;
    array[3] = 0x01;
    array[4] = 0x1D;
    array[5] = 0x1D;
    array[6] = 0x1D;
    array[7] = 0x1D;
    break;

  case WR61:
    array[0] = 0x01;
    array[1] = 0x01;
    array[2] = 0x1D;
    array[3] = 0x1D;
    array[4] = 0x1D;
    array[5] = 0x1D;
    array[6] = 0x1D;
    array[7] = 0x1D;
    break;

  case WR70:
    array[0] = 0x1D;
    array[1] = 0x1D;
    array[2] = 0x1D;
    array[3] = 0x1D;
    array[4] = 0x1D;
    array[5] = 0x1D;
    array[6] = 0x1D;
    array[7] = 0x1D;
    break;

  case C48:
    array[0] = 0x00;
    array[1] = 0x00;
    array[2] = 0x00;
    array[3] = 0x00;
    array[4] = 0x00;
    array[5] = 0x00;
    array[6] = 0x1F;
    array[7] = 0x1F;
    break;

  case C59:
    array[0] = 0x00;
    array[1] = 0x00;
    array[2] = 0x00;
    array[3] = 0x00;
    array[4] = 0x1F;
    array[5] = 0x1F;
    array[6] = 0x1F;
    array[7] = 0x1F;
    break;

  case C61:
    array[0] = 0x00;
    array[1] = 0x00;
    array[2] = 0x1F;
    array[3] = 0x1F;
    array[4] = 0x1F;
    array[5] = 0x1F;
    array[6] = 0x1F;
    array[7] = 0x1F;
    break;
  }
}

void Tank::registerTank(uint8_t num, uint8_t glyphId)
{
  unsigned char glyph[8];
  this->getTank(glyphId, glyph);
  this->lcd->createChar(num, glyph);
  this->registrationMap[num] = glyphId;
}

void Tank::drawTank(uint8_t glyphId, int8_t col, int8_t row)
{
  int8_t characterIndex = -1;
  for (uint8_t i = 0; i < 8; i++)
  {
    if (registrationMap[i] == glyphId)
    {
      characterIndex = i;
      break;
    }
  }

  if (characterIndex > -1)
  {
    if (col > -1 && row > -1)
    {
      this->lcd->setCursor(col, row);
    }

    this->lcd->write(characterIndex);
  }
}

void Tank::drawTank(uint8_t glyphId)
{
  this->drawTank(glyphId, -1, -1);
}

#endif