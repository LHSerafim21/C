/*/Digitar um numero em segundos e mostrar quantas horas, minutos e segundos são esse numero/*/

#include <stdio.h>

int calcular_tempo (int tempo, int *a, int *b, int *c)
{   
 int resto;
 *a = tempo / 3600;
 resto = tempo % 3600;
 *b = resto / 60;
 *c = resto % 60;
}
int main()
{
int tempo, h, m, s;
printf("Digite o numero de segundos: ");
scanf("%d", &tempo);
calcular_tempo(tempo, &h, &m, &s);
printf("%d hora(s) %d minuto(s) e %d segundo(s)\n", h, m, s);
return 0;
}