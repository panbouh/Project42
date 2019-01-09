#!/usr/bin/php
<?php
    if ($argc != 2)
        return (false);
    $tab = explode(" ", $argv[1]);
    $tab = array_filter($tab);
    $new = implode(" ", $tab);
    echo "$new\n";
?>