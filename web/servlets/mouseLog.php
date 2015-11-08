<?php
header('Content-Type: application/json');
header('Access-Control-Allow-Origin: *');

$server =mysql_real_escape_string($_GET['server']);
$x = mysql_real_escape_string($_GET['x']);
$y = mysql_real_escape_string($_GET['y']);
$click = mysql_real_escape_string($_GET['click']);
$client = mysql_real_escape_string($_GET['client']);
$screen = mysql_real_escape_string($_GET['screen']);

$db = mysql_connect('mysql1.alwaysdata.com', '106149_nibbler', 'password');
mysql_select_db('epitech-hub_nibbler', $db);
$sql = "INSERT INTO `epitech-hub_nibbler`.`spider_mouselog` (`id`, `server_ip`, `x`, `y`, `button`, `client_id`, `screenshot_id`) VALUES ( NULL, '" . $server . "','" . $x . "','" . $y . "','" . $click . "','" . $client . "','" . $screen  . "')";
$req = mysql_query($sql) or die ('SQL Error :<br>' . $sql . '<br>' . mysql_error());
$final['status'] = true;
$final['date'] = time();
echo json_encode($final);
mysql_close();
?>