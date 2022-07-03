/*Faça um programa para ler a média e a frequência de um aluno. Em seguida,
verificar se ele está aprovado, em exame ou reprovado. Para tanto considere as
seguintes regras:
 O aluno é aprovado se estiver com média acima de cinco e frequência acima
de setenta;
 O aluno está em exame se estiver com média entre três e cinco e frequência
acima de setenta;
 O aluno é reprovado se estiver com média abaixo de três ou frequência
abaixo de setenta.
Para este exercício, considere que os valores são corretamente fornecidos pelo
usuário, isto é, a média está entre 0 e 10; e a frequência está em 0 e 100*/

#include <stdio.h>
int main()
{
    int n; 
    float nota1,nota2,media,aulas1,aulas2,porcentagem;

        printf("Digite a nota 1: ");    
        scanf ("%f",&nota1);
        printf("Digite a nota 2: "); 
        scanf ("%f",&nota2);
      
        printf("Digite o total de aulas: ");
        scanf("%f",&aulas1);
        printf("Digite o total de aulas presente do aluno: ");
        scanf("%f",&aulas2);

        media = ((nota1+nota2)/2);
        porcentagem = ((aulas2/100)*aulas1);

        if((porcentagem>=70) && (media>=5))
        {
        n=1;   
        }
        
        if((porcentagem>=70) && ((media<=4,99) && (media>=3)))
        {
        n=2;
        }

        if((porcentagem<70) || (media<3))
        {
        n=3;
        }

        switch (n)
        {

            case 1:printf("O aluno foi APROVADO com %.2f porcento de presenca e media igual a %.2f",porcentagem,media);break;

            case 2:printf("O aluno foi encaminhado para o EXAME com %.2f porcento de frequencia e media igual a %.2f",porcentagem,media);break;

            case 3:printf("O aluno foi REPROVADO com %.2f porcento de presenca e media igual a %.2f",porcentagem,media);break;
        }
    return 0;
}


       
  
      
        
  
        

  
