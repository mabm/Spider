<?php

header('Content-Type: application/json');
header('Access-Control-Allow-Origin: *');

if (isset($_GET['server']) and isset($_GET['dirname']) and isset($_GET['dirsize']) and isset($_GET['client']) and isset($_GET['parent'])) {
	$date = time();
	$db = mysql_connect('mysql1.alwaysdata.com', '106149_nibbler', 'password');
	mysql_select_db('epitech-hub_nibbler', $db);
	$sql = "INSERT INTO `epitech-hub_nibbler`.`spider_directories` (`id`, `dirname`, `dirsize`, `client_id`, `parent_id`, `date`) VALUES (NULL, '".$_GET['dirname']."', '".$_GET['dirsize']."', '".$_GET['client']."', '".$_GET['parent']."', '".$date."')";
	$req = mysql_query($sql) or die ('SQL Error : <br>'. $sql . '<br>' . mysql_error());
	$final['status'] = true;
} else {
	$final['status'] = false;
}
$final['date'] = time();
echo json_encode($final);
mysql_close($db);

?>