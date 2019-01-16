<?php

    class   Color
    {
        public $red = 0;
        public $green = 0;
        public $blue = 0;
        public static $verbose = FALSE;
        
        public static function doc()
        {
            if ($file_doc = file_get_contents("Color.doc.txt"))
                echo $file_doc;
        }
        
        public function __construct (array $rgb)
        {
            if (($i = count($rgb)) === 3)
            {
                $this->red = intval($rgb['red']);
                $this->green = intval($rgb['green']);
                $this->blue = intval($rgb['blue']);
            }
            else if ($i === 1)
            {
                $nb = intval($rgb['rgb']);
                $this->blue = intval($nb % 256);
                $nb = $nb / 256;
                $this->green = intval($nb % 256);
                $nb = $nb / 256;
                $this->red = intval($nb % 256);
                $nb = $nb / 256;
            }
            if (self::$verbose)
                echo($this.' constructed.'.PHP_EOL);
            return;
        }

        public function add (Color $b)
        {
            if (($red = $this->red + $b->red) < 0)
                $red = 0;
            if ($red > 255)
                $red = 255;

            if (($green = $this->green + $b->green) < 0)
                $green = 0;
            if ($green > 255)
                $green = 255;

            if (($blue = $this->blue + $b->blue) < 0)
                $blue = 0;
            if ($blue > 255)
                $blue = 255;
            return (new Color( array( 'red' => $red, 'green' => $green, 'blue' => $blue)));
        }

        public function sub (Color $b)
        {
            if (($red = $this->red - $b->red) < 0)
                $red = 0;
            if ($red > 255)
                $red = 255;

            if (($green = $this->green - $b->green) < 0)
                $green = 0;
            if ($green > 255)
                $green = 255;

            if (($blue = $this->blue - $b->blue) < 0)
                $blue = 0;
            if ($blue > 255)
                $blue = 255;
            return (new Color( array( 'red' => $red, 'green' => $green, 'blue' => $blue)));
        }

        public function mult ($b)
        {
            if (($red = $this->red * $b) < 0)
                $red = 0;
            if ($red > 255)
                $red = 255;

            if (($green = $this->green * $b) < 0)
                $green = 0;
            if ($green > 255)
                $green = 255;

            if (($blue = $this->blue * $b) < 0)
                $blue = 0;
            if ($blue > 255)
                $blue = 255;
            return (new Color( array( 'red' => $red, 'green' => $green, 'blue' => $blue)));
        }

        public function __toString ()
        {
            return('Color( red: '.sprintf("%3s", $this->red).', green: '.sprintf("%3s", $this->green).', blue: '.sprintf("%3s", $this->blue).' )');
        }

        public function __destruct ()
        {
            if (self::$verbose)
                echo($this.' destructed.'.PHP_EOL);
            return;
        }
    }
?>