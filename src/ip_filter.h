#pragma once

#include <string>
#include <vector>

namespace ip_filter {
int test_function();

std::vector<std::string> split(const std::string &str, char d);

int read_file(std::vector<std::vector<std::string>>& ip_pool,
              const char *file_name);
} // namespace ip_filter
