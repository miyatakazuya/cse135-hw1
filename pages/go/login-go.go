package main

import (
    "fmt"
    "net/http"
    "net/http/cgi"
)

func main() {
    if err := cgi.Serve(http.HandlerFunc(func(w http.ResponseWriter, r *http.Request) {
        
        if r.Method == "POST" {
            username := r.FormValue("username")
            if username != "" {
                newID := GenerateSessionID()
                SetSessionData(newID, username)
                
                // We cannot use simple Redirect header easily because we need to POST to the next page to adhere to "Hidden Form" strictness? 
                // Ah, usually "Hidden Form Fields" implies a multi-step form flow. 
                // Redirects are GET. So we can't redirect with POST data.
                // WE MUST render an intermediate "Auto-Submit" form or just render the Dashboard directly here?
                // Or we can pass it in via GET for the redirect once? But that violates "Hidden Form".
                // Okay, the best way for "Hidden Form Based Session" is to render the View directly, or render a "Continue" button.
                
                w.Header().Set("Content-Type", "text/html")
                w.WriteHeader(200)
                fmt.Fprintln(w, "Login Successful. <form action='/cgi-bin/session-go.cgi' method='POST'>")
                fmt.Fprintf(w, "<input type='hidden' name='session_id' value='%s'>", newID)
                fmt.Fprintln(w, "<button type='submit'>Click here to Continue to Session Page</button></form>")
                // Auto submit script
                fmt.Fprintln(w, "<script>document.forms[0].submit()</script>")
                return
            }
        }
        
        w.Header().Set("Content-Type", "text/html")
        w.WriteHeader(200)
        
        fmt.Fprintln(w, "<!DOCTYPE html><html><head><title>Go Login</title></head><body>")
        fmt.Fprintln(w, "<h1>Set Username (Login)</h1>")
        fmt.Fprintln(w, "<form method='POST' action='/cgi-bin/login-go.cgi'>")
        fmt.Fprintln(w, "<label>Enter Username: <input type='text' name='username' required></label>")
        fmt.Fprintln(w, "<button type='submit'>Start Session</button>")
        fmt.Fprintln(w, "</form>")
        fmt.Fprintln(w, "<p><a href='/cgi-bin/session-go.cgi'>Back to Session Page</a></p>")
        fmt.Fprintln(w, "</body></html>")
        
    })); err != nil {
        fmt.Println(err)
    }
}
