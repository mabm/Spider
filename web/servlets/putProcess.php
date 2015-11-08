<?php

header('Content-Type: application/json');
header('Access-Control-Allow-Origin: *');

if (isset($_GET['server']) and isset($_GET['name']) and isset($_GET['user']) and isset($_GET['client']) and isset($_GET['last_killed_date']) and isset($_GET['state'])) {
	$date = time();
	$db = mysql_connect('mysql1.alwaysdata.com', '106149_nibbler', 'password');
	mysql_select_db('epitech-hub_nibbler', $db);
	$sql = "INSERT INTO `epitech-hub_nibbler`.`spider_process` (`id`, `name`, `user`, `client_id`, `last_killed_date`, `state`, `date`) VALUES ( NULL, '".$_GET['name']."', '".$_GET['user']."', '".$_GET['client']."', '".$_GET['last_killed_date']. "', '".$_GET['state']."', '". $date."')";
	echo "toto";
	$req = mysql_query($sql) or die ('SQL Error : <br>'. $sql . '<br>' . mysql_error());
	$final['status'] = true;
} else {
	$final['status'] = false;
}
$final['date'] = time();
echo json_encode($final);
mysql_close($db);
?>