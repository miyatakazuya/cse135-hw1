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
    cout << "<!DOCTYPE html>" << endl;
    cout << "<html><head><title>C++ POST Request Echo</title>" << endl;
    cout << "</head><body><h1 align=\"center\">C++ POST Request Echo</h1>" << endl;
    cout << "<hr>" << endl;
    
    string body;
    char c;
    while(cin.get(c)) {
        body += c;
    }
    
    cout << "<b>Message Body:</b><br />" << endl;
    cout << "<ul>" << endl;
    
    if (!body.empty()) {
        stringstream ss(body);
        string segment;
        while(getline(ss, segment, '&')) {
             stringstream ss2(segment);
             string key, val;
             if (getline(ss2, key, '=') && getline(ss2, val)) {
                 cout << "<li>" << urlDecode(key) << " = " << urlDecode(val) << "</li>" << endl;
             }
        }
    }
    cout << "</ul>" << endl;
    cout << "</body></html>" << endl;
    return 0;
}
