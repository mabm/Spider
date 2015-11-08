<?php

header('Content-Type: application/json');
header('Access-Control-Allow-Origin: *');

if (isset($_GET['server']) and isset ($_GET['x']) and isset($_GET['y']) and isset($_GET['button']) and isset($_GET['client']) and isset($_GET['screenshot'])) {
	$date = time();
	$db = mysql_connect('mysql1.alwaysdata.com', '106149_nibbler', 'password');
	mysql_select_db('epitech-hub_nibbler', $db);
	$sql = "INSERT INTO `epitech-hub_nibbler`.`spider_mouselog` (`id`, `server_ip`, `x`, `y`, `button`, `client_id`, `screenshot_id`, `date`) VALUES 
			(NULL, '" . $_GET['server'] . "', '" . $_GET['x'] . "', '" . $_GET['y'] . "', '" . $_GET['button'] . "', '" . $_GET['client'] . "', '" . $_GET['screenshot'] . "', '" . $date ."')";
	$req = mysql_query($sql) or die ('SQL Error : <br>'. $sql . '<br>' . mysql_error());
	$final['status'] = true;
} else {
	$final['status'] = false;
}
$final['date'] = time();
echo json_encode($final);
mysql_close($db);
?>