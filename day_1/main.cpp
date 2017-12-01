#include <iostream>
#include <fstream>

int main() {
  std::ifstream inputStream("input/input.txt");
  std::string str((std::istreambuf_iterator<char>(inputStream)),
                 std::istreambuf_iterator<char>());

  size_t sum = 0;

  for(size_t i = 0; i < str.size() - 1; ++i) {
   if(str.at(i) == str.at(i + 1)) {
     std::cout << str.at(i) << " = " << str.at(i + 1) << std :: endl;
     sum += static_cast<uint8_t>(str.at(i) - '0');
   }
  }

  if(str.at(0) == str.at(str.size() - 1)) {
    std::cout << str.at(0) << " = " << str.at(str.size() - 1) << std :: endl;
    sum += str.at(0) - '0';
  } else {
    std::cout << str.at(0) << " ne " << str.at(str.size() - 1) << std :: endl;
  }

  std::cout << "SUM: " << std::to_string(sum) << std::endl;
}
