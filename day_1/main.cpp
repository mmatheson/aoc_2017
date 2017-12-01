#include <iostream>
#include <fstream>

int main() {
  std::ifstream inputStream;
  inputStream.open("../input/intput.txt");

  std::string inputString;
  while(inputStream >> inputString) {
    std::cout << inputString << std::endl;
  }

  std::cout << std::endl << "END" << std::endl;
}
