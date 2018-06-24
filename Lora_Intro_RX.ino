/*This Code is for the RECEIVER*/

#define LED 5

String received;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);   //default baudrate of module is 115200
  delay(2000);             //wait for Lora device to be ready

  Serial.print("AT\r\n");
  delay(1000);
  
  Serial.print("AT+PARAMETER=10,7,1,7\r\n");    //For Less than 3Kms
  //Serial.print("AT+PARAMETER=10,7,1,7\r\n");    //For More than 3Kms
  delay(100);   //wait for module to respond
  
  Serial.print("AT+BAND=868500000\r\n");    //Bandwidth set to 868.5MHz
  delay(100);   //wait for module to respond
  
  Serial.print("AT+ADDRESS=116\r\n");   //needs to be unique
  delay(100);   //wait for module to respond
  
  Serial.print("AT+NETWORKID=6\r\n");   //needs to be same for receiver and transmitter
  delay(100);   //wait for module to respond

  Serial.print("AT+PARAMETER?\r\n");    //For Less than 3Kms
  //Serial.print("AT+PARAMETER=10,7,1,7\r\n");    //For More than 3Kms
  delay(100);   //wait for module to respond
  
  Serial.print("AT+BAND?\r\n");    //Bandwidth set to 868.5MHz
  delay(100);   //wait for module to respond
  
  Serial.print("AT+NETWORKID?\r\n");   //needs to be same for receiver and transmitter
  delay(100);   //wait for module to respond
  
  Serial.print("AT+ADDRESS?\r\n");   //needs to be unique
  delay(100);   //wait for module to respond

  pinMode(LED,OUTPUT);
  digitalWrite(LED,LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()){
    received = Serial.readString();
    if(received.startsWith("+RCV")){
      if(received[11]=='1'){  //in this case our single received byte would always be at the 11th position
        digitalWrite(LED,HIGH);
      }
      else{
        digitalWrite(LED,LOW);
      }
    }
  }
}
