
int valorDisplay;
bool chegouNove = false;
byte DisplaySeteSeg[10][7] = { 
{ 1,1,1,1,1,1,0 },  
{ 0,1,1,0,0,0,0 },  
{ 1,1,0,1,1,0,1 },  
{ 1,1,1,1,0,0,1 },  
{ 0,1,1,0,0,1,1 },  
{ 1,0,1,1,0,1,1 }, 
{ 1,0,1,1,1,1,1 },  
{ 1,1,1,0,0,0,0 },  
{ 1,1,1,1,1,1,1 },  
{ 1,1,1,0,0,1,1 },  
};


void setup() 
{  
  pinMode(2, OUTPUT);   
  pinMode(3, OUTPUT); 
  pinMode(4, OUTPUT); 
  pinMode(5, OUTPUT); 
  pinMode(6, OUTPUT); 
  pinMode(7, OUTPUT); 
  pinMode(8, OUTPUT); 
  pinMode(9, OUTPUT); 
  

valorDisplay = 0;
Ligar(valorDisplay);
LigarInvertido(valorDisplay);
}

void Ligar(byte digito){
  
byte pino = 2;

for(byte cts = 0; cts < 7; ++cts){
  
  digitalWrite(pino, DisplaySeteSeg[digito][cts]);
  pino++;
  }
  
}
void LigarInvertido(byte digito){
  
byte pino = 2;

for(byte cts = 0; cts < 7; ++cts){
  
  digitalWrite(pino, DisplaySeteSeg[digito][cts]);
  pino++;
  }
  
}


void loop() 
{
 delay(1000);
if(chegouNove == false){
 Ligar(valorDisplay);
 valorDisplay++;
}
 
if(valorDisplay > 9){
chegouNove = true;

  digitalWrite(9, HIGH);
  delay(500);
  digitalWrite(9, LOW);
  delay(500);
}

if(chegouNove){
  LigarInvertido(valorDisplay);
  valorDisplay--;
 
}
if(valorDisplay == 0){
  chegouNove = false;
}
   

}
