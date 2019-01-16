<?php
    // include ('Color.class.php');
    class Vertex
    {
        public static $verbose = FALSE;
        private $_x = 0;
        private $_y = 0;
        private $_z = 0;
        private $_w = 1.0;
        private $_color;

        function __construct (array $val)
        {
            $this->_x = $val['x'];
            $this->_y = $val['y'];
            $this->_z = $val['z'];
            if ($val['w'])
                $this->_w = $val['w'];
            if ($val['color'])
                $this->_color = $val['color'];
            else
                $this->setColor(new Color(array ('rgb' => 16777215)));


            if (self::$verbose)
                print($this.' constructed'.PHP_EOL);
        }
        
        public static function doc()
        {
            if ($file_doc = file_get_contents("Vertex.doc.txt"))
                echo $file_doc;
        }

        function getX(){ return $this->_x; }
        function getY(){ return $this->_y; }
        function getZ(){ return $this->_z; }
        function getW(){ return $this->_w; }
        function getColor(){ return $this->color; }

        function setX($val){ $this->_x += $val; }
        function setY($val){ $this->_y += $val; }
        function setZ($val){ $this->_z += $val; }
        function setW($val){ $this->_w += $val; }
        function setColor(Color $val){ $this->_color = $val; }

        public function __toString ()
        {
            if (self::$verbose)
                return ('Vertex( x: '.sprintf("%.2f", $this->_x).', y: '.sprintf("%.2f",$this->_y).', z:'.sprintf("%.2f", $this->_z).', w:'.sprintf("%.2f", $this->_w).', '.$this->_color.' )');
            return ('Vertex( x: '.sprintf("%.2f", $this->_x).', y: '.sprintf("%.2f",$this->_y).', z:'.sprintf("%.2f", $this->_z).', w:'.sprintf("%.2f", $this->_w).' )');
        }

        function __destruct ()
        {
            if (self::$verbose)
                print($this.' destructed'.PHP_EOL);
            return;
        }
    }

    // Color::$verbose = TRUE;
    // $red = new Color(array ('rgb' => 16777215));

    // print($red.PHP_EOL);
    
    // Vertex::$verbose = TRUE;
    // $bouh  = new Vertex( array( 'x' => 0.0, 'y' => 0.0, 'z' => 0.0 ) );

    // print($bouh.PHP_EOL);
?>