#include <stdio.h>
#include "Exercicio_1.h"
#include "Exercicio_2.h"
#include "Exercicio_3.h"

int main(){
    int e, n=1;


    while(n!=0){

        system("cls");
        printf("Digite qual exercicio deseja testar:\n\n0- SAIR\n1 - Exercicio 1\n2 - Exercicio 2\n3 - Exercicio 3\n");
        scanf("%d",&e);

        switch(e){
            case 0:n=0;break;
            case 1: funcao_Exercicio1();break;
            case 2: funcao_Exercicio2();break;
            case 3: funcao_Exercicio3();break;
        }
    }

}
