<?php
$jogador1 = explode(" ", trim(fgets(STDIN, 1000)));
$jogador2 = explode(" ", trim(fgets(STDIN, 1000)));
$jogador3 = explode(" ", trim(fgets(STDIN, 1000)));
$jogador4 = explode(" ", trim(fgets(STDIN, 1000)));
$jogador5 = explode(" ", trim(fgets(STDIN, 1000)));

$arr = [
  1 => array_sum($jogador1),
  2 => array_sum($jogador2),
  3 => array_sum($jogador3),
  4 => array_sum($jogador4),
  5 => array_sum($jogador5)
];

$vencedor = (array_keys($arr, max($arr))[0]);
$pontos = max($arr);

echo "{$vencedor} {$pontos}";
