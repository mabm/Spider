<?php
	header('Content-Type: application/json');
	header('Access-Control-Allow-Origin: *');

	$server = mysql_real_escape_string($_GET['server']);
	$filename = mysql_real_escape_string($_GET['filename']);
	$filesize = mysql_real_escape_string($_GET['filesize']);
	$client = mysql_real_escape_string($_GET['client']);
	$dir = mysql_real_escape_string($_GET['dir']);

	$db = mysql_connect('mysql1.alwaysdata.com', '106149_nibbler', 'password');
	mysql_select_db('epitech-hub_nibbler', $db);
?>