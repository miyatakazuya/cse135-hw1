#include <iostream>
#include <cstdlib>
#include <string>
#include <unistd.h>
#include <ctime>

using namespace std;

int main() {
    cout << "Cache-Control: no-cache\r\n";
    cout << "Content-type: text/html\r\n\r\n";
    cout << "<!DOCTYPE html><html><head><title>General Request Echo</title></head><body><h1 align=\"center\">General Request Echo</h1><hr>" << endl;
    
    cout << "<p><b>HTTP Protocol:</b> " << (getenv("SERVER_PROTOCOL") ? getenv("SERVER_PROTOCOL") : "") << "</p>" << endl;
    cout << "<p><b>HTTP Method:</b> " << (getenv("REQUEST_METHOD") ? getenv("REQUEST_METHOD") : "") << "</p>" << endl;
    cout << "<p><b>Query String:</b> " << (getenv("QUERY_STRING") ? getenv("QUERY_STRING") : "") << "</p>" << endl;

    char hostname[1024];
    gethostname(hostname, 1024);
    cout << "<p><b>Hostname:</b> " << hostname << "</p>" << endl;

    time_t now = time(0);
    // remove newline from ctime often returned
    string dt = ctime(&now);
    if (!dt.empty() && dt[dt.length()-1] == '\n') {
        dt.erase(dt.length()-1);
    }
    cout << "<p><b>Date/Time:</b> " << dt << "</p>" << endl;

    cout << "<p><b>User Agent:</b> " << (getenv("HTTP_USER_AGENT") ? getenv("HTTP_USER_AGENT") : "") << "</p>" << endl;
    cout << "<p><b>Remote Address:</b> " << (getenv("REMOTE_ADDR") ? getenv("REMOTE_ADDR") : "") << "</p>" << endl;

    string body;
    char c;
    while(cin.get(c)) {
        body += c;
    }
    cout << "<p><b>Message Body:</b> " << body << "</p>" << endl;

    cout << "</body></html>" << endl;
    return 0;
}
