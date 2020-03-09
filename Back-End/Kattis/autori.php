<?php

$arrayNome = explode("-", fgets(STDIN, 1000));

foreach ($arrayNome as $nome) {
    echo $nome[0];
}
