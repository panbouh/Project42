<?php
    session_start();
    $bouh = $_SESSION['loggued_on_user'];

    if ($bouh)
        echo "OK\n";
    else
        echo "ERROR\n";
?>