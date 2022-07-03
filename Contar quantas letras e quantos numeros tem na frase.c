/*/Contar quantas letras e quantos numeros tem na frase/*/

#include <stdio.h>
#include <string.h>

int funcao_contagem(char frase[100], int *a, int *b)
{
  int N = 0, L = 0, i = 0;
  while (frase[i] != '\0'){
        if(frase[i]=='0' || frase[i]=='1' || frase[i]=='2' || frase[i]=='3' || frase[i]=='4' || frase[i]=='5' || frase[i]=='6' || frase[i]=='7' || frase[i]=='8' || frase[i]=='9'){
            N++;
        }if(frase[i] <= 90 && frase[i] >= 65 || frase[i] <= 122 && frase[i] >= 97){
            L++;
        }
        i++;
  }
  *a = N;
  *b = L; 
}

int main()
{
 char frase[100];
 int a, b;
 printf("Digite a String: ");
 gets(frase);
 funcao_contagem(frase, &a, &b);
 printf("Numero de numeros na string: %d\n", a);
 printf("Numero de letras na string: %d\n", b);
}