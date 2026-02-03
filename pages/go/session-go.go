package main

import (
    "fmt"
    "net/http"
    "net/http/cgi"
)

func main() {
    if err := cgi.Serve(http.HandlerFunc(func(w http.ResponseWriter, r *http.Request) {
        
        // Check for Session ID in POST (Hidden Field)
        sessID := r.FormValue("session_id")
        username := GetSessionData(sessID)
        
        // Check if just logged in (from Login page)
        // Login page will POST to HERE (or separate) with username
        // Actually, let's keep it simple: 
        // session-go.cgi: Displays status. Accepts POST from itself (none) or from Login.
        // But Login is separate.
        
        w.Header().Set("Content-Type", "text/html")
        // No cache
        w.Header().Set("Cache-Control", "no-cache")
        w.WriteHeader(200)
        
        fmt.Fprintln(w, "<!DOCTYPE html><html><head><title>Go Session</title>")
        fmt.Fprintln(w, "</head><body>")
        fmt.Fprintln(w, "<h1>Go Session Management (Hidden Form)</h1>")
        
        fmt.Fprintln(w, "<div>")
        
        if username != "" {
            fmt.Fprintln(w, "<p><strong>Status:</strong> Active Session</p>")
            fmt.Fprintf(w, "<p><strong>Username:</strong> %s</p>", username)
            fmt.Fprintf(w, "<p><strong>Session ID:</strong> %s</p>", sessID)
            
            // Logout must be a FORM to pass the hidden ID
            fmt.Fprintln(w, "<form action='/cgi-bin/logout-go.cgi' method='POST'>")
            fmt.Fprintf(w, "<input type='hidden' name='session_id' value='%s'>", sessID)
            fmt.Fprintln(w, "<button type='submit'>Click here to Log Out</button>")
            fmt.Fprintln(w, "</form>")
        } else {
            fmt.Fprintln(w, "<p><strong>Status:</strong> No Active Session</p>")
             fmt.Fprintln(w, "<p>No username set.</p>")
             
             // Login Link
             fmt.Fprintln(w, "<p><a href='/cgi-bin/login-go.cgi'>Click here to Log In</a></p>")
        }
        
        fmt.Fprintln(w, "</div><hr>")
        fmt.Fprintln(w, "<p><a href='/index.html'>Back to Home</a></p>")
        fmt.Fprintln(w, "</body></html>")
        
    })); err != nil {
        fmt.Println(err)
    }
}
