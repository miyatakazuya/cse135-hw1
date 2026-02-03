<?php
header("Cache-Control: no-cache");
header("Content-Type: text/html");
?>
<!DOCTYPE html>
<html><head><title>PHP POST Request Echo</title></head><body><h1 align="center">PHP POST Request Echo</h1><hr>
<b>Message Body:</b><br />
<ul>
<?php
foreach ($_POST as $key => $value) {
    echo "<li>$key = $value</li>\n";
}
?>
</ul>
</body></html>
