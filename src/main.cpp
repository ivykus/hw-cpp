#include <cassert>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

#include "ip_filter.h"


int main(int argc, char const *argv[]) {
  try {
    std::vector<std::vector<std::string>> ip_pool;

    if (argc == 2) {
      ip_filter::read_file(ip_pool, argv[1]);
    } else {
        ip_filter::read_input(ip_pool);
    }

    std::ostream &os = std::cout;

    // TODO reverse lexicographically sort
    // ip_filter::print_ip_pool(ip_pool, std::cout);

    // std::cout << "Sorted: " << std::endl;
    ip_filter::rev_lexi_sort(ip_pool);

    ip_filter::print_ip_pool(ip_pool, std::cout);


    // 222.173.235.246
    // 222.130.177.64
    // 222.82.198.61
    // ...
    // 1.70.44.170
    // 1.29.168.152
    // 1.1.234.8

    // std::cout << " --------------------" << std::endl;

    // TODO filter by first byte and output
    // ip = filter(1)
    // std::cout << "Filtered by first" << std::endl;
    ip_filter::print_filtered_by(ip_pool,os, 1);

    // 1.231.69.33
    // 1.87.203.225
    // 1.70.44.170
    // 1.29.168.152
    // 1.1.234.8
    // std::cout << " --------------------" << std::endl;


    // TODO filter by first and second bytes and output
    // ip = filter(46, 70)
    // std::cout << "Filtered by 46 and 70" << std::endl;
    ip_filter::print_filtered_by(ip_pool, os, 46, 70);

    // 46.70.225.39
    // 46.70.147.26
    // 46.70.113.73
    // 46.70.29.76

    // TODO filter by any byte and output
    // std::cout << "Filtererd by any 46" << std::endl;
    ip_filter::print_filtered_by_any(ip_pool, os, 46);
    // ip = filter_any(46)
    // std::cout << " --------------------" << std::endl;


    // 186.204.34.46
    // 186.46.222.194
    // 185.46.87.231
    // 185.46.86.132
    // 185.46.86.131
    // 185.46.86.131
    // 185.46.86.22
    // 185.46.85.204
    // 185.46.85.78
    // 68.46.218.208
    // 46.251.197.23
    // 46.223.254.56
    // 46.223.254.56
    // 46.182.19.219
    // 46.161.63.66
    // 46.161.61.51
    // 46.161.60.92
    // 46.161.60.35
    // 46.161.58.202
    // 46.161.56.241
    // 46.161.56.203
    // 46.161.56.174
    // 46.161.56.106
    // 46.161.56.106
    // 46.101.163.119
    // 46.101.127.145
    // 46.70.225.39
    // 46.70.147.26
    // 46.70.113.73
    // 46.70.29.76
    // 46.55.46.98
    // 46.49.43.85
    // 39.46.86.85
    // 5.189.203.46
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
  }

  return 0;
}
