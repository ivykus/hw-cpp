#include <algorithm>
#include <fstream>
#include <iostream>
#include <ostream>
#include <string>
#include <vector>

#include "ip_filter.h"

int ip_filter::test_function() { return 42; }

// ("",  '.') -> [""]
// ("11", '.') -> ["11"]
// ("..", '.') -> ["", "", ""]
// ("11.", '.') -> ["11", ""]
// (".11", '.') -> ["", "11"]
// ("11.22", '.') -> ["11", "22"]
ip_filter::ip_t ip_filter::split(const std::string &str, char d) {
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

int ip_filter::read_file(ip_filter::ip_pool_t &ip_pool, const char *file_name) {
  std::ifstream ifs;
  ifs.open(file_name);

  if (!ifs.is_open()) {
    std::cerr << "Couldn't open file: " << file_name << std::endl;
    return 1;
  }

  for (std::string line; std::getline(ifs, line);) {
    auto ip = split(line, '\t');
    ip_pool.push_back(split(ip.at(0), '.'));
  }

  ifs.close();

  return 0;
}

int ip_filter::read_input(ip_filter::ip_pool_t &ip_pool) {
  for (std::string line; std::getline(std::cin, line);) {
    auto v = split(line, '\t');
    ip_pool.push_back(split(v.at(0), '.'));
  }
  return 0;
}

static void print_ip(const ip_filter::ip_t &ip, std::ostream &os) {
  for (auto ip_part = ip.cbegin(); ip_part != ip.cend(); ++ip_part) {
    if (ip_part != ip.cbegin()) {
      os << ".";
    }
    os << *ip_part;
  }
  os << std::endl;
}

static void print_ip(ip_filter::ip_pool_t_const_it ip_it,
std::ostream &os) {
    for (auto ip_part = ip_it->cbegin(); ip_part != ip_it->cend(); ++ip_part) {
      if (ip_part != ip_it->cbegin()) {
        os << ".";
      }
      os << *ip_part;
    }
    os << std::endl;
}

// void ip_filter::print_ip_pool(const ip_filter::ip_pool_t &ip_pool,
//                               std::ostream &os) {
//   for (auto ip = ip_pool.cbegin(); ip != ip_pool.cend(); ++ip) {
//     for (auto ip_part = ip->cbegin(); ip_part != ip->cend(); ++ip_part) {
//       if (ip_part != ip->cbegin()) {
//         os << ".";
//       }
//       os << *ip_part;
//     }
//     os << std::endl;
//   }
// }


void ip_filter::print_ip_pool(const ip_filter::ip_pool_t &ip_pool,
                              std::ostream &os) {
  for (auto ip = ip_pool.cbegin(); ip != ip_pool.cend(); ++ip) {
    print_ip(ip, os);
  }
}

void ip_filter::rev_lexi_sort(ip_filter::ip_pool_t &ip_pool) {
  auto cmp = [](const std::vector<std::string> &lhs,
                const std::vector<std::string> &rhs) {
    auto lhs_it = lhs.cbegin();
    auto rhs_it = rhs.cbegin();
    while (lhs_it != lhs.cend() && rhs_it != rhs.cend()) {
      if (std::stoi(*rhs_it) == std::stoi(*lhs_it)) {
        ++lhs_it;
        ++rhs_it;
      } else {
        return std::stoi(*rhs_it) < std::stoi(*lhs_it);
      }
    }

    return false;
  };

  std::sort(ip_pool.begin(), ip_pool.end(), cmp);
}

void ip_filter::print_filtered_by_any(const ip_filter::ip_pool_t &ip_pool,
                                  std::ostream &os, int val) {
  for(auto it = ip_pool.cbegin(); it != ip_pool.cend(); ++it) {
    for (auto part = (*it).cbegin(); part != (*it).cend(); ++part) {
      if (std::stoi(*part) == val) {
        print_ip(it, os);
        break;
      }
    }
  }
  os << std::endl;
}

void ip_filter::print_filtered_by(const ip_filter::ip_pool_t &ip_pool,
                                  std::ostream &os, int val) {
  for(auto it = ip_pool.cbegin(); it != ip_pool.cend(); ++it) {
    if (std::stoi((*it).at(0)) == val) {
      print_ip(it, os);
    }
  }
}
void ip_filter::print_filtered_by(const ip_filter::ip_pool_t &ip_pool,
                                  std::ostream &os, int val1, int val2) {
  for(auto it = ip_pool.cbegin(); it != ip_pool.cend(); ++it) {
    if (std::stoi((*it).at(0)) == val1 && std::stoi((*it).at(1)) == val2) {
      print_ip(it, os);
    }
  }
}