#include "TPF.c"

int main() {


    Grafo grafo;
    Transformar_Grafo("Grafo1.txt",&grafo);


    for(int i=1;i<=grafo.n;i++){
        imprimir_grafo(&grafo);
        printf("\nDijkstra: \n");
        Dijkstra(&grafo,i);
        printf("\n");
        printf("Bellman-Ford: \n");
        BellmanFord(&grafo,i);
        printf("\n");
        system("pause");
        system("cls");
    }



    return 0;
}
