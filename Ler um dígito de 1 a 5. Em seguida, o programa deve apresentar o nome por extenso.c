/*Faça um programa para ler um dígito de 1 a 5. Em seguida, o programa deve apresentar o
nome do dígito por extenso.
Exemplo:
Informe um dígito de 1 a 5: 4
Nome por extenso: quatro*/

#include <stdio.h>
int main()
{
  int n1;
  printf("Digite um numero de 1 a 5: ");
  scanf ("%d",&n1);  

  if (n1==1)
  {
   printf("Um");
  }
  if (n1==2)
  {
   printf("Dois");   
  }
  if (n1==3)
  {
   printf("Tres");   
  }
  if (n1==4)
  {
   printf("Quatro");   
  }
  if (n1==5)
  {
   printf("Cinco");   
  }
  if ((n1>5) || (n1<0))
  {
   printf("Numero invalido, Digite um numero entre 1 e 5"); 
  }
  return 0;
}
