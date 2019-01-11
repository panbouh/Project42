<?PHP
    echo "wsh8\n";
    $action = $_GET["action"];
    $co_name = $_GET["name"];
    $co_val = $_GET["value"];
    if ($action === "set")
        setcookie($co_name, $co_val, time()+50);
    else if ($action === "get")
        echo "$_COOKIE[$co_name]\n";
    else if ($action === "del")
        setcookie($co_name, FALSE, time()-4242);
?>