// 6. Problema dos conspiradores políticos
// 
// Os agentes A, B, C, D, E, F, G e H são conspiradores políticos. De forma a
// coordenar seus esforços, é vital que cada agente seja capaz de comunicar-se
// direta ou indiretamente com todos os outros conspiradores. Esta comunicação,
// contudo, envolve um certo risto para cada um. Os fatos de risco associados à
// comunicação direta entre cada par de conspiradores é dada por:
// 
//    A    A    A    A    A    B    B    C    C    C    C    D    D    E
//    B    C    E    F    G    C    F    D    F    G    H    E    H    H
//    9    3    8    3    4    10   6    6    4    5    7    6    3    5
// 
// Todas as outras comunicações diretas são impraticáveis pois exporiam todo o
// esquema de disfarce. Qual o menor risco total envolvido neste sistema de 
// conexão, ou seja, o menor risco para que cada uma mensagem seja repassada
// para todos os conspiradores?
//
// Notas: 
// 1) O problema pode ser resolvido através do algoritmo de Dijkstra.
// 2) Pelo que eu entendi, a palavra "par" sugere um grafo não direcionado.
// 
// Lucas Matheus Araújo Trajano de Souza
// @devaraujom
// 13 jun 19

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grafo.h"

int escolha(char *string);
int opcoes(char g);
Vertice * no(int n);
int dijkstra(Vertice * o, Vertice * d, Lista * visitar, int c);

int main(int argc, char *argv[]) {
  printf("Bem-vindx à CONSPOL!\n\n");
  printf("Você pode se comunicar com agentes nomeados de A à H.\n");
  printf("Por favor, escolha sua origem e destino e lhe mostraremos o melhor caminho para a comunicação.\n\n");
  
  int o = escolha("Origem: ");
  int d = escolha("Destino: ");

  if (o == d){
    printf("\nerr 1: Os vértices são iguais\n");
    exit(0);
  }

  Lista * visitar = NULL;
  Vertice * or = NULL;
  Vertice * de = NULL;

  or = no(o);
  de = no(d);

  dijkstra(or, de, visitar, 0);

  return 0;
}

int escolha(char *string) {
  char inp;
  int n;
  
  printf("%s", string);
  scanf(" %c", &inp);
  n = opcoes(inp);
  
  return n;
}

int opcoes(char g){
  if (g == 97 || g == 65){
    return 0;
  } else if (g == 98 || g == 66) {
    return 1;
  } else if (g == 99 || g == 67) {
    return 2;
  } else if (g == 100 || g == 68) {
    return 3;
  } else if (g == 101 || g == 69) {
    return 4;
  } else if (g == 102 || g == 70) {
    return 5;
  } else if (g == 103 || g == 71) {
    return 6;
  } else if (g == 104 || g == 72) {
    return 7;
  } else {
    printf("\nerr 0: Opção inexistente: %c\n", g);
    exit(0);
  }
}

Vertice * no(int o){
  Lista * grafo = NULL;
  grafo = listas();

  for (int i = 0; i < o; i++){
    grafo = grafo->proximo;
  }

  Vertice * no = NULL;
  no = grafo->vertice;

  while (grafo->proximo != NULL){
    grafo = grafo->proximo;
  }

  no->pre = grafo->vertice;
  no->dist = -1;

  return no;
}

int dijkstra(Vertice * o, Vertice * d, Lista * visitar, int c){
  visitar = reduzir(visitar);

  for (int j = 0; j < V; j++){
    if (o->adjacente[j] != NULL) {
      if (o->adjacente[j]->pre == NULL) { 
        o->adjacente[j]->pre = (Vertice*) malloc(sizeof(Vertice));
        o->adjacente[j]->pre = o;
        
        if (c == 0){
          o->adjacente[j]->dist = o->dist + o->peso[j] + 1;
        } else {
          o->adjacente[j]->dist = o->dist + o->peso[j];
        }
        
        if (o->adjacente[j]->nome != d->nome) {
          visitar = inserir(visitar, o->adjacente[j]);
        } else {
          d = o->adjacente[j];
        }
      } else {
        if (o->adjacente[j]->dist > o->dist + o->peso[j]){
          o->adjacente[j]->dist = o->dist + o->peso[j];
          o->adjacente[j]->pre = o;
        }
      }
    }
  }

  if (visitar != NULL){
    dijkstra(visitar->vertice, d, visitar, c+1);
  } else {
    int distancia = d->dist;
    Lista * caminho = NULL;
    Vertice * resultado = d;

    while (resultado->pre != NULL){
      caminho = preceder(caminho, resultado);
      resultado = resultado->pre;
    }

    printf("\nO melhor caminho para a comunicação é \"");
    listar(caminho);
    printf("\", estando a este associado o risco de número %d.\n", distancia);
  }

  return 0;
}