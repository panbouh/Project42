<?php
    $_PRIVATE_PATH = "../private";
    $_PASSWD_PATH = "../private/passwd";

    function account_create($account_t, $login, $pwd)
    {
        $account_t [] = array("login"=>$login, "passwd"=>$pwd);
        $file = array(serialize($account_t));
        file_put_contents("../private/passwd", $file);
    }
    
    function account_exist($account_t, $login)
    {
        if (!$account_t)
            return (FALSE);
        foreach ($account_t as $account)
            {
                if ($account['login'] === $login)
                    return (TRUE);
            }
        return (FALSE);
    }

    $login = $_POST['login'];
    if ($_POST['passwd'])
        $pwd = hash("whirlpool", $_POST['passwd']);
    $account_t = [];

    if (!file_exists($_PRIVATE_PATH))
        mkdir($_PRIVATE_PATH, 0755);

    if (file_exists($_PASSWD_PATH))
    {
        $file = file_get_contents($_PASSWD_PATH);
        $account_tab = unserialize($file);
    }

    if ($login && $pwd && ($_POST['submit']) === "OK")
    {
        if (!account_exist($account_tab, $login))
        {
            account_create($account_tab, $login, $pwd);
            echo ("OK\n");
        }
        else
            echo ("ERROR\n");
    }
    else
        echo ("ERROR\n");
?>