/*/Verificar se o numero dado esta dentro ou fora dos intervalos dados/*/

#include <stdio.h>
int main() 
{
 double n;
 long;
 scanf("%lf",&n);

 if(n<=25 && n>=0)
 {
  printf("Intervalo [0,25]\n");  
 }   

 if(n>25 && n<=50)
 {
  printf("Intervalo (25,50]\n");  
 }   

 if(n>50 && n<=75)
 {
  printf("Intervalo (50,75]\n");  
 }   

 if(n>75 && n<=100)
 {
  printf("Intervalo (75,100]\n");  
 }     
  
 if(n<0 || n>100)
 {
  printf("Fora de intervalo\n");  
 }
 return 0;
}
     
      

  
 
