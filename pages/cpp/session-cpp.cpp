#include "session_utils.h"

int main() {
    cout << "Cache-Control: no-cache\r\n";
    cout << "Content-type: text/html\r\n\r\n";
    
    // Check for ID in URL
    string sess_id = get_query_param("session_id");
    string username = get_session_data(sess_id);
    
    // If invalid session data (file doesn't exist), clear the ID so we treat as logged out
    if (!sess_id.empty() && username.empty()) {
        sess_id = "";
    }
    
    cout << "<!DOCTYPE html><html><head><title>C++ Session</title>";
    cout << "</head><body>";
    cout << "<h1>C++ Session Management (Dirty URL)</h1>";
    
    cout << "<div>";
    
    if (!username.empty()) {
        cout << "<p><strong>Status:</strong> Active Session</p>";
        cout << "<p><strong>Username:</strong> " << username << "</p>";
        cout << "<p><strong>Session ID:</strong> " << sess_id << "</p>";
        // Pass ID to logout
        cout << "<p><a href='/cgi-bin/logout-cpp.cgi?session_id=" << sess_id << "'>Click here to Log Out</a></p>";
    } else {
        cout << "<p><strong>Status:</strong> No Active Session</p>";
        cout << "<p>No username set.</p>";
        // If we have an ID but no data (expired), we might want to start fresh. 
        // For login, we don't need to pass an ID if we are starting fresh.
        cout << "<p><a href='/cgi-bin/login-cpp.cgi'>Click here to Log In</a></p>";
    }
    
    cout << "</div><hr>";
    cout << "<p><a href='/index.html'>Back to Home</a></p>";
    cout << "</body></html>";
    return 0;
}
