#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define N 10
#define M 60

typedef struct avion {
    char codAlf[N];
    char destino[M];
    struct avion *sig;
} Avion;

Avion *cabeza = NULL;
Avion *cola = NULL;


void InsertarAviónCola(char codAlf[], char destino[]){
    Avion *avionNuevo, *aux;
    avionNuevo = (Avion *)malloc(sizeof(Avion));

    aux = cabeza;

    while(aux != NULL) {
                    aux = aux->sig;
        }
        if(aux == NULL){
            strcpy(avionNuevo->codAlf, codAlf);
        }
    aux = cabeza;
    while(aux != NULL) {
                    aux = aux->sig;
        }
      if(aux == NULL){
           strcpy(avionNuevo->destino, destino);
    }
 
 
    avionNuevo->sig = NULL;
 
    if(cabeza == NULL){
        cabeza = avionNuevo;
    }
    else{
        cola->sig = avionNuevo;
    }
 
    cola = avionNuevo;
    printf("\nLa información del avion ha sido guardada exitosamente.\n");
}


    



void InsertarAvión(){
  
    Avion *new;
    new = (Avion *)malloc(sizeof(Avion));
    printf("\nHa escogido insertar un avión.\nEscriba un identificador de la forma de un código alfanumérico que lo identifique:\n ");
    scanf("%s", new->codAlf);
    fflush(stdin);
    
    printf("\n\nPor favor inngrese las coordenadas de su desitino en tériminos de:\n grados, minutos, segundos y orientación, pudiendo haber 4 orientaciones posibles, Norte, Sur, Este y Oeste:\n(Ejemplo: Longitud = 20°20’5’’N, Latitud = 45°30’2’’E)\n");
   gets(new->destino);
    fflush(stdin);
    
     InsertarAviónCola(new->codAlf, new->destino);
    free(new);
}



void imprimirAviones(){
 
    Avion *auxiliar;
    int TAM;
 
    auxiliar = cabeza;
 
    TAM = 0;
    while(auxiliar != NULL) {
        auxiliar = auxiliar->sig;
        TAM++;
    }

    auxiliar = cabeza;
    printf("\nLista de Aviones\n");
 
    while(auxiliar != NULL) {
        printf("=========\n");
        printf("Identifiacdor:   ");puts(auxiliar->codAlf);
        printf("\nDestino:     ");  puts(auxiliar->destino);
        auxiliar = auxiliar->sig;
    }
 
    if(TAM == 0){
        printf("=========\n");
        printf("La cola está vacía.\n");
    }
}


void mostrarSigAvion(){
    
   
    Avion *auxiliar;
    auxiliar = cabeza;
    if (auxiliar != NULL) {
    printf("\nIdentidicador: ");
        printf("%s", auxiliar->codAlf);
    printf("\nDestino: ");
    printf("%s", auxiliar->destino);
}
}





void eliminarSigAvion(){

    Avion *aux_borrar;
    aux_borrar = cabeza;
    cabeza = aux_borrar->sig;
                    free(aux_borrar);
}
 






void ExtraerSiguienteAvion(){
    int y;
    printf("El siguiente avión en despegar es el primero en la cola, esto quiere decir que el el proximo vuelo en salir es el de: \n");
    mostrarSigAvion();
    printf("\n\n");
    printf("Para eliminarlo seleccione 1, de lo contrario seleccione 2.\n");
    scanf("%d", &y);
    if (y==1) {
        eliminarSigAvion();
        
    }
}




int main(){
    int x=0;
    printf("\n\t\t\tPROGRAMA PARA INTRODUCIR Y ELIMINAR AVIONES DE UNA COLA\t\t\t\n");
    printf("\nPara empezar a agregar contactos, escriba 1\n");
    printf("\nPara empezar a extraer siguiente avión, escriba 2\n");
    scanf("%d", &x);
    while (x==1) {
        InsertarAvión();
        printf("\nPara seguir agregando aviones escriba 1, de lo contrario, escriba 3\n");
        scanf("%d", &x);
    }
    printf("\nSu cola de aviones ha quedado de la siguiente manera:\n");
    imprimirAviones();
    printf("\nPara empezar a extraer siguiente avión, escriba 2, de lo contrario escriba 0.\n");
    scanf("%d",&x);
    while (x==2) {
        ExtraerSiguienteAvion();
        printf("Para eliminar otro avión escriba 2, de lo contrario escriba 1: \n"); scanf("%d", &x);
    }
    printf("\nSu cola de aviones ha quedado de la siguiente manera:\n");
    imprimirAviones();
    return 0;
}
