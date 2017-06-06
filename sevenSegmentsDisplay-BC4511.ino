/* Numero de displays */
#define N 4

/* Displays na ordem da esquerda para a direita*/
int sevenSegmentsDisplays[4] = {2,3,4,5};

/* Entradas do CI  => A,B,C,D */
int bc4511Inputs[4] = {6,7,8,9};

/* Códigos BCD para representar números de 0 a 10*/
byte bcdCode[10] = {B0000, B0001, B0010, B0011, B0100, B0101, B0110, B0111, B1000, B1001};

/* Máscara de bits para as entradas do CI */
byte mask[N] = {B0001, B0010, B0100, B1000};


void setup() {
  for(int i = 0; i < N; i++){
    pinMode(sevenSegmentsDisplays[i], OUTPUT);
    pinMode(bc4511Inputs[i], OUTPUT);
  }
}

void loop() {
  int contador = 9513;
  unsigned int digitos[N];
  
  digitos[3] = numero%10;
  digitos[2] = (numero/10)%10;
  digitos[1] = (numero/100)%10;
  digitos[0] = (numero/1000)%10;


    /* Laço para varrer os displays sequencialmente */
    /* Varre da esquerda para direita, começando da dezenaMilhar */
    for(int i = 0; i < N; i++){
      
        /* Laço para setar valores A, B, C, D no BC4511 (código BCD)*/
        for(int j = 0; j < N; j++){

          if( bcdCode[digitos[i]] & mask[j] )
            digitalWrite(bc4511Inputs[j], HIGH);
          else
            digitalWrite(bc4511Inputs[j], LOW);
        }

        /* Liga e desliga display rapidamente */
        digitalWrite(sevenSegmentsDisplays[i], HIGH);
        delay(5);
        digitalWrite(sevenSegmentsDisplays[i], LOW);
    }

}
