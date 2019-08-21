#include <stdio.h>
float altura;
char sexo[1];

void pessoa();

int main() {
  pessoa();
  
  return 0;
}

void pessoa(){
  int continuar = 1, contador = 0, homens = 0, mulheres = 0;
  float mediatotal = 0, maiorAltura = 0, ultimaAltura = 0, mediaMulheres = 0, mediaHomens = 0;

  while(continuar == 1){
    printf("Informe seu sexo e altura:\n");
    scanf("%s %f", sexo, &altura);

    mediatotal += altura;

    if(*sexo == 'm' || *sexo == 'M'){      
      mediaHomens += altura;
      homens++;
    } else if (*sexo == 'f' || *sexo == 'F'){
      mediaMulheres += altura;
      mulheres++;
    }

    if(ultimaAltura < altura){
      maiorAltura = altura;
    }

    ultimaAltura = altura;
    
    printf("Adicionar mais uma pessoa? 1 - Sim \t 2 - Não\n");
    scanf("%d", &continuar);
    
    contador++;
  }

  printf("Altura média das %d pessoas: %.2f \n", contador, (mediatotal/contador));
  printf("Maior altura encontrada: %.2f \n", maiorAltura);
  printf("Altura média das %d mulheres: %.2f \n", mulheres, (mediaMulheres/mulheres));
  printf("Altura média dos %d homens: %.2f \n", homens, (mediaHomens/homens));
  printf("Quantidade de homens: %d", homens);
}