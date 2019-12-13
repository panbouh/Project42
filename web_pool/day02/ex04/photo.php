#!/usr/bin/php
<?php
    if ($argc < 1)
        return (false);
        
    function get_html($home_page)
    {
        $curl = curl_init();

        curl_setopt($curl, CURLOPT_URL, $home_page);
        curl_setopt($curl, CURLOPT_SSL_VERIFYPEER, false);
        curl_setopt($curl, CURLOPT_RETURNTRANSFER, true);

        $html = curl_exec($curl);

        curl_close($curl);
        return($html);
    }

    function get_img($html, $url)
    {
        preg_match_all('|(<img src=")([^"]*)(".*>)|', $html, $tab);
        foreach($tab[2] as $elem)
        {
            if (preg_match('/^http(s)?:\/\/.*/', $elem))
                $ret[] = $elem;
            else
                $ret[] = preg_replace('|/$|', "", $url)."/".preg_replace('|^/|', "", $elem);
        }
        return ($ret);
    }

    function dl_img($url_img, $dir)
    {
        $curl = curl_init ($url_img);
        curl_setopt($curl, CURLOPT_HEADER, false);
        curl_setopt($curl, CURLOPT_RETURNTRANSFER, true);
        curl_setopt($curl, CURLOPT_BINARYTRANSFER, true);
        $bin = curl_exec($curl);
        curl_close ($curl);
        if ($fd = fopen($dir, 'w'))
        {
            fwrite($fd, $bin);
            fclose($fd);
        }
    }
    if (!empty($html = get_html($argv[1])))
    {
        if ($img_url = get_img($html, $argv[1]))
        {
            $dir = preg_replace('/^http(s)?:\/\//', "", $argv[1]);
            echo $dir."\n\n\n";
            if (!file_exists($dir))
                mkdir ($dir);
            foreach ($img_url as $img)
            {
                $path = $dir."/".basename($img);
                dl_img($im, $path);
            }
        }
    }