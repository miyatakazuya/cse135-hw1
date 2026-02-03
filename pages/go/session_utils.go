package main

import (
    "os"
    "io/ioutil"
    "math/rand"
    "time"
)

const SESS_DIR = "/tmp/"

func GetSessionData(id string) string {
    if id == "" { return "" }
    // Sanitize ID
    for _, c := range id {
        if !((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            return ""
        }
    }
    
    data, err := ioutil.ReadFile(SESS_DIR + "sess_" + id)
    if err != nil { consoleLog("Error reading: " + err.Error()); return "" }
    return string(data)
}

func SetSessionData(id string, data string) {
    if id == "" { return }
    ioutil.WriteFile(SESS_DIR + "sess_" + id, []byte(data), 0600)
}

func DestroySession(id string) {
    if id == "" { return }
    os.Remove(SESS_DIR + "sess_" + id)
}

func GenerateSessionID() string {
    rand.Seed(time.Now().UnixNano())
    chars := "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"
    b := make([]byte, 16)
    for i := range b {
        b[i] = chars[rand.Intn(len(chars))]
    }
    return string(b)
}

func consoleLog(msg string) {
    // Write to stderr so it shows in error log, not stdout
    os.Stderr.WriteString(msg + "\n")
}
