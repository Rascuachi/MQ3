int valor_limite= 400;                  // Fiaja el valor limite en el que se activa la alarma    
float valor_alcohol;

void setup() { 
  Serial.begin(9600);                   // Activa el puerto Serial a 9600 Baudios
  pinMode(2,OUTPUT);   
  pinMode(3,OUTPUT);                  
}

void loop() { 
  valor_alcohol=analogRead(A0);
  Serial.println(valor_alcohol);       // Envia al Serial el valor leido del Sensor MQ3 
  float porcentaje=(valor_alcohol/10000);  //calcula el porcentaje
  Serial.println(porcentaje);            // Envia al Serial el porcentaje 
  Serial.println(' ');    
  
  if(valor_alcohol > valor_limite){    // Si la medida de gas metano es mayor de valor limite
       digitalWrite(2, HIGH);
       digitalWrite(3, LOW);            
   }
   else{
      digitalWrite(2, LOW);
      digitalWrite(3, HIGH);
   }
  delay (400);                          // Espera 400ms para realizar la proxima medida
}