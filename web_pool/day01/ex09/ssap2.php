#!/usr/bin/php
<?php
    if ($argc < 2)
        return (false);

    function is_alpha($a)
    {
        if (($a >= "a" && $a <= "z") || ($a >= "A" && $a <= "Z"))
            return (true);
        return (false);
    }

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

    function ft_sort($tab)
    {
        $alp = array();
        $mum = array();
        $spe = array();

        foreach ($tab as $line)
        {
            if (is_alpha($line[0]))
                $alp[] = $line;
            else if (is_numeric($line[0]))
                $num[] = $line;
            else
                $spe[] = $line;
        }
        // print_r($alp);
        // print_r($num);
        // print_r($spe);
        if ($alp)
            sort($alp, SORT_NATURAL | SORT_FLAG_CASE);
        if ($num)
            sort($num, SORT_STRING);
        if ($spe)
            sort($spe);
        // echo "------sorting-----------\n";
        // print_r($alp);
        // print_r($num);
        // print_r($spe);
        $new = array_merge((array)$alp, (array)$num, (array)$spe);
        return ($new);
    }

    function ft_split($str)
    {
        $new = explode(" ", $str);
        $new = array_filter($new);
        $new = ft_sort($new);
        // echo "------fnish-----------\n";
        // print_r($new);
        return ($new);
    }

    $new_str = implode(' ', get_param($argv));
    $new_tab = ft_split($new_str);
    foreach ($new_tab as $str)
        echo "$str\n";
?>