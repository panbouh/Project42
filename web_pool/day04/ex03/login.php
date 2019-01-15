<?php
    session_start();
    include("auth.php"); 
     $_SESSION['loggued_on_user'] = "";
    $login = $_GET['login'];
    $pwd = $_GET['passwd'];
    if (auth($login, $pwd))
    {
        echo "ERROR\n";
        return (TRUE);
    }
    $_SESSION['loggued_on_user'] = $login;
    echo "OK\n";
?>