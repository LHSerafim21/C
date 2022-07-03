/*A importância de R$ 780.000,00 será dividida entre três ganhadores de um concurso.
Sendo que da quantia total:
 O primeiro ganhador receberá 50%;
 O segundo receberá 30%;
 O terceiro receberá o restante.
Calcule e imprima a quantia ganha por cada um dos ganhadores.*/
#include <stdio.h>
int main()
{
 float premio,res;
 printf("Digite o valor do premio: ");
 scanf ("%f",&premio);
 printf("O premio do primeiro ganhador sera: %.2f\n",premio*50/100);
 printf("O premio do segundo ganhador sera: %.2f\n",premio*30/100);  
 printf("O premio do terceiro ganhador sera: %.2f\n",premio*20/100);
 return 0;
}