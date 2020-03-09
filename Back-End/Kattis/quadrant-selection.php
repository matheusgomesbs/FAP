<?php
$entradaX = trim(fgets(STDIN, 1000));
$entradaY = trim(fgets(STDIN, 1000));

if($entradaX > 0 && $entradaY > 0) {
  echo "1";
} else if ($entradaX < 0 && $entradaY > 0) {
  echo "2";
} else if ($entradaX < 0 && $entradaY < 0) {
  echo "3";
} else {
  echo "4";
}
