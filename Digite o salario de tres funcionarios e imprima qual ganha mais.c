/*/Digite o salario de tres funcionarios e imprima qual ganha mais/*/
#include <stdio.h>
 
int main() {
 int A,B;
 float C;
 scanf("%d",&A);
 scanf("%d",&B);
 scanf("%f",&C);
 printf("NUMBER = %d\nSALARY = U$ %.2f\n",A ,(float)B * C);
 return 0;
}