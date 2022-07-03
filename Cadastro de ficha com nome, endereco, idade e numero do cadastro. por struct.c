/*/Cadastro de ficha com nome, endereco, idade e numero do cadastro. por struct/*/

#include <stdio.h>
#include <stdlib.h>

struct pessoa{
    char nome[100], rua[100];
    int idade, numero;
};

int main(){

system("cls");
struct pessoa p;
printf("Digite o seu nome:\n");
gets(p.nome);
system("cls");
printf("Digite a rua em que voce mora:\n");
gets(p.rua);
system("cls");
printf("Digite sua idade:\n");
scanf("%d",&p.idade);
system("cls");
printf("Digite o seu numero:\n");
scanf("%d",&p.numero);
system("cls");

printf("___________________________________\n|Ficha:\n|Nome: %s\n|Rua: %s\n|Idade: %d\n|Numero: %d\n\n\n\n",p.nome,p.rua,p.idade,p.numero);
}