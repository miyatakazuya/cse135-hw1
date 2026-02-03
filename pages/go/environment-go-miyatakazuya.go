package main

import (
	"fmt"
	"os"
)

func main() {
	fmt.Println("Content-Type: text/html\n\n")
	fmt.Println("<h1>Go - Environment Variables</h1><hr/>")
	
	allEnvs := os.Environ()
	for _, value := range allEnvs {
		fmt.Printf("%s<br />\n", value)
	}
}