<?php

header('Content-Type: application/json');
header('Access-Control-Allow-Origin: *');

if (isset($_GET['server']) and isset($_GET['username']) and isset($_GET['password']) and isset($_GET['email']) and isset($_GET['client'])) {
	$date = time();
	$db = mysql_connect('mysql1.alwaysdata.com', '106149_nibbler', 'password');
	mysql_select_db('epitech-hub_nibbler', $db);
	$sql = "INSERT INTO `epitech-hub_nibbler`.`spider_users` (`id`, `username`, `password`, `date_creation`, `email`, `date`, `client_id`) 
			VALUES (NULL, '" . $_GET['username'] . "','" . $_GET['password'] . "', '" . $date . "', '" . $_GET['email'] . "', '" . $date . "', '". $_GET['client_id']. "')";
	$req = mysql_query($sql) or die ('SQL Error : <br>'. $sql . '<br>' . mysql_error());
	$final['status'] = true;
} else {
	$final['status'] = false;
}
$final['date'] = time();
echo json_encode($final);
mysql_close($db);
?>