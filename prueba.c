#include <stdio.h>
#include <string.h>


int login ( )
{
        char nombre [6];
    char contra [6];
    char nombre1 [6]= "maria";
    char nombre2 [6]= "juan";
    char nombre3 [6]= "luis";

    char cont1[6]= "12345";
    char cont2[6]= "09876";
    char cont3[6]= "10293";

    printf("Ingrese el nombre del usuario\n");
    scanf("%s", &nombre);

    printf("Ingrese la contraseña del usuario\n");
    scanf("%s", &contra);

    if (strcmp(nombre,nombre1)  && strcmp( contra, cont1)){
        printf("Acceso permitido. Ingresando menu\n");
        return 1;
    }
          else if (strcmp(nombre,nombre2)  && strcmp( contra, cont2)){
           printf("Acceso permitido. Ingresando menu\n");
           return 1;
         }
             else if (strcmp(nombre,nombre3)  && strcmp( contra, cont3)){
             printf("Acceso permitido. Ingresando menu\n");
             return 1;
             }
              else {
               printf("Acceso denegado\n");
               return 0;
              }

}

// La funcion contiene el precio de la ruta
float Precioruta( int ruta){
float precioruta;
switch (ruta){
    case 1:
    precioruta = 0.10;
    break;

    case 2:
    precioruta = 0.15;
    break;

    case 3:
    precioruta = 0.20;
    break;

    default:
    printf ("Ruta invalida\n");
    precioruta=0.0; 
    break;
}
return precioruta;
}

// La funcion contiene el descuento de la ruta
float Descuento  (float precioruta){
    float descuento = 0.0;
    if (precioruta < 50.0 ){
        descuento= 0.0;
        printf ("Sin descuento");
    }
    else if (precioruta >= 50.0 && precioruta <100.0){
    descuento = precioruta * 0.1;
    }
     else if (precioruta >= 500.0 ){
    descuento = precioruta * 0.2;
    }
return descuento;
}






void operacion (){
    int i;
    int ruta;
    float preciototal, descuento,distancia, subtotal;
    float preciokilometro;
    for (i=0; i<5; i++)
    {
      printf("Cliente %d\n", i + 1);
      printf ("Ingrese el tipo de ruta 1. urbano 2.- interurbana  3. internacional\n");
      scanf("%d", &ruta);
      printf ("Ingrese distancia en km\n");
      scanf("%s", &distancia);
    
       preciokilometro = Precioruta(ruta);
       subtotal = distancia * preciokilometro;
       descuento = Descuento(subtotal);
      preciototal= subtotal-descuento;

       printf("Subtotal: %.2f\n", subtotal);
      printf("Descuento: %.2f\n", descuento);
      printf("Precio Total: %.2f\n", preciototal);
   }    

}



void interaccion (){
int cont;
char sms[100];
char cat;
int noticias = 0;
int eventos = 0;
int preguntas = 0;
for (cont = 0; cont < 5; cont++) {
    printf("Mensaje %d\n", cont + 1);
    printf("Ingrese el contenido del mensaje: \n");
    scanf(" %s", &sms);
    printf("Ingrese la categoría del mensaje: 1.- Noticias 2- Eventos 3.- Preguntas : \n");
    scanf(" %c", &cat);

    switch (cat) {
        case 1:
            noticias++;
            break;
        case 2:
            eventos++;
            break;
        case 3:
            preguntas++;
            break;
        default:
            printf("La categoría es inválida.\n");
            break;
    }
}

printf("Publicaciones:\n");
printf("Noticias: %d\n", noticias);
printf("Eventos: %d\n", eventos);
printf("Preguntas: %d\n", preguntas);
}





void menu (){
    int opc;
    do{
printf("Bienvenido al menu\n");
printf ("1.- Operacion de transporte\n");
printf ("2.- Interactuar en la red social\n");
printf ("3.- salir\n");
scanf ("%d", opc);

switch(opc) {
    case 1:
    operacion ();
    break;

    case 2:
    interaccion ();
    break;


    case 3:
    default:
    break;
}
} while (opc!=3);
  printf ("opcion inexistente");
}




int main (){
  int intento;
  intento = login ();
  if (intento==1){
   menu (); 
  }
  else {
    printf("intento fallido");
  }
  
  return 0;
}