<?php
header("Cache-Control: no-cache");
header("Content-Type: text/html");
?>
<!DOCTYPE html>
<html><head><title>POST Request Echo</title></head><body><h1 align="center">POST Request Echo</h1><hr>
<b>Message Body:</b><br />
<ul>
<?php
foreach ($_POST as $key => $value) {
    echo "<li>$key = $value</li>\n";
}
?>
</ul>
</body></html>
