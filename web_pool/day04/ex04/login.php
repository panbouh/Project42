<?php
function find_or_create()
{
	if(file_exists("../htdocs") === FALSE)
		mkdir("../htdocs");
	if(file_exists("../htdocs/private") === FALSE)
		mkdir("../htdocs/private");
	return(file_exists("../htdocs/private/passwd"));
}

if ($_POST['login'] && $_POST['passwd'] && $_POST['login'] != "" && $_POST['passwd'] != "")
{
	if ($_POST['submit'] == "OK")
	{
		if (find_or_create() == 1)
		{
			$unstr = file_get_contents("../htdocs/private/passwd");
			$arrayed_data = unserialize($unstr);
			if ($arrayed_data[$_POST['login']] != NULL)
			{
				echo "ERROR\n";
				exit;
			}
		}
		$hashed_pwd = hash('whirlpool', $_POST['passwd']);
        $arrayed_data[$_POST['login']] = $hashed_pwd;
		$serialized_data = serialize($arrayed_data);
		file_put_contents("../htdocs/private/passwd", $serialized_data);
		echo "OK\n";
		exit;
	}
}
echo "ERROR\n";
exit;
?>
