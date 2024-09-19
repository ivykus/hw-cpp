#include <fstream>
#include <string>
#include <vector>
#include <iostream>

#include "ip_filter.h"

int ip_filter::test_function() { return 42; }

// ("",  '.') -> [""]
// ("11", '.') -> ["11"]
// ("..", '.') -> ["", "", ""]
// ("11.", '.') -> ["11", ""]
// (".11", '.') -> ["", "11"]
// ("11.22", '.') -> ["11", "22"]
std::vector<std::string> ip_filter::split(const std::string &str, char d) {
  std::vector<std::string> r;

  std::string::size_type start = 0;
  std::string::size_type stop = str.find_first_of(d);
  while (stop != std::string::npos) {
    r.push_back(str.substr(start, stop - start));

    start = stop + 1;
    stop = str.find_first_of(d, start);
  }

  r.push_back(str.substr(start));

  return r;
}

int ip_filter::read_file(std::vector<std::vector<std::string>>& ip_pool, const char *file_name) 
{
    std::ifstream ifs;
    ifs.open(file_name);


    if(!ifs.is_open()) {
        std::cerr << "Couldn't open file: " << file_name << std::endl;
        return 1;
    }

    for(std::string line; std::getline(ifs, line);) {
        auto ip = split(line, '\t');
        ip_pool.push_back(split(ip.at(0), '.'));
    }

    ifs.close();

    return 0;
}
