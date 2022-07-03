/*/Ler o nome, idade e endereço de uma pessoa/*/

#include <stdio.h>
int main(void)
{  
 char nome[31],endereco[31];
 int idade;

printf("Digite o nome: ");
gets(nome);

printf("Digite o endereco: ");
gets(endereco);

fflush (stdin);

printf("Digite a idade: ");
scanf("%d",&idade);

printf("seu nome e: %s\nseu endereco e: %s\nsua idade: %d",nome,endereco,idade);
 return 0;
}