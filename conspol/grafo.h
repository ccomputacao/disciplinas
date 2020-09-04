// Nome é o nome do vértice;
// V é o número máximo de vértices;
// Para cada vertice adjacente, em um array de vértices, numerados 
// de 0 a V-1, há um peso corresponde, em um array de pesos, de número igual;
// Há um vertice nomeado "pre" em cada estrutura do nó, onde este é o 
// vértice anterior do caminho;
// Há um valor correspondente à distância (dist).
// 
// Lucas Matheus Araújo Trajano de Souza
// @devaraujom
// 24 jun 19

#define V 6

typedef struct Vertice {
  char *nome;
  int peso[V];
  struct Vertice * adjacente[V];
  struct Vertice * pre;
  int dist;
} Vertice;

typedef struct Lista {
  struct Vertice * vertice;
  struct Lista * proximo;
} Lista;

Lista * listas(void) {
  Vertice * A = NULL;
  Vertice * B = NULL;
  Vertice * C = NULL;
  Vertice * D = NULL;
  Vertice * E = NULL;
  Vertice * F = NULL;
  Vertice * G = NULL;
  Vertice * H = NULL;
  Vertice * VAZIO = NULL;
  
  A = (Vertice*) malloc(sizeof(Vertice));
  B = (Vertice*) malloc(sizeof(Vertice));
  C = (Vertice*) malloc(sizeof(Vertice));
  D = (Vertice*) malloc(sizeof(Vertice));
  E = (Vertice*) malloc(sizeof(Vertice));
  F = (Vertice*) malloc(sizeof(Vertice));
  G = (Vertice*) malloc(sizeof(Vertice));
  H = (Vertice*) malloc(sizeof(Vertice));
  VAZIO = (Vertice*) malloc(sizeof(Vertice));

  A->nome = "A";
  A->adjacente[0] = B;
  A->peso[0] = 9;
  A->adjacente[1] = C;
  A->peso[1] = 3;
  A->adjacente[2] = E;
  A->peso[2] = 8;
  A->adjacente[3] = F;
  A->peso[3] = 3;
  A->adjacente[4] = G;
  A->peso[4] = 4;
  A->adjacente[5] = NULL;
  A->peso[5] = -1;
  A->pre = NULL;
  A->dist = 0;

  B->nome = "B";
  B->adjacente[0] = A;
  B->peso[0] = 9;
  B->adjacente[1] = C;
  B->peso[1] = 10;
  B->adjacente[2] = F;
  B->peso[2] = 6;
  B->adjacente[3] = NULL;
  B->peso[3] = -1;
  B->adjacente[4] = NULL;
  B->peso[4] = -1;
  B->adjacente[5] = NULL;
  B->peso[5] = -1;
  B->pre = NULL;
  B->dist = 0;

  C->nome = "C";
  C->adjacente[0] = A;
  C->peso[0] = 3;
  C->adjacente[1] = B;
  C->peso[1] = 10;
  C->adjacente[2] = D;
  C->peso[2] = 6;
  C->adjacente[3] = F;
  C->peso[3] = 4;
  C->adjacente[4] = G;
  C->peso[4] = 5;
  C->adjacente[5] = H;
  C->peso[5] = 7;
  C->pre = NULL;
  C->dist = 0;

  D->nome = "D";
  D->adjacente[0] = C;
  D->peso[0] = 6;
  D->adjacente[1] = E;
  D->peso[1] = 6;
  D->adjacente[2] = H;
  D->peso[2] = 3;
  D->adjacente[3] = NULL;
  D->peso[3] = -1;
  D->adjacente[4] = NULL;
  D->peso[4] = -1;
  D->adjacente[5] = NULL;
  D->peso[5] = -1;
  D->pre = NULL;
  D->dist = 0;

  E->nome = "E";
  E->adjacente[0] = A;
  E->peso[0] = 8;
  E->adjacente[1] = D;
  E->peso[1] = 6;
  E->adjacente[2] = H;
  E->peso[2] = 5;
  E->adjacente[3] = NULL;
  E->peso[3] = -1;
  E->adjacente[4] = NULL;
  E->peso[4] = -1;
  E->adjacente[5] = NULL;
  E->peso[5] = -1;
  E->pre = NULL;
  E->dist = 0;

  F->nome = "F";
  F->adjacente[0] = A;
  F->peso[0] = 3;
  F->adjacente[1] = B;
  F->peso[1] = 6;
  F->adjacente[2] = C;
  F->peso[2] = 4;
  F->adjacente[3] = NULL;
  F->peso[3] = -1;
  F->adjacente[4] = NULL;
  F->peso[4] = -1;
  F->adjacente[5] = NULL;
  F->peso[5] = -1;
  F->pre = NULL;
  F->dist = 0;

  G->nome = "G";
  G->adjacente[0] = A;
  G->peso[0] = 4;
  G->adjacente[1] = C;
  G->peso[1] = 5;
  G->adjacente[2] = NULL;
  G->peso[2] = -1;
  G->adjacente[3] = NULL;
  G->peso[3] = -1;
  G->adjacente[4] = NULL;
  G->peso[4] = -1;
  G->adjacente[5] = NULL;
  G->peso[5] = -1;
  G->pre = NULL;
  G->dist = 0;

  H->nome = "H";
  H->adjacente[0] = C;
  H->peso[0] = 7;
  H->adjacente[1] = D;
  H->peso[1] = 3;
  H->adjacente[2] = E;
  H->peso[2] = 5;
  H->adjacente[3] = NULL;
  H->peso[3] = -1;
  H->adjacente[4] = NULL;
  H->peso[4] = -1;
  H->adjacente[5] = NULL;
  H->peso[5] = -1;
  H->pre = NULL;
  H->dist = 0;

  VAZIO->nome = "VAZIO";

  Lista * grafo = NULL;
  grafo = (Lista*) malloc(sizeof(Lista));

  grafo->vertice = A;
  grafo->proximo = (Lista*) malloc(sizeof(Lista));

  grafo->proximo->vertice = B;
  grafo->proximo->proximo = (Lista*) malloc(sizeof(Lista));

  grafo->proximo->proximo->vertice = C;
  grafo->proximo->proximo->proximo = (Lista*) malloc(sizeof(Lista));

  grafo->proximo->proximo->proximo->vertice = D;
  grafo->proximo->proximo->proximo->proximo = (Lista*) malloc(sizeof(Lista));

  grafo->proximo->proximo->proximo->proximo->vertice = E;
  grafo->proximo->proximo->proximo->proximo->proximo = (Lista*) malloc(sizeof(Lista));
  
  grafo->proximo->proximo->proximo->proximo->proximo->vertice = F;
  grafo->proximo->proximo->proximo->proximo->proximo->proximo = (Lista*) malloc(sizeof(Lista));
  
  grafo->proximo->proximo->proximo->proximo->proximo->proximo->vertice = G;
  grafo->proximo->proximo->proximo->proximo->proximo->proximo->proximo = (Lista*) malloc(sizeof(Lista));
  
  grafo->proximo->proximo->proximo->proximo->proximo->proximo->proximo->vertice = H;
  grafo->proximo->proximo->proximo->proximo->proximo->proximo->proximo->proximo = (Lista*) malloc(sizeof(Lista));

  grafo->proximo->proximo->proximo->proximo->proximo->proximo->proximo->proximo->vertice = VAZIO;
  grafo->proximo->proximo->proximo->proximo->proximo->proximo->proximo->proximo->proximo = NULL;
  
  return grafo;
}

void listar(Lista * grafo){
  Lista * atual = grafo;
  while(atual != NULL){
    if (atual->proximo == NULL){ 
      printf("%s", atual->vertice->nome);
    } else {
      printf("%s - ", atual->vertice->nome);
    }
    
    atual = atual->proximo;
  }
}

Lista * reduzir(Lista * cabeca){
  if (cabeca == NULL){
    return NULL;
  }

  Lista * frente = cabeca;
  cabeca = cabeca->proximo;
  frente->proximo = NULL;

  if (frente == cabeca){
    cabeca = NULL;
  }
  
  free(frente);
  return cabeca;
}

Lista * criar(Lista * proximo, Vertice * vertice){
	Lista * novo = (Lista*) malloc(sizeof(Lista));

  if(novo == NULL){
    printf("\nerr 2: Erro ao criar nó\n");
  }
  
	novo->vertice = vertice;
	novo->proximo = proximo;
	
	return novo;
}

Lista * preceder(Lista * cabeca, Vertice * vertice){
  Lista * novo = criar(cabeca, vertice);
  cabeca = novo;
  
  return cabeca;
}

Lista * acrescentar(Lista * cabeca, Vertice * vertice) {
    Lista * atual = cabeca;
    
    while (atual->proximo != NULL) {
        atual = atual->proximo;
    }

    Lista * novo = criar(NULL, vertice);
    atual->proximo = novo;

    return cabeca;
}

Lista * inserir(Lista * cabeca, Vertice * vertice){
  if (cabeca == NULL) {
    cabeca = preceder(cabeca, vertice);
    
    return cabeca;
  } else {
    cabeca = acrescentar(cabeca, vertice);
    
    return cabeca;
  }
}