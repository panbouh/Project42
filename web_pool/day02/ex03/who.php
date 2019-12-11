#!/usr/bin/php
<?php
    $xutmp_f = "/var/run/utmpx";

    // $file_bin = file_get_contents($xutmp_f);

    $file_bin = file($xutmp_f);

    unset($file_bin[0]);
    $tmp = implode('\n', $file_bin);

    print_r($file_bin);

    $file_trad = unpack('alogin/awho/itime', $tmp);

    print_r($file_trad);

?>