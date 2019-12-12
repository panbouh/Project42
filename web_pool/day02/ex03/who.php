#!/usr/bin/php
<?php

    function tty_sort($a, $b)
    {
        return (strcmp($a["tty"], $b["tty"]));
    }

    $date = "%b %e %H:%M";
    date_default_timezone_set('Europe/Paris');

    $utmpx_f = "/var/run/utmpx";

    $fd = fopen($utmpx_f, 'r');

    while ($file_bin = fread($fd, 628))
    {
        $file_trad[] = unpack("a256login/a4id/a32tty/ipid/itype/isec/imicro/a256host/i16pad", $file_bin);
    }
    fclose($fd);

    usort($file_trad, "tty_sort");

    foreach($file_trad as $block)
    {
        if ($block['type'] === 7)
        {
            echo $block['login'] . " " . $block['tty']  . "  ", strftime($date, $block['sec']), "\n";
        }
    }
?>