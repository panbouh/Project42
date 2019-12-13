<?php
    function enter_here()
    {
        if ($_SERVER['PHP_AUTH_USER'] !== 'zaz' && $_SERVER['PHP_AUTH_PW'] !== 'jaimelespetitsponeys') 
        {
            header('WWW-Authenticate: Basic realm=\"Espace membres\"');
            header('HTTP\ 1.0 401 Unauthorized');
            return (false);
        }
        echo "name = " . $_SERVER['PHP_AUTH_USER'] . "\n";
        echo "pwd  = " . $_SERVER['PHP_AUTH_PW'] . "\n";
        return (true);
    }

    if (!enter_here())
    {
        echo "<html><body>Cette zone est accessible uniquement aux membres du site</body></html>";  
    }
    else
    {
        $img = file_get_contents("../img/42.png");
        $img_64 = base64_encode($img);
        echo "<img src=\"data:image/png;base64,$img_64\">";


    }
?>
