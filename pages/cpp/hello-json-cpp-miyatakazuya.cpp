#include <iostream>
#include <ctime>
#include <cstdlib>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

int main(int argc, char* argv[], char* envp[]) {
    std::cout << "Cache-Control: no-cache\r\n";
    std::cout << "Content-type: application/json\r\n\r\n";
    time_t now = time(0);
    char buf[80];
    struct tm tstruct;
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", &tstruct);

    const char* ip = getenv("REMOTE_ADDR");
    std::string ip_str = (ip) ? ip : "";

    json j;
    j["message"] = "C++ - Hello World json";
    j["time"] = buf;
    j["ip"] = ip_str;

    std::cout << j.dump() << std::endl;

    return 0;
}