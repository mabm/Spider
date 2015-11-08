<?php

header('Content-Type: application/json');
header('Access-Control-Allow-Origin: *');

$server = mysql_real_escape_string($_GET['server']);
$log = mysql_real_escape_string($_GET['log']);
$db = mysql_connect('mysql1.alwaysdata.com', '106149_nibbler', 'password');
mysql_select_db('epitech-hub_nibbler', $db);
$sql = "INSERT INTO `epitech-hub_nibbler`.`spider_log` (`id`, `server_ip`, `value`, `date`) VALUES ( NULL,'" . $server . "','" . $log . "','". time() . "')";
$req = mysql_query($sql) or die('SQL Error :<br>' . $sql . '<br>' . mysql_error());
$final['status'] = true;
$final['date'] = time();
echo json_encode($final);
mysql_close();
?>