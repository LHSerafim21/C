#include <stdio.h>
#include <stdlib.h>
#include "Escurecer.h"
#include "Clarear.h"
#include "Girar.h"
#include "Binarizacao.h"

void main(){

    int x,y=0;

    while(y==0){

        system("cls");
        printf("Digite a funcao desejada: \n\n0- Sair\n1- Escurecer Imagem\n2- Clarear Imagem\n3- Girar Imagem\n4- Binarizacao Histograma\n");
        scanf("%d",&x);

        switch(x){
            case 0: y=1; break;
            case 1: Principal__Escurecer(); break;
            case 2: Principal__Clarear(); break;
            case 3: Principal__Girar(); break;
            case 4: Principal__Binarizacao(); break;
        }
    }

    return 0;
}
