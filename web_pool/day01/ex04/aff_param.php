#!/usr/bin/php
<?php
    if ($argc < 2)
        return (false);
    $i = 0;
    foreach ($argv as $str)
    {
        if ($i > 0)
            echo "$str\n";
        $i++;
    }
    return (true);
?>