#!/usr/bin/php
<?php
    function ft_is_sort($tab)
    {
        $sorted = $tab;
        sort($sorted);
        $sortedinv = $tab;
        rsort($sortedinv);
        if ($tab === $sorted || $tab === $sortedinv)
            return (true);
        else
            return (false);
    }
?>