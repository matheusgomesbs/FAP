window.onload = event => {
  //pegarElemento("input").forEach(el => { el.value = Math.ceil(Math.random() * 10); });
  pegarElemento(".limpar", false).onclick = () => { pegarElemento('.content', false).innerHTML = ''; };

  let form = pegarElemento(".formMatriz", false);
  let formSistemaLinear = pegarElemento(".formSistemaLinear", false);
  let addColumn = pegarElemento('.addColumn', false);
  let removeColumn = pegarElemento('.removeColumn', false);

  formSistemaLinear.onclick = (e) => {
    e.preventDefault();
    let campos = pegarElemento(".formSistemaLinear input[name*='s-']");
    let matriz = matrizQuadrada(3);
    let acao = e.target.dataset.action;

    matriz = preencherMatriz(campos, matriz);

    resultado = executarAcoes(acao, matriz);
    modalShow(`S = {${resultado}}`);

    return false;
  }

  form.onclick = (e) => {
    let camposA = pegarElemento(".formMatriz input[name*='a-']");
    let matrizA = matrizQuadrada(pegarElemento(".formMatriz input[name*='a-0-']").length);
    let camposB = pegarElemento(".formMatriz input[name*='b-']");
    let matrizB = matrizQuadrada(pegarElemento(".formMatriz input[name*='b-0-']").length);
    let acao = e.target.dataset.action;

    matrizA = preencherMatriz(camposA, matrizA);
    matrizB = preencherMatriz(camposB, matrizB);

    resultado = executarAcoes(acao, matrizA, matrizB);

    switch (acao) {
      case 'detA':
        modalShow("O determinante de A é " + resultado);
        break;
      case 'detB':
        modalShow("O determinante de B é " + resultado);
        break;
      case 'singA':
        modalShow(`A matriz <strong> A ${(resultado) ? 'é' : 'não é'}</strong> singular.`);
        break;
      case 'singB':
        modalShow(`A matriz <strong> B ${(resultado) ? 'é' : 'não é'}</strong> singular.`);
        break;
      default:
        mostrarResultadoTable(resultado);
        break;
    }

    if (acao !== 'detA' || acao !== 'detB' || acao !== 'singA' || acao !== 'singB') {
      var target = "#resultado";
      var scrollToPosition = $(target).offset().top - 200;

      $('html,body').animate({ 'scrollTop': scrollToPosition }, 600, function () {
        window.location.hash = target;
      });
    }

    return false;
  };

  function modalShow(text) {
    let modal = $('.modal');

    modal.on('show.bs.modal', e => {
      modal.find('.modal-body').html(text);
    });

    modal.modal('show');
  }

  function mostrarResultadoTable(resultado) {
    let content = `<table class="table col-3 mr-2">`;
    content += `<thead class="table-dark text-center"><td colspan="${resultado.length}">Resultado</td></thead>`;
    resultado.forEach(itens => {
      content += `<tr>`;
      itens.forEach(item => {
        content += `<td>${item}</td>`;
      });
      content += `</tr>`;
    });

    content += `</table>`;

    $('.content').prepend(content);
  }

  function executarAcoes(acao, matrizA, matrizB) {
    switch (acao) {
      case 'somar':
        resultado = projeto.somarMatriz(matrizA, matrizB);
        break;
      case 'multiplicar':
        resultado = projeto.multiplicarMatriz(matrizA, matrizB);
        break;
      case 'detA':
        resultado = projeto.determinante(matrizA);
        break;
      case 'detB':
        resultado = projeto.determinante(matrizB);
        break;
      case 'singA':
        resultado = projeto.matrizSingular(matrizA);
        break;
      case 'singB':
        resultado = projeto.matrizSingular(matrizB);
        break;
      case 'sistemaLinear':
        resultado = projeto.sistemaLinear(matrizA);
        break;
    }

    return resultado;
  }

  function preencherMatriz(campos, matriz) {
    campos.forEach((element, index) => {
      let row = element.dataset.row;
      let column = element.dataset.column;

      matriz[row][column] = parseInt(element.value);
    });

    return matriz;
  }

  function matrizQuadrada(LinhaColuna) {
    let matriz = new Array;

    for (let i = 0; i < LinhaColuna; i++) {
      matriz[i] = [];
      for (let j = 0; j < LinhaColuna; j++) {
        matriz[i][j] = 0;
      }
    }

    return matriz;
  }

  function pegarElemento(element, all = true) {
    if (all) {
      return document.querySelectorAll(element);
    } else {
      return document.querySelector(element);
    }
  }

  function insertColumn() {
    let itens = pegarElemento('#matrizA tr');
    if (itens.length < 4) {
      let tr = `<tr class="el-${itens.length}">`;
      tr += `
      <td><input type="number" class="form-control" name="a-${itens.length}-0" data-row="${itens.length}" data-column="0" required></td>
      <td><input type="number" class="form-control" name="a-${itens.length}-1" data-row="${itens.length}" data-column="1" required></td>
      <td><input type="number" class="form-control" name="a-${itens.length}-2" data-row="${itens.length}" data-column="2" required></td>
      `;
      tr += `</tr>`;

      $("#matrizA").append(tr);
      $("#matrizA tr").each((el) => {
        let td = `<td><input type="number" class="form-control" name="a-${el}-${itens.length}" data-row="${itens.length}" data-column="${el}" required></td>`;
        $("#matrizA .el-" + el).append(td);
      });
    } else {
      modalShow('Limite atingido!');
    }
  }

  function deleteColumn() {
    let itens = $('#matrizA tr');
    let trClass = itens.length - 1;

    if (itens.length > 2) {
      $("#matrizA .el-" + trClass).remove();
      itens.each(el => {
        $("#matrizA input[name*=a-" + el + "-" + trClass + "]").remove();
      });
    } else {
      modalShow('Limite atingido!');
    }
  }
};
