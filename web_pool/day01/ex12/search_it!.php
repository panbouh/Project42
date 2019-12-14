#!/usr/bin/php
<?php
    if ($argc < 2)
        return (false);

    $keyOne = $argv[1];

    unset($argv[0]);
    unset($argv[1]);

    foreach ($argv as $elem)
    {
        list($key, $val) = explode(':', $elem);
        if ($keyOne === $key)
            $result = $val;

    }
    if (isset($result))
        echo "$result\n";
?>