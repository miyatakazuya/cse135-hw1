#include <iostream>
#include <ctime>
#include <cstdlib>

int main(int argc, char* argv[], char* envp[]) {
    std::cout << "Content-type: text/html\r\n\r\n";

    std::cout << "<!DOCTYPE html>\n";
    std::cout << "<html>\n";
    std::cout << "<head>\n";
    std::cout << "<title>C++ Hello World - By Kazuya Miyata CSE135!</title>\n";
    std::cout << "</head>\n";
    std::cout << "<body>\n";
    std::cout << "<h2>Hello World from C++!</h2><hr/>\n";
    time_t timestamp;
    time(&timestamp);
    std::cout << "Today is " << ctime(&timestamp) << "<br>";
    std::cout << "Your IP Address is: " << getenv("REMOTE_ADDR") << "<br>";
    std::cout << "</body>\n";
    std::cout << "</html>\n";

    return 0;
}