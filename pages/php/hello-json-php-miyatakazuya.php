<?php
$arr = array('message' => "Hello World from PHP!", 'time' => date('Y-m-d H:i:s', time()), 'ip' => $_SERVER['REMOTE_ADDR']);
header('Content-Type: application/json; charset=utf-8');
echo json_encode($arr);
?>