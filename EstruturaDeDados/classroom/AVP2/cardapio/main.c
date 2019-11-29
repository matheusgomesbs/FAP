#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//defines
#define MAXITENS 20

// estrutura
struct Item {
  int codigo;
  char nome[50];  
  float valor;
  char ingredientes[50];

} item[MAXITENS];

// prototipo
void menu();
void cadastrar();
void cadastrarItem(struct Item cItem);
void editar();
void deletar();
void menuListagem();
void listar();
void filtrar(int order);
void limparTela();
void mensagem(char msg[]);

//variaveis
int opcaoMenu;
int opcaoMenuListagem;
int qtdItens;

int main(void) {
  menu();
  return 0;
}

void menu() {
  printf("|========================================|");
  printf("\n%2s Menu principal\n","");
  printf("|========================================|");
  printf("\n1 - Cadastrar itens");
  printf("\n2 - Editar itens");
  printf("\n3 - Deletar itens");
  printf("\n4 - Listar itens");
  printf("\n5 - Limpar tela");
  printf("\n6 - Sair");
  printf("\n");
  scanf("%d", &opcaoMenu);
  
  switch(opcaoMenu){
    case 1:
      printf("|========================================|");
      printf("\n%2s Cadastro de itens\n","");
      printf("|========================================|");   
      cadastrar();
    break;
    case 2:
      printf("|========================================|");
      printf("\n%2s Edição de itens\n","");
      printf("|========================================|");  
      editar();
    break;
    case 3:
      printf("|========================================|");
      printf("\n%2s Exclusão de itens\n","");
      printf("|========================================|");  
      deletar();
    break;
    case 4:
      menuListagem();
    break;
    case 5:
      limparTela();
    break;
    case 6:
      limparTela();
      mensagem("\n\nAVISO ==> Você saiu do sistema, volte sempre!\n\n");
      exit(0);
    default:
      limparTela();
      mensagem("\n\nERRO ==> Valor informado incorreto!\n\n");
    break;
  }
  
  menu();
}

void cadastrar() {
  char continuar;
  do{
    if(qtdItens < MAXITENS) {
      fflush(stdin);
      mensagem("\nInforme o nome: ");
      getchar();
      fgets(item[qtdItens].nome, 50, stdin);    
      mensagem("Informe o valor: ");
      scanf("%f", &item[qtdItens].valor);
      mensagem("Informe os ingredientes: ");
      getchar();
      fgets(item[qtdItens].ingredientes, 50, stdin);

      cadastrarItem(item[qtdItens]);
      mensagem("\n\nSUCESSO ==> Item cadastrado com sucesso!\n\n");
    } else {
      mensagem("\n\nAVISO ==> Limite de itens atingido!\n\n");
    }

    mensagem("\nDeseja cadastrar outro item? S/N: ");
    scanf("%s", &continuar);
  } while(continuar == 's' || continuar == 'S');
}

void cadastrarItem(struct Item cItem) {
  cItem.codigo = qtdItens + 1;
  item[qtdItens] = cItem;
  qtdItens++;
}

void editar() {
  int codigoItem;
  char continuar;

  do{    
    fflush(stdin);
    mensagem("\nInforme o código do item: ");
    scanf("%d", &codigoItem);
    //verificar se existe
    if(item[codigoItem - 1].codigo != 0) {
      mensagem("\nInforme o nome: ");
      getchar();
      strcpy(item[codigoItem - 1].nome, fgets(item[codigoItem - 1].nome, 50, stdin));
      mensagem("Informe o valor: ");
      scanf("%f", &item[codigoItem - 1].valor);
      mensagem("Informe os ingredientes: ");
      getchar();
      strcpy(item[codigoItem - 1].ingredientes, fgets(item[codigoItem - 1].ingredientes, 50, stdin));
      mensagem("\n\nSUCESSO ==> Item editado com sucesso!\n\n");
    } else {
      mensagem("\n\nAVISO ==> Item não encontrado!\n\n");
    }

    mensagem("\nDeseja editar outro item? S/N: ");
    scanf("%s", &continuar);
  } while(continuar == 's' || continuar == 'S');
}

void deletar() {
  if(qtdItens > 0) {
  int i, cont = 0, codigo_item;

	mensagem("\nInforme o Codigo do Produto que se Deseja Excluir: ");

	scanf("%i",&codigo_item);
	for(i = 0 ; i < qtdItens; i++){
		if (item[i].codigo == codigo_item) {
			item[i] = item[i+1];
      qtdItens--;
      cont++;
		}
	}

	if(cont > 0){
    mensagem("SUCESSO ==> O item foi excluído com sucesso!\n\n");
    mensagem("Pressione ENTER Para Continuar...\n\n");
    setbuf(stdin,NULL);
    getchar ();
    limparTela();
  } else {  
    mensagem("\nAVISO ==> Esse item não existe.\n\n");
  }
  } else {
    mensagem("\nAVISO ==> Não existem itens para deletar.\n\n");
  }
}

void menuListagem() {
  if(qtdItens > 0) {
    printf("\n");
    printf("|========================================|");
    printf("\n%2s Menu Listagem\n","");
    printf("|========================================|");
    printf("\n1 - Listar em ordem crescente");
    printf("\n2 - Listar em ordem decrescente");
    printf("\n3 - Limpar tela");
    printf("\n4 - Voltar");
    printf("\n");
    scanf("%d", &opcaoMenuListagem);
    
    switch(opcaoMenuListagem){
      case 1:
        printf("|========================================|");
        printf("\n%2s Listando itens em ordem crescente\n","");
        printf("|========================================|");
        filtrar(0);
        listar();
      break;
      case 2:
        printf("|========================================|");
        printf("\n%2s Listando itens em ordem decrescente\n","");
        printf("|========================================|");  
        filtrar(1);
        listar();
      break;
      case 3:
        limparTela();
      break;
      case 4:
        menu();
      default:
        limparTela();
        mensagem("ERRO ==> Valor informado incorreto!\n\n");
      break;
    }
    
    menuListagem(); 
  }
  else {
    mensagem("\n\nAVISO ==> Nenhum item cadastrado.\n\n");
  }
}

void listar() {
  for(int i = 0; i < qtdItens; i++) {
    printf("\nCódigo: %d", item[i].codigo);
    printf("\nNome: %s", item[i].nome);
    printf("\nValor: %.2f", item[i].valor);
    printf("\nIngredientes: %s", item[i].ingredientes);
    printf("\n------------------------------------------");
  }
}

void filtrar(int order) {
  int min = 0;
  struct Item tmpItem;

  for(int i = 0; i < qtdItens; i++) {
    min = i;
    
    for(int j = i + 1; j < qtdItens; j++){
      if( (order == 1 && item[j].valor > item[min].valor) || (order == 0 && item[j].valor < item[min].valor) ) {
        min = j;
      }
    }

    if(min != i) {
      tmpItem = item[min];
      item[min] = item[i];
      item[i] = tmpItem;
    }
  }
}


void limparTela() {
  //printf("\e[2J\e[0;0H");
  system("clear || cls");
}

void mensagem(char msg[]) {
  printf("%s", msg);
}
