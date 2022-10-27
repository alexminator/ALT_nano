
void kalmanFilter(){
  // kalman process
  Pc = P + Q;       //Predict covariance
  Xp = Xe;
  
  G = Pc/(Pc + R);    // kalman gain
  
                    //
  Zp = Xp;
  Xe = G*(get_dist()-Zp)+Xp;   // the kalman State estimate of the sensor voltage
  P = (1-G)*Pc;             //update covarience  

  
  Serial.print("Filtro Kalman: ");
  Serial.println(Xe);         //printing new state
  delay(20);
}