#ifndef EXERCICIO_3_H_INCLUDED
#define EXERCICIO_3_H_INCLUDED
#endif // EXERCICIO_3_H_INCLUDED

#define PESO 56.00
#define ALTURA 39.00
#define LARGURA 45.00

int atribuirPreferencialOuNao(int x){

    int cli = (int)rand() / RAND_MAX; // Gera um número aleatório entre 0 e 1

    if(cli == 1){
        return x=1;
    }else{
        return x=0;
    }
}

float atribuirValorFloatAleatorio(float valorMin, float valorMax) {
    float valorAleatorio = (float)rand() / RAND_MAX; // Gera um número aleatório entre 0 e 1
    float valor = valorMin + valorAleatorio * (valorMax - valorMin); // Mapeia o número aleatório para o intervalo desejado
    return valor;
}

void Verificar_Preferencial(){

    int x;
    char cliente[150];

     x = atribuirPreferencialOuNao(x);

    if(x == 1){
        printf("O cliente é preferencial!!");
        sleep(3);
    }else{
        printf("O cliente nao é preferencial!!");
        sleep(3);
    }
}

int Verificar_Dimensao(int y){

    srand(time(NULL));

    float Peso, Altura, Largura;
    float valorMin = 0.0;
    float valorMax = 100.0;

    float valorAleatorio = atribuirValorFloatAleatorio(valorMin, valorMax);
    Peso = valorAleatorio; valorAleatorio =0;
    valorAleatorio = atribuirValorFloatAleatorio(valorMin, valorMax);
    Altura = valorAleatorio; valorAleatorio =0;
    valorAleatorio = atribuirValorFloatAleatorio(valorMin, valorMax);
    Largura = valorAleatorio; valorAleatorio =0;

    system("cls");
    printf("Peso Maximo = 56.00 kgs\nAltura Maxima = 39.00 cms\nLargura Maxima = 45.00 cms\n\nAs dimensoes do pacote que chegou sao:\n\nPESO: %.2f\nALTURA: %.2f\nLARGURA: %.2f", Peso, Altura, Largura);

    if((Peso <= PESO) && (Altura <= ALTURA) && (Largura <= LARGURA)){
        printf("\nO pacote esta dentro dos padroes");
        sleep(5);
        y=2;
    }else{
        printf("\n\nO pacote nao esta dentro dos padroes");
        sleep(5);
        y=1;
    }

    return y;
}

int funcao_Exercicio3(){

    int x,y;

    while(x!=0){
        Verificar_Dimensao(y);
        if(y == 2){
            Verificar_Preferencial();
        }else{
            system("cls");
            printf("Deseja Parar Simulacao?\n\n0- SIM\n1- NAO\n");
            scanf("%d",&x);
        }
    }
}
