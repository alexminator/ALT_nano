//#############MEDICION CON EL SENSOR ULTRASONICO#########################
const int trigPin = 2;
const int echoPin = 5;
 
long duration = 0;
int distance = 0;
//float distanciaPromedio = 0;
 
float get_dist() {
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
 
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(20);
  digitalWrite(trigPin, LOW);
 
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH, 26000);//timeout de 200000 microsegundos que es 26ms
 
  // Calculating the distance
  //distance= duration/58;
  //Serial.println("___________________________________________    " + String(nivel));
  delay (500);
  float distance = (float)(duration / 58);

  if(distance > 40)
    distance += 3.0;
  else   
    distance += 2.0;
  return distance;
  
}