#include <iostream>
#include <fstream>
#include <sstream>
#include <limits>
#include <cassert>

int main(int argc, char** argv) {
  if(argc != 2) {
    std::cout << "Expected 1 arg, got " << std::to_string(argc - 1) << std::endl;
    return 1;
  }

  std::string filename(argv[1]);
  std::cout << "Opening File: " << filename << std::endl;

  std::ifstream inputStream(filename);
  if(!inputStream.is_open()) {
    std::cout << "Failed to open file: " << filename << std::endl;
    return 1;
  }

  std::string line;
  unsigned int checksum = 0;
  while(std::getline(inputStream, line)) {
    std::stringstream linestream(line);
    unsigned int min = std::numeric_limits<unsigned int>::max();
    unsigned int max = 0;

    std::string word;
    while(linestream >> word) {
      unsigned int val = std::stoi(word);
      min = std::min(val, min);
      max = std::max(val, max);
    }

    checksum += (max - min);
  }

  std::cout << "Checksum: " << checksum << std::endl;
}
