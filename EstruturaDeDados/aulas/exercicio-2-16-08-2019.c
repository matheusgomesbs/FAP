#include <stdio.h>

void adicionarProduto();
void montarTabela(char *nome, float preco, int quantidade);
void showRows(char *caracter, int quantidade);

struct produtos {
  char *nome;
  float preco;
  int quantidade;
};

int main() {
  int continuar = 0;
  
  while(continuar == 0){
    adicionarProduto();

    printf("Adicionar mais produtos? 1 - Sim | 2 - Não");
    scanf("%d", &continuar);
  }

  return 0;
}

void adicionarProduto(){
  struct produtos produto;

  printf("Informe o nome: \n");
  scanf("%s", &produto.nome);
  printf("Informe o preço: \n");
  scanf("%f", &produto.preco);
  printf("Informe a quantidade: \n");
  scanf("%d", &produto.quantidade);

  montarTabela(produto.nome, produto.preco, produto.quantidade);
}

void montarTabela(char *nome, float preco, int quantidade) {
  showRows("-", 60);
  printf("Produto \t Preço Unitário \t Quantidade \t Preço Total\n");
  showRows("-", 60);
  printf("%s \t", nome);
  printf("%.2f \t", preco);
  printf("%d \t", quantidade);
  printf("%.2f \t\n", (quantidade * preco));
}

void showRows(char *character, int quantity){
  int i;
  for(i = 0; i < quantity; i++)
    printf("%s", character);
  printf("\n");
}