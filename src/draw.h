void clean(){
      lcd.setCursor(16, 1);
      lcd.print("    ");
      lcd.setCursor(16, 2);
      lcd.print("    ");
      lcd.setCursor(16, 3);
      lcd.print("    ");
}

void empty(){
  // vacio
      draw->registerTank(0, WLe);
      draw->registerTank(1, WRe);
      draw->registerTank(2, WLBe);
      draw->registerTank(3, WRBe);
      // draw->registerTank(4, Be); OBSOLETO!!!
      clean();
      // wall left
      lcd.setCursor(16, 1);
      draw->drawTank(WLe);
      lcd.setCursor(16, 2);
      draw->drawTank(WLe);
      lcd.setCursor(16, 3);
      draw->drawTank(WLBe);
      // bottom
      lcd.setCursor(17, 3);
      lcd.write("_");
      // draw->drawTank(Be);
      lcd.setCursor(18, 3);
      lcd.write("_");
      // draw->drawTank(Be);
      // wall rigth
      lcd.setCursor(19, 1);
      draw->drawTank(WRe);
      lcd.setCursor(19, 2);
      draw->drawTank(WRe);
      lcd.setCursor(19, 3);
      draw->drawTank(WRBe);
}

void ten(){
  // lleno 10%
      draw->registerTank(0, WLe);
      draw->registerTank(1, WRe);
      draw->registerTank(2, BL10);
      draw->registerTank(3, BR10);
      draw->registerTank(4, BC10);
      clean();
      // wall left
      lcd.setCursor(16, 1);
      draw->drawTank(WLe);
      lcd.setCursor(16, 2);
      draw->drawTank(WLe);
      lcd.setCursor(16, 3);
      draw->drawTank(BL10);
      // bottom
      lcd.setCursor(17, 3);
      draw->drawTank(BC10);
      lcd.setCursor(18, 3);
      draw->drawTank(BC10);
      // wall rigth
      lcd.setCursor(19, 1);
      draw->drawTank(WRe);
      lcd.setCursor(19, 2);
      draw->drawTank(WRe);
      lcd.setCursor(19, 3);
      draw->drawTank(BR10);
}

void twenty(){
  // lleno 20%
      draw->registerTank(0, WLe);
      draw->registerTank(1, WRe);
      draw->registerTank(2, BL20);
      draw->registerTank(3, BR20);
      draw->registerTank(4, BC20);
      clean();
      // wall left
      lcd.setCursor(16, 1);
      draw->drawTank(WLe);
      lcd.setCursor(16, 2);
      draw->drawTank(WLe);
      lcd.setCursor(16, 3);
      draw->drawTank(BL20);
      // bottom
      lcd.setCursor(17, 3);
      draw->drawTank(BC20);
      lcd.setCursor(18, 3);
      draw->drawTank(BC20);
      // wall rigth
      lcd.setCursor(19, 1);
      draw->drawTank(WRe);
      lcd.setCursor(19, 2);
      draw->drawTank(WRe);
      lcd.setCursor(19, 3);
      draw->drawTank(BR20);
}

void thirty(){
  // lleno 30%
      draw->registerTank(0, WLe);
      draw->registerTank(1, WRe);
      draw->registerTank(2, BL30);
      draw->registerTank(3, BR30);
      draw->registerTank(4, BC30);
      clean();
      // wall left
      lcd.setCursor(16, 1);
      draw->drawTank(WLe);
      lcd.setCursor(16, 2);
      draw->drawTank(WLe);
      lcd.setCursor(16, 3);
      draw->drawTank(BL30);
      // bottom
      lcd.setCursor(17, 3);
      draw->drawTank(BC30);
      lcd.setCursor(18, 3);
      draw->drawTank(BC30);
      // wall rigth
      lcd.setCursor(19, 1);
      draw->drawTank(WRe);
      lcd.setCursor(19, 2);
      draw->drawTank(WRe);
      lcd.setCursor(19, 3);
      draw->drawTank(BR30);
}

void forty(){
  // lleno 40%
      draw->registerTank(0, WLe);
      draw->registerTank(1, WRe);
      draw->registerTank(2, WL48);
      draw->registerTank(3, WR48);
      draw->registerTank(4, C48);
      draw->registerTank(5, BL30);
      draw->registerTank(6, BR30);
      draw->registerTank(7, BC30);
      clean();
      // wall left
      lcd.setCursor(16, 1);
      draw->drawTank(WLe);
      lcd.setCursor(16, 2);
      draw->drawTank(WL48);
      lcd.setCursor(16, 3);
      draw->drawTank(BL30);
      // bottom
      lcd.setCursor(17, 3);
      draw->drawTank(BC30);
      lcd.setCursor(18, 3);
      draw->drawTank(BC30);
      lcd.setCursor(17, 2);
      draw->drawTank(C48);
      lcd.setCursor(18, 2);
      draw->drawTank(C48);
      // wall rigth
      lcd.setCursor(19, 1);
      draw->drawTank(WRe);
      lcd.setCursor(19, 2);
      draw->drawTank(WR48);
      lcd.setCursor(19, 3);
      draw->drawTank(BR30);
}

void fifty(){
  // lleno 50%
      draw->registerTank(0, WLe);
      draw->registerTank(1, WRe);
      draw->registerTank(2, WL59);
      draw->registerTank(3, WR59);
      draw->registerTank(4, C59);
      draw->registerTank(5, BL30);
      draw->registerTank(6, BR30);
      draw->registerTank(7, BC30);
      clean();
      // wall left
      lcd.setCursor(16, 1);
      draw->drawTank(WLe);
      lcd.setCursor(16, 2);
      draw->drawTank(WL59);
      lcd.setCursor(16, 3);
      draw->drawTank(BL30);
      // bottom
      lcd.setCursor(17, 3);
      draw->drawTank(BC30);
      lcd.setCursor(18, 3);
      draw->drawTank(BC30);
      lcd.setCursor(17, 2);
      draw->drawTank(C59);
      lcd.setCursor(18, 2);
      draw->drawTank(C59);
      // wall rigth
      lcd.setCursor(19, 1);
      draw->drawTank(WRe);
      lcd.setCursor(19, 2);
      draw->drawTank(WR59);
      lcd.setCursor(19, 3);
      draw->drawTank(BR30);
}

void sixty(){
  // lleno 60%
      draw->registerTank(0, WLe);
      draw->registerTank(1, WRe);
      draw->registerTank(2, WL61);
      draw->registerTank(3, WR61);
      draw->registerTank(4, C61);
      draw->registerTank(5, BL30);
      draw->registerTank(6, BR30);
      draw->registerTank(7, BC30);
      clean();
      // wall left
      lcd.setCursor(16, 1);
      draw->drawTank(WLe);
      lcd.setCursor(16, 2);
      draw->drawTank(WL61);
      lcd.setCursor(16, 3);
      draw->drawTank(BL30);
      // bottom
      lcd.setCursor(17, 3);
      draw->drawTank(BC30);
      lcd.setCursor(18, 3);
      draw->drawTank(BC30);
      lcd.setCursor(17, 2);
      draw->drawTank(C61);
      lcd.setCursor(18, 2);
      draw->drawTank(C61);
      // wall rigth
      lcd.setCursor(19, 1);
      draw->drawTank(WRe);
      lcd.setCursor(19, 2);
      draw->drawTank(WR61);
      lcd.setCursor(19, 3);
      draw->drawTank(BR30);
}

void seventy(){
  // lleno 70%
      draw->registerTank(0, WLe);
      draw->registerTank(1, WRe);
      draw->registerTank(2, WL70);
      draw->registerTank(3, WR70);
      draw->registerTank(4, BL30);
      draw->registerTank(5, BR30);
      draw->registerTank(6, BC30);
      clean();
      // wall left
      lcd.setCursor(16, 1);
      draw->drawTank(WLe);
      lcd.setCursor(16, 2);
      draw->drawTank(WL70);
      lcd.setCursor(16, 3);
      draw->drawTank(BL30);
      // bottom
      lcd.setCursor(17, 3);
      draw->drawTank(BC30);
      lcd.setCursor(18, 3);
      draw->drawTank(BC30);
      lcd.setCursor(17, 2);
      lcd.write(0xFF);
      // draw->drawTank(BC30);
      lcd.setCursor(18, 2);
      // draw->drawTank(BC30);
      lcd.write(0xFF);
      // wall rigth
      lcd.setCursor(19, 1);
      draw->drawTank(WRe);
      lcd.setCursor(19, 2);
      draw->drawTank(WR70);
      lcd.setCursor(19, 3);
      draw->drawTank(BR30);
}

void eighty(){
  // lleno 80%
      draw->registerTank(0, WL48);
      draw->registerTank(1, WR48);
      draw->registerTank(2, WL70);
      draw->registerTank(3, WR70);
      draw->registerTank(4, C48);
      draw->registerTank(5, BL30);
      draw->registerTank(6, BR30);
      draw->registerTank(7, BC30);
      clean();
      // wall left
      lcd.setCursor(16, 1);
      draw->drawTank(WL48);
      lcd.setCursor(16, 2);
      draw->drawTank(WL70);
      lcd.setCursor(16, 3);
      draw->drawTank(BL30);
      // bottom
      lcd.setCursor(17, 3);
      draw->drawTank(BC30);
      lcd.setCursor(18, 3);
      draw->drawTank(BC30);
      lcd.setCursor(17, 1);
      draw->drawTank(C48);
      lcd.setCursor(18, 1);
      draw->drawTank(C48);
      lcd.setCursor(17, 2);
      lcd.write(0xFF);
      // draw->drawTank(BC30);
      lcd.setCursor(18, 2);
      lcd.write(0xFF);
      // draw->drawTank(BC30);
      // wall rigth
      lcd.setCursor(19, 1);
      draw->drawTank(WR48);
      lcd.setCursor(19, 2);
      draw->drawTank(WR70);
      lcd.setCursor(19, 3);
      draw->drawTank(BR30);
}

void ninety(){
  // lleno 90%
      draw->registerTank(0, WL59);
      draw->registerTank(1, WR59);
      draw->registerTank(2, WL70);
      draw->registerTank(3, WR70);
      draw->registerTank(4, C59);
      draw->registerTank(5, BL30);
      draw->registerTank(6, BR30);
      draw->registerTank(7, BC30);
      clean();
      // wall left
      lcd.setCursor(16, 1);
      draw->drawTank(WL59);
      lcd.setCursor(16, 2);
      draw->drawTank(WL70);
      lcd.setCursor(16, 3);
      draw->drawTank(BL30);
      // bottom
      lcd.setCursor(17, 1);
      draw->drawTank(C59);
      lcd.setCursor(18, 1);
      draw->drawTank(C59);
      lcd.setCursor(17, 2);
      lcd.write(0xFF);
      // draw->drawTank(BC30);
      lcd.setCursor(18, 2);
      lcd.write(0xFF);
      // draw->drawTank(BC30);
      lcd.setCursor(17, 3);
      draw->drawTank(BC30);
      lcd.setCursor(18, 3);
      draw->drawTank(BC30);
      // wall rigth
      lcd.setCursor(19, 1);
      draw->drawTank(WR59);
      lcd.setCursor(19, 2);
      draw->drawTank(WR70);
      lcd.setCursor(19, 3);
      draw->drawTank(BR30);
}

void full(){
  // lleno 100%
      draw->registerTank(0, WL61);
      draw->registerTank(1, WR61);
      draw->registerTank(2, WL70);
      draw->registerTank(3, WR70);
      draw->registerTank(4, C61);
      draw->registerTank(5, BL30);
      draw->registerTank(6, BR30);
      draw->registerTank(7, BC30);
      clean();
      // wall left
      lcd.setCursor(16, 1);
      draw->drawTank(WL61);
      lcd.setCursor(16, 2);
      draw->drawTank(WL70);
      lcd.setCursor(16, 3);
      draw->drawTank(BL30);
      // bottom
      lcd.setCursor(17, 3);
      draw->drawTank(BC30);
      lcd.setCursor(18, 3);
      draw->drawTank(BC30);
      lcd.setCursor(17, 1);
      draw->drawTank(C61);
      lcd.setCursor(18, 1);
      draw->drawTank(C61);
      lcd.setCursor(17, 2);
      lcd.write(0xFF);
      // draw->drawTank(BC30);
      lcd.setCursor(18, 2);
      lcd.write(0xFF);
      // draw->drawTank(BC30);
      // wall rigth
      lcd.setCursor(19, 1);
      draw->drawTank(WR61);
      lcd.setCursor(19, 2);
      draw->drawTank(WR70);
      lcd.setCursor(19, 3);
      draw->drawTank(BR30);
}
