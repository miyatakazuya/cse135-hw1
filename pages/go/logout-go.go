package main

import (
    "fmt"
    "net/http"
    "net/http/cgi"
)

func main() {
    if err := cgi.Serve(http.HandlerFunc(func(w http.ResponseWriter, r *http.Request) {
        
        sessID := r.FormValue("session_id")
        DestroySession(sessID)
        
        // Redirect to main (GET is fine for logout, as we are resetting state)
        http.Redirect(w, r, "/cgi-bin/session-go.cgi", http.StatusFound)
        
    })); err != nil {
        fmt.Println(err)
    }
}
