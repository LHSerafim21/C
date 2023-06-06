#ifndef TPF_H_INCLUDED
#define TPF_H_INCLUDED

#include<stdio.h>
#include<stdlib.h>
#define MAX_VERTICES 100
#define INFINITO 99999

typedef struct{
    int grafo[MAX_VERTICES][MAX_VERTICES];
    int n;
    int m;
    int d[MAX_VERTICES];
    int pi[MAX_VERTICES];
}Grafo;

void Transformar_Grafo(char n_arq[],Grafo mat);
void imprimir_grafo(Grafo mat);
void ImprimirMenorCaminho(Grafo *G,int s, int v);
void InicializaVetores(Grafo *G,int s);
void EncontrarCaminhosMenores(int u, int v, Grafo *G,int Q[]);
void EncontrarCaminhosMenoresA(int u, int v, Grafo *G);
int EncontrarVerticesPesoMinimo(int Q[],int n);
void Dijkstra(Grafo *G, int s);
void BellmanFord(Grafo *G, int r);


#endif // TPF_H_INCLUDED
