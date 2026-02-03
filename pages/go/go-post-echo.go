package main

import (
    "fmt"
    "io/ioutil"
    "os"
    "strings"
    "net/url"
)

func main() {
    fmt.Println("Cache-Control: no-cache")
    fmt.Println("Content-type: text/html\n")
    fmt.Println("<!DOCTYPE html><html><head><title>Go POST Request Echo</title></head><body><h1 align=\"center\">Go POST Request Echo</h1><hr>")
    
    body, _ := ioutil.ReadAll(os.Stdin)
    bodyStr := string(body)
    
    fmt.Println("<b>Message Body:</b><br />")
    fmt.Println("<ul>")
    
    if len(bodyStr) > 0 {
         parts := strings.Split(bodyStr, "&")
        for _, part := range parts {
            pair := strings.SplitN(part, "=", 2)
             if len(pair) == 2 {
                key, err1 := url.QueryUnescape(pair[0])
                val, err2 := url.QueryUnescape(pair[1])
                if err1 == nil && err2 == nil {
                     fmt.Printf("<li>%s = %s</li>\n", key, val)
                }
            }
        }
    }
    fmt.Println("</ul>")
    fmt.Println("</body></html>")
}
