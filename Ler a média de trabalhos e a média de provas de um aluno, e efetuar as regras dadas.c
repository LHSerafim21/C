/*/Faça um programa para ler a média de trabalhos e a média de provas de um
aluno. Em seguida, o programa deverá calcular a média final do aluno com base
nas seguintes regras:
 Se o aluno apresentar médias de trabalho e de provas acima de cinco, a
média final será a média aritmética entre as médias de trabalhos e de provas;
 Caso contrário, a média final será a menor das médias obtidas entre
trabalhos e provas/*/
#include <stdio.h>
int main()
{
float n1,n2,media;
printf("Insira a media dos trabalhos: ");
scanf("%f",&n1);
printf("Insira a media das provas: ");
scanf("%f",&n2);  

media=(n1+n2)/2;

if((n1>=5) && (n2>=5))
{
 printf("A media final do aluno e %.1f",media);   
}
if(n1>n2)
{
 printf("A media final do aluno e %.1f",n2);   
}
if(n2>n1)
{
 printf("A media final do aluno e %.1f",n1);   
}
if(n1=n2)
{
 printf("A media final do aluno e %.1f",n1);
}
}