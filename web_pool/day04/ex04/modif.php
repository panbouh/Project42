<?php
// function find_or_create()
// {
// 	if(file_exists("../htdocs") === FALSE)
// 		mkdir("../htdocs");
// 	if(file_exists("../htdocs/private") === FALSE)
// 		mkdir("../htdocs/private");
// 	return(file_exists("../htdocs/private/passwd"));
// }


if ($_POST['login'] && $_POST['oldpw'] && $_POST['newpw'] && $_POST['login'] != "" && $_POST['oldpw'] != "" && $_POST['newpw'] != "")
{
	if ($_POST['submit'] == "OK")
	{
        // if (find_or_create() == 1)
        if (1)
		{
          
           // if ($unstr != "")
            if (@file_get_contents("../htdocs/private/passwd") != FALSE)
            {
                $unstr = file_get_contents("../htdocs/private/passwd");
                $arrayed_data = unserialize($unstr);

                if ($arrayed_data[$_POST['login']] != NULL)
                {
                    $true_pw = $arrayed_data[$_POST['login']];
                    
                    if (hash('whirlpool', $_POST['oldpw']) == $true_pw) // si hash(old mdp) == hash en bdd
                    {
                        $hashed_newpw = hash('whirlpool', $_POST['newpw']);
                        $arrayed_data[$_POST['login']] = $hashed_newpw;
                        $serialized_data = serialize($arrayed_data);
                        file_put_contents("../htdocs/private/passwd", $serialized_data);
                        echo "OK\n";
                        exit;
                    }
                }
            }
		}
	}
}
echo "ERROR\n";
exit;
?>
