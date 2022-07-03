/*/Digitar um valor e mostrar as notas para o valor e o resto a ser dado, por função/*/

#include <stdio.h>
#include <math.h>

void quant_notas(float valor, float nota, float *quant, float *resto){
    *quant = valor / nota;
    *resto = valor - nota * (int)*quant;
}
int main(){

    float valor, nota, quant = 0, resto = 0;

    printf("Digite um valor: ");
    scanf("%f", &valor);

    nota = 100;
    quant_notas(valor, nota, &quant, &resto);
    valor = resto;
    printf("Quantidade de notas de R$ %.2f: %.0f\n", nota, floor(quant));
    
    nota = 50;
    quant_notas(valor, nota, &quant, &resto);
    valor = resto;
    printf("Quantidade de notas de R$ %.2f: %.0f\n", nota, floor(quant));
    
    nota = 20;
    quant_notas(valor, nota, &quant, &resto);
    valor = resto;
    printf("Quantidade de notas de R$ %.2f: %.0f\n", nota, floor(quant));
    
    nota = 10;
    quant_notas(valor, nota, &quant, &resto);
    valor = resto;
    printf("Quantidade de notas de R$ %.2f: %.0f\n", nota, floor(quant));
    
    nota = 5;
    quant_notas(valor, nota, &quant, &resto);
    valor = resto;
    printf("Quantidade de notas de R$ %.2f: %.0f\n", nota, floor(quant));
    
    nota = 2;
    quant_notas(valor, nota, &quant, &resto);
    valor = resto;
    printf("Quantidade de notas de R$ %.2f: %.0f\n", nota, floor(quant));
    
    nota = 1;
    quant_notas(valor, nota, &quant, &resto);
    valor = resto;
    printf("Quantidade de moedas de R$ %.2f: %.0f\n", nota, floor(quant));
    
    nota = 0.5;
    quant_notas(valor, nota, &quant, &resto);
    valor = resto;
    printf("Quantidade de moedas de R$ %.2f: %.0f\n", nota, floor(quant));
    
    nota = 0.25;
    quant_notas(valor, nota, &quant, &resto);
    valor = resto;
    printf("Quantidade de moedas de R$ %.2f: %.0f\n", nota, floor(quant));
    
    nota = 0.1;
    quant_notas(valor, nota, &quant, &resto);
    valor = resto;
    printf("Quantidade de moedas de R$ %.2f: %.0f\n", nota, floor(quant));
    
    nota = 0.05;
    quant_notas(valor, nota, &quant, &resto);
    valor = resto;
    printf("Quantidade de moedas de R$ %.2f: %.0f\n", nota, floor(quant));

    printf("Resto: R$ %.2f\n", resto);
      
    return 0;
}