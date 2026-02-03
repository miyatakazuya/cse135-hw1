<?php
session_start();
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>PHP Session (Cookies)</title>
</head>
<body>
    <h1>PHP Session Management (Cookies)</h1>
    
    <div>
        <?php if(isset($_SESSION['username'])): ?>
            <p><strong>Status:</strong> Active Session</p>
            <p><strong>Username:</strong> <?php echo htmlspecialchars($_SESSION['username']); ?></p>
            <p><a href="logout-php.php">Click here to Log Out</a></p>
        <?php else: ?>
            <p><strong>Status:</strong> No Active Session</p>
            <p>No username set.</p>
            <p><a href="login-php.php">Click here to Log In</a></p>
        <?php endif; ?>
    </div>
    
    <hr>
    <p><a href="../../index.html">Back to Home</a></p>
</body>
</html>
