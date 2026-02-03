<?php
session_start();

// Handle Form Submission
if ($_SERVER['REQUEST_METHOD'] === 'POST') {
    $username = trim($_POST['username']);
    if (!empty($username)) {
        $_SESSION['username'] = $username;
        header("Location: session-php.php");
        exit;
    }
}
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>PHP Login</title>
</head>
<body>
    <h1>Set Username (Login)</h1>
    <form method="POST" action="login-php.php">
        <label>Enter Username: <input type="text" name="username" required></label>
        <button type="submit">Start Session</button>
    </form>
    <p><a href="session-php.php">Back to Session Page</a></p>
</body>
</html>
