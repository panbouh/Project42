#!/usr/bin/php
<?php
    function is_alpha($a)
    {
        if (($a >= "a" && $a <= "z") || ($a >= "A" && $a <= "Z"))
            return (true);
        else
            return (false);
    }

    if (is_alpha("1"))
        echo "aaaa\n";
?>