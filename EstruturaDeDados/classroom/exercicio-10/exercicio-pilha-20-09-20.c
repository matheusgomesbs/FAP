#include <stdio.h>
#include <string.h>

#define TAMANHO 10

typedef struct {
  int topo;
  char dado[TAMANHO];
} Pilha;

void inicia(Pilha *p) {
  p->topo = -1;
}

int cheia (Pilha *p) {
  return (p->topo == TAMANHO -1);
}

int vazia(Pilha *p) {
  return (p->topo == -1);
}

int empilhar(Pilha *p, char val) {
  if (cheia(p)){
    return 0; // Pilha cheia
  }

  p->dado[++p->topo]=val;

  return 1;
}

int desempilhar(Pilha *p, char *val) {
  if (vazia(p)){
    return 0; // Pilha vazia
  }

  *val = p->dado[p->topo--];

  return 1;
}

void imprime(Pilha p) {
  int i;
  for(i = p.topo; i >= 0; i--) {
    printf("[ %d ]\n", p.dado[i]);
  }
}

int main() {
  Pilha elemento;
  char palavra[TAMANHO], inversa[TAMANHO];

  printf("Digite uma palavra: ");
  scanf("%s", palavra);

  inicia(&elemento);
  
  int i;
  for(i = 0; i < strlen(palavra); i++) {
    empilhar(&elemento, palavra[i]);
  }

  i = 0;

  while(!vazia(&elemento)) {
    desempilhar(&elemento, &inversa[i]);

    i++;
  }

  inversa[i] = '\0'; //terminador de string -> \0

  if(strcmp(palavra, inversa) == 0) {
    printf("\nÉ Palindromos: %s == %s\n", palavra, inversa);
  } else {
    printf("\nNão são Palindromos: %s != %s\n", palavra, inversa);
  }
}
