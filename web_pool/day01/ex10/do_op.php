#!/usr/bin/php
<?php
    if ($argc != 4)
        {echo "Incorrect Parameters\n"; return (false);}
    
    $nb1 = intval($argv[1]);
    $nb2 = intval($argv[3]);

    if (trim($argv[2]) === "+")
        echo ($nb1 + $nb2)."\n";
    else if (trim($argv[2]) === "-")
        echo ($nb1 - $nb2)."\n";
    else if (trim($argv[2]) === "/")
        echo ($nb1 / $nb2)."\n";
    else if (trim($argv[2]) === "*")
        echo ($nb1 * $nb2)."\n";
    else if (trim($argv[2]) === "%")
        echo ($nb1 % $nb2)."\n";
    else
        echo "0\n";
?>