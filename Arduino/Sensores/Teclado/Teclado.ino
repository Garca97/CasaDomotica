#include <Keypad.h> //llama a la librería Keypad.h
 
char contrasena[]="2222";  //aquí escribimos la contraseña de 4 dígitos
char codigo[4];            //Cadena donde se guardaran los caracteres de las teclas presionadas
int cont=0;          //variable que se incrementara al presionar las teclas
 
const byte ROWS = 4; //Numero de filas del teclado que se esta usando
const byte COLS = 4; //Numero de columnas del teclado que se esta usando
 
char hexaKeys[ROWS][COLS] =  //Aquí pondremos la disposición de los caracteres tal cual están en nuestro teclado
{
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
 
byte rowPins[ROWS] = {9, 8, 7, 6}; //Seleccionamos los pines en el arduino donde iran conectadas las filas
byte colPins[COLS] = {5, 4, 3, 2}; //Seleccionamos los pines en el arduino donde iran conectadas las filas
 
Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); //inicializa el teclado
 
void setup()
{
  pinMode(13, OUTPUT); //Pin 13 como salida
  Serial.begin(9600); //inicializar puerto serie
}
 
void loop()
{
  char customKey = customKeypad.getKey(); //se guarda en la variable customKey el caracter de la tecla presionada
  if (customKey != NO_KEY)         //se evalúa si se presionó una tecla
  {
    codigo[cont]=customKey;          //se guarda caracter por caracter en el arreglo codigo[]
    Serial.println(codigo[cont]);    //se imprime en el puerto serie la tecla presionada
    cont=cont+1;              //incrementamos la variable cont
    if(cont==4)          //si ya fueron presionadas 4 teclas se evalúa si la contraseña es correcta
    {
      if(codigo[0]==contrasena[0]&&codigo[1]==contrasena[1]&&codigo[2]==contrasena[2]&&codigo[3]==contrasena[3])
      {
        digitalWrite(13,!digitalRead(13));        //si la contraseña fué correcta se enciende o se apaga el led del pin13
      }
      cont=0;  //resetear a 0 la variable cont
    }
  }
}
