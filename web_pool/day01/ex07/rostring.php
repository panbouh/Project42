#!/usr/bin/php
<?php
    if ($argc < 2)
        return (false);

    function epur_str($str)
    {
        $str = trim($str);
        $new = "";
        for ($i = 0, $y = 0; $str[$i]; $i++)
        {
            $new[$y++] = $str[$i];
            while ($str[$i] && $str[$i] === " " && $str[$i + 1] === " ")
                $i++;
        }
        return ($new);
    }

    $str = $argv[1];
    $i = 0;

    while ($str[$i] && $str[$i] != ' ')
        $i++;

    $cut = substr($str, 0, $i);
    $begin = substr($str, $i + 1, strlen($str) - $i);
    $new = $begin." ".$cut;
    echo (epur_str($new))."\n";
    
?>