/*/Descobrir por funções se o numero é primo ou não/*/

#include <stdio.h>

int primo(int a){
    int i, primo = 1;
    for(i = 2; i < a; i++){
        if(a % i == 0){
            primo = 0;   
            }
        }
    if(primo && a > 0){
            return 1;
        }else{
            return 0;
    }
} 
int main(){

    int x;

    printf("Digite um numero inteiro positivo para verificar se ele e primo: ");
    scanf("%d", &x);
    printf("%d\n", primo(x));

    return 0;    
}