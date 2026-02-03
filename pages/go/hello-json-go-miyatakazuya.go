package main

import (
	"fmt"
	"os"
	"time"
	"encoding/json"
)

type Response struct {
	Message string `json:"message"`
	Time    string `json:"time"`
	IP      string `json:"ip"`
}

func main() {
	fmt.Println("Cache-Control: no-cache")
	fmt.Println("Content-Type: application/json\n\n")
	
	r := Response{
		Message: "Go - Hello World json",
		Time:    time.Now().Format("2006-01-02 15:04:05"),
		IP:      os.Getenv("REMOTE_ADDR"),
	}

	jsonData, err := json.Marshal(r)
	if err != nil {
		fmt.Println("Error marshaling JSON:", err)
		return
	}

	fmt.Printf("%s\n", jsonData)
}