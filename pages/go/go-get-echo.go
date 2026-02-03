package main

import (
    "fmt"
    "os"
    "strings"
    "net/url"
)

func main() {
    fmt.Println("Cache-Control: no-cache")
    fmt.Println("Content-type: text/html\n")
    fmt.Println("<!DOCTYPE html><html><head><title>GET Request Echo</title></head><body><h1 align=\"center\">Get Request Echo</h1><hr>")
    
    query := os.Getenv("QUERY_STRING")
    fmt.Printf("<b>Query String:</b> %s<br />\n", query)
    
    if len(query) > 0 {
        parts := strings.Split(query, "&")
        for _, part := range parts {
            pair := strings.SplitN(part, "=", 2)
            if len(pair) == 2 {
                key, err1 := url.QueryUnescape(pair[0])
                val, err2 := url.QueryUnescape(pair[1])
                if err1 == nil && err2 == nil {
                     fmt.Printf("%s = %s<br/>\n", key, val)
                }
            }
        }
    }
    fmt.Println("</body></html>")
}
