#include <cassert>
#include <cstdlib>
#include <iostream>



int main(int argc, char const *argv[]) {
  try {
    std::cout << "Hithere!" << std::endl;;
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
  }

  return 0;
}
