<?php
header("Cache-Control: no-cache");
header("Content-Type: text/html");
?>
<!DOCTYPE html>
<html><head><title>PHP GET Request Echo</title></head><body><h1 align="center">PHP Get Request Echo</h1><hr>
<b>Query String:</b> <?php echo $_SERVER['QUERY_STRING']; ?><br />
<?php
foreach ($_GET as $key => $value) {
    echo "$key = $value<br/>\n";
}
?>
</body></html>
