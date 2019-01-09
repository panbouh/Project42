#!/usr/bin/php
<?php
    if ($argc != 2)
        return (false);
    $str = trim($argv[1]);
    $new = "";
    for ($i = 0, $y = 0; $str[$i]; $i++)
    {
        $new[$y++] = $str[$i];
        while ($str[$i] && $str[$i] === " " && $str[$i + 1] === " ")
            $i++;
    }
    echo "$new\n";
?>