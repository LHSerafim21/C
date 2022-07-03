/*Escreva um programa para ler a idade de um nadador e classifica-lo conforme
a tabela a seguir:
Categoria Idade
Infantil A: 5 a 7
Infantil B: 8 a 10
Juvenil A: 11 a 13
Juvenil B: 14 a 17
Adulto Maiores de 18 anos*/

#include <stdio.h>
int main ()
{
int idade;
printf("Insira a idade do nadador: ");
scanf("%d",&idade);

if (idade<5)
{
printf("Idade Invalida, digite uma idade a partir de 5 anos");    
}    

if ((idade>=5) && (idade<=7))
{
printf("Esta classificada no sistema infantil A");    
}

if ((idade>=8)&&(idade<=10))
{
printf("Esta classificada no sistema infantil B");    
}

if ((idade>=11)&&(idade<=13))
{
printf("Esta classificada no sistema Juvenil A");    
}

if ((idade>=14)&&(idade<=17))
{
printf("Esta classificada no sistema Juvenil B");    
}

if (idade>=18)
{
printf("Maior de idade");    
}
return 0;
}