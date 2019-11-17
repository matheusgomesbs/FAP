let projeto = {
  pivoAcumulator: [],
  
  somarMatriz: function(matrizA, matrizB) {
    let matrizC = this.matrizPadrao(matrizA);

    matrizA.forEach((elementoMatriz, indexMatriz) => {
      for(let i = 0; i < elementoMatriz.length; i++){
        matrizC[indexMatriz][i] = this.somar(matrizA[indexMatriz][i], matrizB[indexMatriz][i]);
      }
    });

    return matrizC;
  },

  multiplicarMatriz: function(matrizA, matrizB) {
    let matrizC = this.matrizPadrao(matrizA);

    for (let i = 0; i < matrizA.length; i++) {      
      for (let j = 0; j < matrizB.length; j++) {
        let soma = 0;
        for (let k = 0; k < matrizA[0].length; k++) {
          soma += this.multiplicar(matrizA[i][k], matrizB[k][j]);
        }
        matrizC[i][j] = soma;
      }      
    }

    return matrizC;
  },

  determinante: function(matriz) {
    if(matriz.length==2){
      let det = (matriz[0][0] * matriz[1][1]) - (matriz[1][0] * matriz[0][1]);

      return det;
    }

    let soma = 0;
    for(let i = 0; i < matriz.length; i++){
        let tmp = this.criarMAtriz(matriz.length-1);
        for(let j = 0; j < matriz.length; j++){
            if(j != i){
                for(let k = 1; k < matriz.length; k++){
                    let indice = -1;
                    if(j < i){
                      indice = j;
                    } else if(j > i){
                      indice = j-1;
                    }
                    tmp[indice][k-1] = matriz[j][k];
                }
            }
        }
        if(i % 2 == 0){  
          soma += matriz[i][0] * this.determinante(tmp);                            
        }                            
        else{                            
          soma -= matriz[i][0] * this.determinante(tmp);
        }                        
      }
    
    return soma;
  },

  criarMAtriz: function(size){
    var matriz = new Array(size);
    for (i = 0; i < size ; i++){ 
      matriz[i] = new Array(size); 
    } 
    return matriz;
  },

  matrizSingular: function(matriz) {
    return (this.determinante(matriz) === 0) ? true : false;
  },

  sistemaLinear: function(matriz) {
    matriz = this.gaussJordan(matriz);
    let matrizC = this.matrizPadrao(matriz);

    matriz.forEach((elementoMatriz, indexMatriz) => {
      for(let i = 0; i < elementoMatriz.length; i++){
        if(matriz[indexMatriz][i] === 0 && elementoMatriz[indexMatriz] === 0 ){
          matrizC[indexMatriz][i] = 0;
        } else {
          matrizC[indexMatriz][i] = this.dividir(matriz[indexMatriz][i], elementoMatriz[indexMatriz]);
        }
      }
    });
    
    matriz = [matrizC[0][3], matrizC[1][3], matrizC[2][3]];

    return matriz;
  },

  gaussJordan: function(matriz) {  
    matriz = this.escalonar(matriz);    
    
    return matriz;
  },

  escalonar: function(matriz){
    let matrizC = this.matrizPadrao(matriz);
    let pivo = matriz[0][0];

    for(let m = 0; m < matriz.length; m++){
      pivo = (matriz[m][0] === 0) ? (matriz[m][1] === 0) ? matriz[m][2] : matriz[m][1] : matriz[m][0];
      this.pivoAcumulator.push(pivo);
      matriz.forEach((el, index) => {
        matrizC[m] = matriz[m];
        if(matriz[m] !== matriz[index]) {
          for(let i = 0; i < el.length; i++) {
            matrizC[index][i] = Number(pivo * el[i]) + Number(this.mudarSinal(matriz[index][m]) * matriz[m][i]);
          }
        }
      });

      matriz = matrizC;
      matrizC = this.matrizPadrao(matriz);
    }

    return matriz;
  },

  matrizPadrao: function (matriz, valorPadrao = 0) { 
    return Array(matriz.length).fill(0).map(() => {
      return Array(matriz[0].length).fill(valorPadrao)
    });
  },

  somar: function(primeiroValor, segundoValor) {
    return parseInt(primeiroValor) + parseInt(segundoValor);
  },

  multiplicar: function(primeiroValor, segundoValor) {
    return parseInt(primeiroValor) * parseInt(segundoValor);
  },

  dividir: function(primeiroValor, segundoValor) {
    return parseInt(primeiroValor) / parseInt(segundoValor);
  },

  mudarSinal: function(valor) {
    return Number(valor * -1);
  }
}
