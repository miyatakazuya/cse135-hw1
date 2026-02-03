#include "session_utils.h"

int main() {
    // We need to parse POST data if method is POST
    string method = getenv("REQUEST_METHOD") ? getenv("REQUEST_METHOD") : "";
    
    if (method == "POST") {
        string body = get_post_body();
        string user = get_post_param(body, "username");
        
        string new_id = generate_session_id();
        set_session_data(new_id, user);
        
        // Redirect with Dirty URL
        cout << "Location: /cgi-bin/session-cpp.cgi?session_id=" << new_id << "\r\n\r\n";
        return 0;
    }
    
    cout << "Content-type: text/html\r\n\r\n";
    cout << "<!DOCTYPE html><html><head><title>C++ Login</title></head><body>";
    cout << "<h1>Set Username (Login)</h1>";
    cout << "<form method='POST' action='/cgi-bin/login-cpp.cgi'>";
    cout << "<label>Enter Username: <input type='text' name='username' required></label>";
    cout << "<button type='submit'>Start Session</button>";
    cout << "</form>";
    cout << "<p><a href='/cgi-bin/session-cpp.cgi'>Back to Session Page</a></p>";
    cout << "</body></html>";
    
    return 0;
}
