#include "session_utils.h"

int main() {
    string sess_id = get_query_param("session_id");
    if (!sess_id.empty()) {
        destroy_session(sess_id);
    }
    
    // Redirect back to main page without ID
    cout << "Location: /cgi-bin/session-cpp.cgi\r\n\r\n";
    
    return 0;
}
