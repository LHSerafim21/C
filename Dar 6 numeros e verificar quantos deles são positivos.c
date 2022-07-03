/*/Dar 6 numeros e verificar quantos deles são positivos/*/

#include <stdio.h>
 
int main() {
 int n1,n2,n3,n4,n5,n6,A,B,C,D,E,F,soma;
 scanf("%d",&n1);
 scanf("%d",&n2);
 scanf("%d",&n3);
 scanf("%d",&n4);
 scanf("%d",&n5);
 scanf("%d",&n6);

 if(n1>=1)
 {
  A=1;
 }
 else
 {
  A=0;
 }
 
 if(n2>=1)
 {
  B=1;
 }
 else
 {
  B=0;
 }

 if(n3>=1)
 {
  C=1;
 }
 else
 {
  C=0;
 }

 if(n4>=1)
 {
  D=1;
 }
 else
 {
  D=0;
 }

 if(n5>=1)
 {
  E=1;
 }
 else
 {
  E=0;
 }

 if(n6>=1)
 {
  F=1;
 }
 else
 {
  F=0;
 }
 
 soma=A+B+C+D+E+F;
 printf("%d valores positivos\n",soma);
 return 0;
}