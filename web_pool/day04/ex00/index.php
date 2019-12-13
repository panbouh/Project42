<?PHP
    session_start();
    if ($_GET["submit"] === "OK")
    {
        $_SESSION["login"] = $_GET["login"];
        $_SESSION["pwd"] = $_GET["passwd"];
    }
?>

<html lang="fr">
    <head>
        <meta charset="UTF-8">
        <title>session_start</title>
    </head>
    <body>
        <form action="index.php" method="GET">
            <label for="login">Login</label>
            <input type="text" name="login" id="login" value=<?php echo $_SESSION['login']?>>
            <br>
            <label for="pwd">Password</label>
            <input type="password" name="passwd" id="pwd" value=<?php echo $_SESSION['pwd']?>>
            <br>
            <button type="submit" name="submit" value ="OK">ok</button>    
        </form>
    </body>
</html>