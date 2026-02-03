<?php
header("Cache-Control: no-cache");
header("Content-Type: text/html");
?>
<!DOCTYPE html>
<html><head><title>General Request Echo</title></head><body><h1 align="center">General Request Echo</h1><hr>
<p><b>HTTP Protocol:</b> <?php echo $_SERVER['SERVER_PROTOCOL']; ?></p>
<p><b>HTTP Method:</b> <?php echo $_SERVER['REQUEST_METHOD']; ?></p>
<p><b>Query String:</b> <?php echo $_SERVER['QUERY_STRING']; ?></p>
<p><b>Hostname:</b> <?php echo gethostname(); ?></p>
<p><b>Date/Time:</b> <?php echo date(DATE_RFC2822); ?></p>
<p><b>User Agent:</b> <?php echo $_SERVER['HTTP_USER_AGENT']; ?></p>
<p><b>Remote Address:</b> <?php echo $_SERVER['REMOTE_ADDR']; ?></p>
<p><b>Message Body:</b> <?php echo file_get_contents('php://input'); ?></p>
</body></html>
