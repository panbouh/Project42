<?php
   if (!($file = @file_get_contents("../private/passwd")))
    echo ("ERROR\n");

   function change_passwd($accounts_t, &$account, $newpw)
   {
       $account['passwd'] = $newpw;
       $file = array(serialize($accounts_t));
       file_put_contents("../private/passwd", $file);
   }

   $login = $_POST['login'];
   $oldpw = hash("whirlpool", $_POST['oldpw']);
   $newpw = hash("whirlpool", $_POST['newpw']);

   $accounts_tab = unserialize($file);

   foreach($accounts_tab as &$account)
   {
       if ($account['login'] === $login && $account['passwd'] === $oldpw)
       {
           change_passwd($accounts_tab, $account, $newpw);
           echo ("OK\n");
       }
   }
   echo ("ERROR\n");
?>