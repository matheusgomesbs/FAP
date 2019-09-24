#include <stdio.h>

/*
* Exercicio 3
* Tabela de produtos
*/
int main() {
  float banana_preco = 2.50, banana_quantidade = 2;
  float uva_preco = 6.50, uva_quantidade = 6;
  float pessego_preco = 10.22, pessego_quantidade = 10;
  float sub_total;

  printf("Produto | Preço Unitário | Quantidade | Preço Total\n");
  printf("Banana  | %14.2f | %10.2f | %11.2f\n", banana_preco, banana_quantidade, (banana_preco * banana_quantidade));
  printf("Uva     | %14.2f | %10.2f | %11.2f\n", uva_preco, uva_quantidade, (uva_preco * uva_quantidade));
  printf("Pessego | %14.2f | %10.2f | %11.2f\n", pessego_preco, pessego_quantidade, (pessego_preco * pessego_quantidade));
  sub_total = (banana_preco * banana_quantidade) + (uva_preco * uva_quantidade) + (pessego_preco * pessego_quantidade);
  printf("%8s|%16s|%1s Sub-Total | %11.2f\n","","","", sub_total);
  printf("%8s| Imposto (5%) %15s| %11.2f\n","","", (sub_total*0.05));
  printf("%8s|%16s|%6s Total| %11.2f\n", "", "", "", sub_total + (sub_total*0.05));

  return 0;
}
