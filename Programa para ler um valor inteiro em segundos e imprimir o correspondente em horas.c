/*Faça um programa para ler um valor inteiro em segundos e imprimir o correspondente em horas,
minutos e segundos*/
#include <stdio.h>
int main()
{
 int segundos,minutos,horas;
 printf("Digite um valor em segundos: ");
 scanf ("%d",&segundos);
 minutos=segundos/60;
 horas=minutos/60;
 printf("%d segundos correspondem a %d minutos, que correspondem a %d hora",segundos,minutos,horas);
 return 0;

}