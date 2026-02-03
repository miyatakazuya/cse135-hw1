<!DOCTYPE html>
<html>
<body>

<h1>PHP Hello World - By Kazuya Miyata CSE135</h1><br/>

<?php
$env_vars = getenv();

foreach ($env_vars as $key => $value) {
    echo "<b>$key:</b> $value<br>";
}
?>

</body>
</html>