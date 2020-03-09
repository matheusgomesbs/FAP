<?php
$entrada = explode(" ", trim(fgets(STDIN, 1000)));

echo $entrada[1] + ($entrada[1] - $entrada[0]);
