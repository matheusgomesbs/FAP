<?php
$sentenca = trim(fgets(STDIN, 1000));

$palavras = explode(" ", $sentenca);
$arr = array_count_values($palavras);

foreach($arr as $valor) {
  if($valor > 1) {
    echo "no";
    return;
  }
}

echo "yes";
