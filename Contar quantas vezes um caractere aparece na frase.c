/*/Contar quantas vezes um caractere aparece na frase/*/

#include <stdio.h>

int quant_char(char c, char *s){
    
    int i, n = 0;
    for(i = 0; s[i] != '\0'; i++){
        if(s[i] == c){
            n++;
        }
    }
    return n;
}

int main(){

    char s[20];
    char c;

    printf("Digite uma string: ");
    gets(s);

    printf("Digite um caractere: ");
    scanf("%c", &c);

    printf("O caracter aparece %d vezes na string\n", quant_char(c, s));

    return 0;
}