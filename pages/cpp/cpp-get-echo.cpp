#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <sstream>
#include <cstdio>

using namespace std;

string urlDecode(string str) {
    string ret;
    char ch;
    int i, ii;
    for (i=0; i<str.length(); i++) {
        if (str[i] != '%') {
            if(str[i] == '+') ret += ' ';
            else ret += str[i];
        } else {
            sscanf(str.substr(i + 1, 2).c_str(), "%x", &ii);
            ch = static_cast<char>(ii);
            ret += ch;
            i = i + 2;
        }
    }
    return ret;
}

int main() {
    cout << "Cache-Control: no-cache\r\n";
    cout << "Content-type: text/html\r\n\r\n";
    cout << "<!DOCTYPE html><html><head><title>GET Request Echo</title></head><body><h1 align=\"center\">Get Request Echo</h1><hr>" << endl;
    
    char* query_str = getenv("QUERY_STRING");
    string query = query_str ? query_str : "";
    
    cout << "<b>Query String:</b> " << query << "<br />" << endl;
    
    if (!query.empty()) {
        stringstream ss(query);
        string segment;
        while(getline(ss, segment, '&')) {
             stringstream ss2(segment);
             string key, val;
             if (getline(ss2, key, '=') && getline(ss2, val)) {
                 cout << urlDecode(key) << " = " << urlDecode(val) << "<br/>" << endl;
             }
        }
    }
    
    cout << "</body></html>" << endl;
    return 0;
}
