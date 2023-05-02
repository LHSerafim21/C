#include "Trabalho.c"

int main(){

    int n;

    system("cls");

    while(n!=1){

        printf("/------------------------INTERFACE----------------------------/\n\n  Digite 1- Problema de Associacao de Tarefas\n  Digite 2- Codificacao de Huffman\n  Digite 3- Problema da Mochila Fracionária\n  Digite 4- Problema da Mochila Booleana\n  Digite 5- Problema da Subsequência Comum Máxima\n  Digite 6- Sair do Programa\n\n/-------------------------------------------------------------/\n\n");
        scanf("%d",&n);

        switch(n){

            case 1:funcao_AssociaaoTarefas();n==0;system("cls");return n; break;
            case 2:funcao_CodifecacaoHuffman();n==0;system("cls");return n; break;
            case 3:funcao_MochilaFracionaria();n==0;system("cls");return n; break;
            case 4:funcao_MochilaBoleana();n==0;system("cls");return n; break;
            case 5:funcao_SubsequenciaComumMaxima();n==0;system("cls");return n; break;
            case 6:n==1;return n;; break;

            default: system("cls");printf("\n\nNUMERO INVALIDO, TENTE OUTRO");sleep(1);break;
        }
    }

    return 0;
}