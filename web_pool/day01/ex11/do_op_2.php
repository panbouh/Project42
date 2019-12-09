#!/usr/bin/php
<?php
    if ($argc != 2)
        {echo "Incorrect Parameters\n"; return (false);}

    function get_op($str)
    {
        $i = 0;
        while (strpos('/*-+%', $str[$i]) === false)
            $i++;
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
        $i = -1;
        for (42; isset($end[$i]) && !is_numeric($end[$i]); $i++)
        {
            echo "coucou\n";
            if (strpos('/*-+%', $end[$i]) === true)
                return (false);
        }
        while (isset($end[$i]))
        {
            if (strpos('0123456789', $end[$i]) === false)
                return (false);
            $i++;
        }
        return (intval($end));
    }
    // ----------------------------------------------------------------------- //

    $str = epur_str($argv[1]);
    for ($i = 0; isset($str[$i]); $i++)
    {
        if (strpos('/*-+% 1234567890', $str[$i]) === false)
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