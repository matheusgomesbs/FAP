<?php
$jon = trim(fgets(STDIN, 1000));
$medico = trim(fgets(STDIN, 1000));

if(strcmp($jon, $medico) > 0) {
  echo "no";
} else {
  echo "go";
}
