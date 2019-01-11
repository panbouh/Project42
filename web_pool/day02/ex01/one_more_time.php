#!/usr/bin/php
<?php
    if ($argc != 2)
        {echo "\n";return (false);}

    function epur_str($s)
    {
        $str = trim($s);
        $str = preg_replace("/[[:blank:]]+/", " ", $str);
        return ($str);
    }
    
    function check_format($s)
    {
        if ((preg_match("/[a-zA-Z]{1}[a-z]+ [0-31]{1,2} [a-zA-Z]{1}[a-z]+ \d{4} [0-2][0-4](:[0-5][0-9]){2}/", $s)) === 0)
            return (FALSE);
        $day = array(
            'lundi',
            'mardi',
            'mercredi',
            'jeudi',
            'vendredi',
            'samedi',
            'dimanche',
        );
        $month = array(
            'janvier',
            'fevrier',
            'mars',
            'avril',
            'mai',
            'juin',
            'juillet',
            'aout',
            'septembre',
            'octobre',
            'novembre',
            'decembre',
        );

        $tab = explode(" ", $s);

        if (in_array(strtolower($tab[0]), $day) === FALSE)
            return (FALSE);

        if (intval($tab[1]) === 0)
            return (FALSE);
        
        if (in_array(strtolower($tab[2]), $month) === FALSE)
            return (FALSE);

        return (TRUE);
    }

    function super_translator_2000($s) 
    {
        $transWord = array  (
                                'janvier'=>'jan',
                                'février'=>'feb',
                                'mars'=>'march',
                                'avril'=>'apr',
                                'mai'=>'may',
                                'juin'=>'jun',
                                'juillet'=>'jul',
                                'août'=>'aug',
                                'septembre'=>'sep',
                                'octobre'=>'oct',
                                'novembre'=>'nov',
                                'décembre'=>'dec',
                                'lundi' => 'mon',
                                'mardi' => 'tue',
                                'mercredi' => 'web',
                                'jeudi' => 'thu',
                                'vendredi' => 'fri',
                                'samedi' => 'sat',
                                'dimanche' => 'sun',
                            );
        return (strtr(strtolower($s), $transWord));
    }
    date_default_timezone_set("Europe/Paris");

    $date = epur_str($argv[1]);

    if (check_format($date) === FALSE)
        {echo "Wrong Format\n";return (FALSE);}

    if (($ts = strtotime(super_translator_2000($date))) === FALSE)
        {echo "Wrong Format\n";return (FALSE);}

    echo "$ts\n";
?>
