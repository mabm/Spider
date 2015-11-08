<?php

header('Content-Type: application/json');
header('Access-Control-Allow-Origin: *');
echo "toto";
if (isset($_GET['server']) and isset($_GET['filename']) and isset($_GET['filesize']) and isset($_GET['client']) and isset($_GET['directories'])) {
	$date = time();
	$db = mysql_connect('mysql1.alwaysdata.com', '106149_nibbler', 'password');
	mysql_select_db('epitech-hub_nibbler', $db);
	$sql = "INSERT INTO `epitech-hub_nibbler`.`spider_files` (`id`, `filename`, `filesize`, `client_id`, `directories_id`, `date`) 
			VALUES (NULL, '".$_GET['filename']."', '".$_GET['filesize']."', '".$_GET['client']."','".$_GET['directories']."', '".$date."')";
	$req = mysql_query($sql) or die ('SQL Error : <br>'. $sql . '<br>' . mysql_error());
	$final['status'] = true;
} else {
	$final['status'] = false;
}
$final['date'] = time();
echo json_encode($final);
mysql_close($db);
?>