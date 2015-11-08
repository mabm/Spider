<?php

header('Content-Type: application/json');
header('Access-Control-Allow-Origin: *');

if (isset($_GET['id'])) {
	$db = mysql_connect('mysql1.alwaysdata.com', '106149_nibbler', 'password');
	mysql_select_db('epitech-hub_nibbler', $db);
	$sql = 'SELECT * FROM spider_log WHERE id = ' . $_GET['id'] . ' ORDER BY date DESC';
	$req = mysql_query($sql) or die('SQL Error :<br>'.$sql.'<br>'.mysql_error());
	$mainTab = array();
	while ($data = mysql_fetch_assoc($req)) {
		$local = "";
		$local['log'] = $data['value'];
		$local['date'] = date('d/m/Y', $data['date']).' - '.date('H:i:s', $data['date']);
		array_push($mainTab, $local);
	}
	$final['list'] = $mainTab;
	$final['status'] = true;
} else {
	$final['status'] = false;
}
echo json_encode($final);
mysql_close($db);
?>