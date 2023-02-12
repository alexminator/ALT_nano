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

#include <LiquidCrystal.h>

const uint8_t WLe = 0;
const uint8_t WRe = 1;
const uint8_t WLBe = 2;
const uint8_t WRBe = 3;
const uint8_t Be = 4;
const uint8_t BL10 = 5;
const uint8_t BL20 = 6;
const uint8_t BL30 = 7;
const uint8_t BR10 = 8;
const uint8_t BR20 = 9;
const uint8_t BR30 = 10;
const uint8_t BC10 = 11;
const uint8_t BC20 = 12;
const uint8_t BC30 = 13;
const uint8_t WL48 = 14;
const uint8_t WL59 = 15;
const uint8_t WL61 = 16;
const uint8_t WL70 = 17;
const uint8_t WR48 = 18;
const uint8_t WR59 = 19;
const uint8_t WR61 = 20;
const uint8_t WR70 = 21;
const uint8_t C48 = 22;
const uint8_t C59 = 23;
const uint8_t C61 = 24;

class Tank
{
	public:
		Tank(LiquidCrystal *lcd);
		void registerTank(uint8_t num, uint8_t glyphId);
		void drawTank(uint8_t glyphId, int8_t col, int8_t row);
		void drawTank(uint8_t glyphId);

	private:
		LiquidCrystal *lcd;
		uint8_t registrationMap[8];
		void getTank(uint8_t glyphId, unsigned char* array);
};