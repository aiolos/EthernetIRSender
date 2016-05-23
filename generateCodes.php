<?php

for ($i = 0; $i < 256; $i++) {
    $hex = dechex($i);
    $hex2 = dechex(255 - $i);
    echo strtoupper('40BF' . str_pad($hex, 2, 0, STR_PAD_LEFT) . str_pad($hex2, 2, 0, STR_PAD_LEFT)) . PHP_EOL;
}