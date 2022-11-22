
void kalmanFilter(){
  // kalman process
  Pc = P + Q;       //Predict covariance
  Xp = Xe;
  
  G = Pc/(Pc + R);    // kalman gain
  
                    //
  Zp = Xp;
  Xe = G*(get_dist()-Zp)+Xp;   // the kalman State estimate of the sensor voltage
  P = (1-G)*Pc;             //update covarience  
  
  debuglnD("Filtro Kalman: " + String(Xe));
  //Serial.println(Xe);         //printing new state
  delay(20);
}