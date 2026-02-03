#include <iostream>

int main(int argc, char* argv[], char* envp[]) {
    std::cout << "Content-type: text/html\r\n\r\n";
    std::cout << "<!DOCTYPE html>" << std::endl;
    std::cout << "<html>" << std::endl;
    std::cout << "<head>" << std::endl;
    std::cout << "<title>C++ - Environment Variables</title>" << std::endl;
    std::cout << "</head>" << std::endl;
    std::cout << "<body>" << std::endl;
    std::cout << "<h1>C++ - Environment Variables</h1><hr/>" << std::endl;
    std::cout << "<pre>" << std::endl;
    
    for (char** env = envp; *env != 0; ++env) {
        std::cout << *env << std::endl;
    }
    std::cout << "</pre>" << std::endl;
    std::cout << "</body>" << std::endl;
    std::cout << "</html>" << std::endl;
    return 0;
}