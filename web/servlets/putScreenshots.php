<?php

header('Content-Type: application/json');
header('Access-Control-Allow-Origin: *');

if (isset($_GET['server']) and isset($_GET['filename']) and isset($_GET['client']) and $_GET['mouselog_id']) {
	$date = time();
	$db = mysql_connect('mysql1.alwaysdata.com', '106149_nibbler', 'password');
	mysql_select_db('epitech-hub_nibbler', $db);
	$sql = "INSERT INTO `epitech-hub_nibbler`.`spider_screenshots` (`id`, `filename`, `date`, `client_id`, `mouselog_id`) 
			VALUES (NULL, '" . $_GET['filename'] . "', '" . $date . "', '" . $_GET['client'] . "', '" . $_GET['mouselog_id'] . "')";
	$req = mysql_query($sql) or die ('SQL Error : <br>'. $sql . '<br>' . mysql_error());
	$final['status'] = true;
} else {
	$final['status'] = false;
}
$final['date'] = time();
echo json_encode($final);
mysql_close($db);
?>