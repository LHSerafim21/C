/*/Calcular fatorial simples/*/

#include <stdio.h>
int main()
{
int n,x,y=1;
scanf("%d", &n);
for(x=n;x>=1;x--)
y*=x;
printf ("%d\n",y);
return 0;
}