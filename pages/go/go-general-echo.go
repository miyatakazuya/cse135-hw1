package main

import (
    "fmt"
    "io/ioutil"
    "os"
    "time"
)

func main() {
    fmt.Println("Cache-Control: no-cache")
    fmt.Println("Content-type: text/html\n")
    fmt.Println("<!DOCTYPE html><html><head><title>Go General Request Echo</title></head><body><h1 align=\"center\">Go General Request Echo</h1><hr>")
    
    fmt.Printf("<p><b>HTTP Protocol:</b> %s</p>\n", os.Getenv("SERVER_PROTOCOL"))
    fmt.Printf("<p><b>HTTP Method:</b> %s</p>\n", os.Getenv("REQUEST_METHOD"))
    fmt.Printf("<p><b>Query String:</b> %s</p>\n", os.Getenv("QUERY_STRING"))
    
    host, _ := os.Hostname()
    fmt.Printf("<p><b>Hostname:</b> %s</p>\n", host)
    fmt.Printf("<p><b>Date/Time:</b> %s</p>\n", time.Now().Format(time.RFC1123))
    fmt.Printf("<p><b>User Agent:</b> %s</p>\n", os.Getenv("HTTP_USER_AGENT"))
    fmt.Printf("<p><b>Remote Address:</b> %s</p>\n", os.Getenv("REMOTE_ADDR"))
    
    body, _ := ioutil.ReadAll(os.Stdin)
    fmt.Printf("<p><b>Message Body:</b> %s</p>\n", string(body))
    
    fmt.Println("</body></html>")
}
