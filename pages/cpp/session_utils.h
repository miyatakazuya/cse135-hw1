#ifndef SESSION_UTILS_H
#define SESSION_UTILS_H

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <vector>
#include <sstream>

using namespace std;

// Helper to get query params
string get_query_param(string param_name) {
    char* qs = getenv("QUERY_STRING");
    if (!qs) return "";
    string query = qs;
    stringstream ss(query);
    string segment;
    while(getline(ss, segment, '&')) {
        stringstream ss2(segment);
        string key, val;
        if (getline(ss2, key, '=') && getline(ss2, val)) {
            if (key == param_name) return val;
        }
    }
    return "";
}

// Helper to get POST body data
string get_post_body() {
    string body;
    char c;
    while(cin.get(c)) {
        body += c;
    }
    return body;
}

// Helper to parse POST body for a key
string get_post_param(string body, string param_name) {
    if (body.empty()) return "";
    stringstream ss(body);
    string segment;
    while(getline(ss, segment, '&')) {
        stringstream ss2(segment);
        string key, val;
        if (getline(ss2, key, '=') && getline(ss2, val)) {
            if (key == param_name) return val;
        }
    }
    return "";
}

// Generate a random session ID
string generate_session_id() {
    srand(time(0) + rand());
    string chars = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    string id = "";
    for(int i=0; i<16; ++i) {
        id += chars[rand() % chars.length()];
    }
    return id;
}

// Setup paths
const string SESS_DIR = "/tmp/";

string get_session_file_path(string id) {
    // Basic sanitization
    for(char c : id) {
        if(!isalnum(c)) return "";
    }
    return SESS_DIR + "sess_" + id;
}

// Read username from session file
string get_session_data(string id) {
    if (id.empty()) return "";
    string path = get_session_file_path(id);
    if(path.empty()) return "";
    
    ifstream infile(path.c_str());
    if (infile.good()) {
        string data;
        getline(infile, data);
        return data; // Assuming file just contains username
    }
    return "";
}

// Write username to session file
void set_session_data(string id, string username) {
    if (id.empty()) return;
    string path = get_session_file_path(id);
    if(path.empty()) return;
    
    ofstream outfile(path.c_str());
    outfile << username;
    outfile.close();
}

// Delete session
void destroy_session(string id) {
    if (id.empty()) return;
    string path = get_session_file_path(id);
    if(path.empty()) return;
    remove(path.c_str());
}

#endif
