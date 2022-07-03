/*/Concatenar duas frases por função/*/

#include<stdio.h>

char funcao_concatenacao(char str1[100],char str2[100], char str3[100]){
    int i = 0, j = 0;
    while(str1[i] != '\0'){
        str3[i] = str1[i];
        i++;
    }
    while(str2[j] != '\0'){
        str3[i + j] = str2[j];
        j++;
    }
    str3[i + j] = '\0';
}

int main(){
    char frase1[100], frase2[100], frase3[100];
    printf("Digite a primeira frase: ");
    gets(frase1);
    printf("Digite a segunda frase: ");
    gets(frase2);
    funcao_concatenacao(frase1, frase2, frase3);
    printf("%s\n", frase3);
    return 0;
}