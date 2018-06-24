/*This Code is for the TRANSMITTER*/

#define ON 14
#define OFF 12
#define AUTO 16

void setup() {
  // put your setup code here, to run once:
  
  Serial.begin(115200);   //default baudrate of module is 115200
  delay(100);             //wait for Lora device to be ready
  
  Serial.print("AT\r\n");
  delay(100);
  
  Serial.print("AT+PARAMETER=10,7,1,7\r\n");    //For Less than 3Kms
  //Serial.print("AT+PARAMETER=10,7,1,7\r\n");    //For More than 3Kms
  delay(100);   //wait for module to respond
  
  Serial.print("AT+BAND=868500000\r\n");    //Bandwidth set to 868.5MHz
  delay(100);   //wait for module to respond
  
  Serial.print("AT+ADDRESS=115\r\n");   //needs to be unique
  delay(100);   //wait for module to respond
  
  Serial.print("AT+NETWORKID=6\r\n");   //needs to be same for receiver and transmitter
  delay(100);   //wait for module to respond

  Serial.print("AT+PARAMETER?\r\n");    //prints the current parameters
  delay(100);   //wait for module to respond
  
  Serial.print("AT+BAND?\r\n");    //prints the current bandwidth
  delay(100);   //wait for module to respond
  
  Serial.print("AT+NETWORKID?\r\n");   //prints the network id
  delay(100);   //wait for module to respond
  
  Serial.print("AT+ADDRESS?\r\n");   //prints the address
  delay(100);   //wait for module to respond

  pinMode(ON,INPUT_PULLUP);   //set pin 5 as input for button
  pinMode(OFF,INPUT_PULLUP);    //set pin 6 as input for button
  pinMode(AUTO,INPUT_PULLUP);   //set pin 7 as input for switch
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(ON)==0){
    Serial.print("AT+SEND=116,1,1\r\n");    //send 1 to address 116("1" is of 1 byte)
    delay(500);   //longer delay to wait for completion of transmition
  }
  if(digitalRead(OFF)==0){
    Serial.print("AT+SEND=116,1,0\r\n");    //send 0 to address 116("0" is of 1 byte)
    delay(500);   //longer delay to wait for completion of transmition
  }

  while(digitalRead(AUTO)==0){
    Serial.print("AT+SEND=116,1,1\r\n");    //send 1 to address 116("1" is of 1 byte)
    delay(1000);   //longer delay to wait for completion of transmition
    Serial.print("AT+SEND=116,1,0\r\n");    //send 0 to address 116("0" is of 1 byte)
    delay(1000);   //longer delay to wait for completion of transmition
  }
}
