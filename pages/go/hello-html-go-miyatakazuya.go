package main

import (
	"fmt"
	"os"
	"time"
)

func main() {
	fmt.Println("Content-Type: text/html\n\n")
	fmt.Println("<h1>GO CGI is working!</h1><hr/>")
	fmt.Println("<h2>GO Hello World - By Kazuya Miyata CSE135</h2>")
	fmt.Printf("<p>This program was generated at: %s</p>", time.Now().Format("2006-01-02 15:04:05"))
	fmt.Printf("<p>Your current IP Address is: %s</p>", os.Getenv("REMOTE_ADDR"))
}