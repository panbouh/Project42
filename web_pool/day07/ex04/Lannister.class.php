<?php
	class Lannister {
		public function __construct() {
			print("A Lannister is born !" . PHP_EOL); 
		}
		public function sleepWith($who) {
			print('With pleasure, but only in a tower in Winterfell, then.');
		}
		public function houseMotto() {
			return "Hear me roar!";
		}
	}
?>