<?php
/**
 * Automated GitHub Deployment Script
 */
$log_file = "deploy_log.txt";
$date = date('Y-m-d H:i:s');

// Execute the pull command
// 2>&1 redirects errors to the output so you can see them in the log
$output = shell_exec("git pull origin main 2>&1");

// Log the result for your README verification
$log_entry = "[$date] PULL RESULT: " . trim($output) . "\n";
file_put_contents($log_file, $log_entry, FILE_APPEND);

echo "Deployment finished. Check log for details.";
?>
