<?php

$tabuleiro = explode(" ", trim(fgets(STDIN, 1000)));
$pecas = [1, 1, 2, 2, 2, 8];

foreach($tabuleiro as $key => $value) {
  echo ($pecas[$key] - $tabuleiro[$key]) . " ";
}
