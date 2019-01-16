<?php

include_once('Lannister.class.php');
include_once('Jaime.class.php');
include_once('Tyrion.class.php');

class Stark {
}

class Cersei extends Lannister {
}

class Sansa extends Stark {
}

$jaime = new Jaime();
$cersei = new Cersei();
$tyrion = new Tyrion();
$sansa = new Sansa();

$jaime->sleepWith($tyrion); // Not even if I'm drunk !
$jaime->sleepWith($sansa); // Let's do this.
$jaime->sleepWith($cersei); // With pleasure, but only in a tower in Winterfell, then.

$tyrion->sleepWith($jaime); // Not even if I'm drunk !
$tyrion->sleepWith($sansa); // Let's do this.
$tyrion->sleepWith($cersei); // Not even if I'm drunk !


?>
