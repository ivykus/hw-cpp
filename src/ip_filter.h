#pragma once

#include <string>
#include <vector>

namespace ip_filter {
int test_function();

using ip_pool_t = std::vector<std::vector<std::string>>;
using ip_t = std::vector<std::string>;
using ip_pool_t_const_it = std::vector<std::vector<std::string>>::const_iterator;

std::vector<std::string> split(const std::string &str, char d);

int read_file(ip_pool_t& ip_pool,
              const char *file_name);
int read_input(ip_pool_t& ip_pool);
void print_ip_pool(const ip_pool_t &ip_pool, std::ostream &os);

void rev_lexi_sort(ip_pool_t &ip_pool);

void print_filtered_by(const ip_pool_t &ip_pool, std::ostream &os, int val1);
void print_filtered_by(const ip_pool_t &ip_pool, std::ostream &os, int val1, int val2);

void print_filtered_by_any(const ip_pool_t &ip_pool, std::ostream &os, int val);
} // namespace ip_filter
