<?php
$data = explode(' ', fgets(STDIN, 1000));

if($data[0] == "DEC" && $data[1] == 25 || $data[0] == "OCT" && $data[1] == 31) {
    echo "yup";
} else {
  echo "nope";
}
