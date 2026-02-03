<?php
session_start();
session_destroy();
// Clear cookie
setcookie(session_name(), "", time() - 3600);
header("Location: session-php.php");
exit;
