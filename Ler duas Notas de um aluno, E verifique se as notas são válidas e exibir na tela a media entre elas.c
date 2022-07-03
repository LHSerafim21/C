/*Faça um programa que leia duas notas de um aluno, verifique se as notas são válidas e exiba
na tela a média destas notas. Uma nota válida deve ser, obrigatoriamente, um valor entre 0.0 e
10.0. Caso a nota não possua um valor válido, este fato deve ser informado ao usuário e o
programa termina*/
#include <stdio.h>
int main ()
{
 float nota1,nota2,media;
 printf("Insira a nota 1: ");
 scanf ("%f",&nota1);
 printf("Insira a nota 2: ");
 scanf ("%f",&nota2);
 media=(nota1+nota2)/2;
 if ((nota1<=10 && nota1>=0) && (nota2<=10 && nota2>=0))
 {
   printf("As notas sao validas\nA media entre elas e: %.2f",media);  
 } 
 else
 {
   printf("As notas nao sao validas");
 }
}