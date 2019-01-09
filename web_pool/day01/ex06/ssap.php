#!/usr/bin/php
<?php
    function get_param($av)
    {
        $new = [];
        $i = 0;
        foreach ($av as $str)
        {
            if ($i > 0)
                $new[] = $str;
            $i++;
        }
        return ($new);
    }

    function ft_split($str)
    {
        $new = explode(" ", $str);
        $new = array_filter($new);
        sort($new);
        return ($new);
    }

    $new_str = implode(' ', get_param($argv));
    $new_tab = ft_split($new_str);
    foreach ($new_tab as $str)
        echo "$str\n";
?>