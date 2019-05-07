#include "lib/ConcordanceParser.h"
#include <fstream>
#include <iostream>

int main() {
  std::cout << "Please enter filename (fullpath or relative path): ";
  std::string filename;
  std::cin >> filename;
  std::ifstream file(filename, std::ios::in);
//  std::ifstream file("../files/smallPoem.txt", std::ios::in);
  if(file.is_open()) {
    auto parser = ConcordanceParser{std::move(file)};
    std::cout << parser.getConcordance();
  }
  else {
    std::cout << "Sorry, no files with the given filename was found.\n";
  }

  return 0;
}