#!/usr/bin/php
<?php
    if ($argc != 2)
        {echo "Incorrect Parameters\n"; return (false);}

    function get_op($str)
    {
        $i = 0;
        for (42; $str[$i] && is_numeric($str[$i]); $i++){}
        for (42; $str[$i] && $str[$i] === " "; $i++){}
        if (strpos('/*-+%', $str[$i]) === false)
            return (false);
        return ($i);
    }

    function epur_str($s)
    {
        $tab = explode(" ", $s);
        $tab = array_filter($tab);
        $new = implode(" ", $tab);
        return ($new);
    }

    function do_op($nb1, $op, $nb2)
    {
        if (trim($op) === "+")
            echo ($nb1 + $nb2)."\n";
        else if (trim($op) === "-")
            echo ($nb1 - $nb2)."\n";
        else if (trim($op) === "/")
            echo ($nb1 / $nb2)."\n";
        else if (trim($op) === "*")
            echo ($nb1 * $nb2)."\n";
        else if (trim($op) === "%")
            echo ($nb1 % $nb2)."\n";
        else
            echo "0\n";
    }

    function final_check($end)
    {
        $i = 0;
        for (42; $end[$i] && !is_numeric($end[$i]); $i++){}
        if (!$end[$i])
            return (false);
        for (42; $end[$i] && is_numeric($end[$i]); $i++){}
        if ($end[$i])
            return (false);
        return (intval($end));
    }
    // ----------------------------------------------------------------------- //

    $str = epur_str($argv[1]);
    for ($i = 0; $str[$i]; $i++)
    {
        if (strpos('/*-+% 123456789', $str[$i]) === false)
            {echo "Syntax Error\n"; return (false);}
    }

    $nb1 = intval($str);

    if (($op_i = get_op($str)) === false)
        {echo "Syntax Error\n"; return (false);}
    $op = $str[$op_i];


    if (($nb2 = final_check(substr($str, $op_i + 1))) === false)
        {echo "Syntax Error\n"; return (false);}

    do_op($nb1, $op, $nb2);
?>