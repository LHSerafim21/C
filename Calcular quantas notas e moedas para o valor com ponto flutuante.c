/*/Leia um valor de ponto flutuante com duas casas decimais. Este valor representa um valor monetário. A seguir, calcule o menor número de notas e moedas possíveis no qual o valor pode ser decomposto. As notas consideradas são de 100, 50, 20, 10, 5, 2. As moedas possíveis são de 1, 0.50, 0.25, 0.10, 0.05 e 0.01. A seguir mostre a relação de notas necessárias.

Entrada
O arquivo de entrada contém um valor de ponto flutuante N (0 ≤ N ≤ 1000000.00).

Saída
Imprima a quantidade mínima de notas e moedas necessárias para trocar o valor inicial, conforme exemplo fornecido.

Obs: Utilize ponto (.) para separar a parte decimal./*/

#include <stdio.h>
 
 int main()
 {
  long B,C,D,E,F,G,H,J,K,L,M,N;   
  double A,I;
  scanf("%lf",&A);
  B=A/100;
  C=(A-B*100)/50;
  D=(A-(B*100)-(C*50))/20;
  E=(A-(B*100)-(C*50)-(D*20))/10;
  F=(A-(B*100)-(C*50)-(D*20)-(E*10))/5;
  G=(A-(B*100)-(C*50)-(D*20)-(E*10)-(F*5))/2;
  H=(A-(B*100)-(C*50)-(D*20)-(E*10)-(F*5)-(G*2));
  I=(A-(B*100)-(C*50)-(D*20)-(E*10)-(F*5)-(G*2)-(H))*100;/*/PARTE QUEBRADA/*/
  J=I/50;
  K=(I-(J*50))/25;
  L=(I-(J*50)-(K*25))/10;
  M=(I-(J*50)-(K*25)-(L*10))/5;
  N=(I-(J*50)-(K*25)-(L*10)-(M*5));
  printf("NOTAS:\n%d nota(s) de R$ 100.00\n%d nota(s) de R$ 50.00\n%d nota(s) de R$ 20.00\n%d nota(s) de R$ 10.00\n%d nota(s) de R$ 5.00\n%d nota(s) de R$ 2.00\nMOEDAS:\n%d moeda(s) de R$ 1.00\n%d moeda(s) de R$ 0.50\n%d moeda(s) de R$ 0.25\n%d moeda(s) de R$ 0.10\n%d moeda(s) de R$ 0.05\n%d moeda(s) de R$ 0.01\n",B,C,D,E,F,G,H,J,K,L,M,N);
  return 0;
}