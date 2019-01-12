<?PHP
    session_start();
    echo "reload4\n";
    $_SESSION["login"] = $_GET["login"];
    $_SESSION["pwd"] = $_GET["passwd"];
    echo "log : ".$_SESSION["login"]."\npwd : ".$_SESSION["pwd"]."\n";
?>

<html lang="fr">
    <head>
        <meta charset="UTF-8">
        <title>session_start</title>
    </head>
    <body>
        <form action="index.php" method="GET">
            <label for="login">Login</label>
            <input type="text" name="login" id="login" value="<?php $_SESSION[login]?>">
            <label for="pwd">Password</label>
            <input type="password" name="passwd" id="pwd" value="echo $_SESSION[pwd]">
            <button type="submit" name="submit">ok</button>    
        </form>
    </body>
</html>