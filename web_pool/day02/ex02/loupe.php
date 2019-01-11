#!/usr/bin/php
<?php
    if ($argc != 2)
        {echo"Usage:\n./loupe.php file.htlm\n";return (FALSE);}
    
    $file = file($argv[1]);
    print_r($file);

    $line = implode("", $file);
    $line = preg_replace_callback('/"(.*)"/',
                                    function ($matches){
                                                        return (strtoupper($matches[0]));
                                                        }
                                                , $line);
    echo "line :\n$line\n";
?>