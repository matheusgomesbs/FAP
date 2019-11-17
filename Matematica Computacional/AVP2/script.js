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
    /**
     * a01 a11 a12 | a10 a11
     * b20 b21 b22 | b20 b21
     * c30 c31 c32 | c30 c31
     */

    matriz.forEach((elementoMatriz, indexMatriz) => {
      for(let i = 0; i < elementoMatriz.length; i++){        
        console.log("a"+indexMatriz+i);
      }
    });

    //return matriz;
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

    // escalonamento automatico
    for(let m = 0; m < matriz.length; m++){
      // evita que o pivo seja zero com if ternario   
      pivo = (matriz[m][0] === 0) ? (matriz[m][1] === 0) ? matriz[m][2] : matriz[m][1] : matriz[m][0];
       
      // salva os pivores a matriz
      this.pivoAcumulator.push(pivo);
      // acessa cada linha da matriz
      matriz.forEach((el, index) => {
        matrizC[m] = matriz[m];
        // exclui o pivo do escalonamento
        if(matriz[m] !== matriz[index]) {
          // escalonamento
          for(let i = 0; i < el.length; i++) {
            // (pivo * el[i]) + (matriz[index][m] * matriz[m][i])
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

//let matriz = [[4,-3,2, 7],[-2,2,-2, -2],[3,4,4, 9]];
let matriz = [[4,-3,2],[-2,2,-2],[3,4,4]];

//console.log(projeto.sistemaLinear(matriz));
//console.table(projeto.determinante(matriz));
