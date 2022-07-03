/*/Faça um programa para identificar se um determinado ano fornecido pelo
usuário é bissexto. Para tanto, verifique com a seguintes regras:
 Um ano é bissexto se for divisível por 400 ou
 Um ano é bissexto se for divisível por 4 e não for divisível por 100.
Exemplos: 1600, 1988, 1992, 1996, 2000, 2004, 2008, 2012, 2016./*/
#include <stdio.h>
int main()
{
int n,x;
printf("Insira o ano: ");
scanf("%d",&n);
x=n%400;
if(x!=0)
{
 printf("Nao e ano Bissexto");   
}    
else
{
 printf("E ano Bissexto");
}
return 0;
}