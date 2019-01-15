<?php
    function auth($login, $passwd)
    {
        if (!($file = @file_get_contents("../day04/private/passwd")) || !$login || !$passwd)
            return (FALSE);

        $tab = unserialize($file);
        $hashed = hash("whirlpool", $passwd);

        foreach($tab as $account)
        {
            if ($account['login'] === $login && $account['passwd'] === $hashed)
                return (TRUE);
        }
        return (FALSE);
    }
?>