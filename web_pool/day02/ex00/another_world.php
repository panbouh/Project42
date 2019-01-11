#!/usr/bin/php
<?php
    if ($argc != 2)
        {echo "\n";return (false);}
    
    $str = trim($argv[1]);
    $str = preg_replace("/[[:blank:]]+/", " ", $str);
    echo "$str\n";
?>