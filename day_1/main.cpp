#include <iostream>
#include <fstream>

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

  std::string str((std::istreambuf_iterator<char>(inputStream)),
                 std::istreambuf_iterator<char>());

  uint64_t sum = 0;
  for(size_t i = 0; i < str.size() - 1; ++i) {
   if(str[i] == str[i + 1]) {
     sum += static_cast<uint8_t>(str[i] - '0');
   }
  }

  if(str[0] == str[str.size() - 1]) {
    sum += str[0] - '0';
  }

  std::cout << "SUM: " << std::to_string(sum) << std::endl;
}
