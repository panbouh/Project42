<?php
    class House
    {
        public function introduce()
        {
            print('house '.$this->getHouseName().' of '.$this->getHouseSeat().' : "'.$this->getHouseMotto().'"').PHP_EOL;
        }
    }
?>