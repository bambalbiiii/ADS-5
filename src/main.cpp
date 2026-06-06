// Copyright 2021 NNTU-CS
#include <iostream>
#include <string>

std::string infx2pstfx(const std::string& inf);
int eval(const std::string& post);

int main() {
  std::string expr = "(2+2)*(3-1)";
  std::string post = infx2pstfx(expr);
  std::cout << "infix:   " << expr << std::endl;
  std::cout << "postfix: " << post << std::endl;
  std::cout << "result:  " << eval(post) << std::endl;
  return 0;
}
