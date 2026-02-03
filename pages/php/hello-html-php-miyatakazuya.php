<!DOCTYPE html>
<html>
<body>

<h1>PHP Hello World - By Kazuya Miyata CSE135</h1><br/>

<?php
echo "Hello World from PHP!" . "<br>";
echo "Today is " .date('Y-m-d H:i:s', time()). "<br>";
echo "Your IP Address is: " . $_SERVER['REMOTE_ADDR'] . "<br>";
?>

</body>
</html>