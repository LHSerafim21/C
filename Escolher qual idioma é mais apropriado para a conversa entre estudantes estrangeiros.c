/*/Rafael recentemente recebeu uma bolsa de estudos e está fazendo intercâmbio fora do Brasil, onde conheceu várias pessoas de várias nacionalidades diferentes. O idioma nativo desse país é o Inglês, e todas as pessoas que Rafael conheceu falam inglês como primeira ou segunda língua.

Como aprender um segundo idioma é uma tarefa difícil e cansativa, as pessoas preferem falar seu idioma nativo sempre que possível. Uma exceção à essa regra é quando há duas pessoas no grupo que não tem o mesmo idioma nativo. Nesse tipo de situação, o idioma utilizado é o inglês.

Por exemplo, se em um grupo há só brasileiros, o idioma falado será o português, mas caso haja um espanhol entre os brasileiros, o idioma falado será o inglês.

Rafael as vezes fica confuso sobre qual idioma deveria ser falado em cada grupo de pessoas, e para isso pediu sua ajuda.

Entrada
A primeira linha contém um inteiro N, indicando o número de casos de testes a seguir.

Cada caso de teste inicia com um inteiro K (2 ≤ K ≤ 100), representando o número de pessoas no grupo. Em seguida haverá K linhas, contendo uma string S cada, representando o idioma nativo de cada uma dessas K pessoas.

Cada string conterá no mínimo 1 e no máximo 20 caracteres, entre eles apenas letras minúsculas (a-z).

Saída
Imprima uma linha, contendo uma string S, representando o idioma mais apropriado para a conversa.

Exemplo de Entrada:	
2
3
portugues
chines
portugues
/*/

#include <stdio.h>

int main()
{
 int N, K, i, d;
 char idiomas[100][21];
 
 scanf("%d", &N);
 
 while(N--)
 {
  scanf("%d", &K);
  
  for(i = 0; i < K; i++)
   scanf(" %s", idiomas[i]);
  
  d = 0;
  
  for(i = 1; i < K && !d; i++)
   if(strcmp(idiomas[0], idiomas[i]) != 0)
    d = 1;
  
  if(d)
   printf("ingles\n");
  else
   printf("%s\n", idiomas[0]);
  
 }
 
 return 0;
}