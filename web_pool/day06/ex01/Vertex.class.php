<?php
    class Vertex
    {
        private static $verbose = FALSE;
        private $_x = 0;
        private $_y = 0;
        private $_z = 0;
        private $_w = 1.0;
        private $_color;

        function __construt (array $val)
        {
            $this->_x = $val['x'];
            $this->_y = $val['y'];
            $this->_z = $val['z'];
            if ($val['w'])
                $this->_w = $val['w'];
            if ($val['color'])
                $this->_color = $val['color'];
            else
                $_color = new Color(array ('rgb' => 16777215));
            echo "$this constructed\n";        
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
            $s = "Vertex( x: ".$this->_x.", y: ".$this->_y.", z:".$this->_z.", w:".$this->_w;
            if (self::$verbose)
                $s = $s.", ".Color();
            $s = $s." )";
            return ($s);
        }

        function __destruct ()
        {
            echo "$this destructed\n";
            return;
        }
    }
?>