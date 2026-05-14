// Copyright 2025 NNTU-CS
#include <string>
#include "alg.h"
#include "tstack.h"

int getPriority(char ch) {
  if (ch == '(') return 0;
  if (ch == '+' || ch == '-') return 1;
  if (ch == '*' || ch == '/') return 2;
  return -1;
}

std::string infx2pstfx(const std::string& inf) {
  std::string pstfx = "";
  TStack<char, 100> stack;
  bool last_was_digit = false;
  for (size_t i = 0; i < inf.length(); ++i) {
    char ch = inf[i];
    if (ch >= '0' && ch <= '9') {
      pstfx += ch;
      last_was_digit = true;
    } else {
      if (last_was_digit) {
        pstfx += ' ';
        last_was_digit = false;
      }
      if (ch == '(') {
        stack.push(ch);
      } else if (ch == ')') {
        while (!stack.isEmpty() && stack.get() != '(') {
          pstfx += stack.pop();
          pstfx += ' ';
        }
        if (!stack.isEmpty()) {
          stack.pop();
        }
      } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
        while (!stack.isEmpty() &&
               getPriority(stack.get()) >= getPriority(ch)) {
          pstfx += stack.pop();
          pstfx += ' ';
        }
        stack.push(ch);
      }
    }
  }
  if (last_was_digit) {
    pstfx += ' ';
  }
  while (!stack.isEmpty()) {
    pstfx += stack.pop();
    pstfx += ' ';
  }
  if (!pstfx.empty() && pstfx.back() == ' ') {
    pstfx.pop_back();
  }
  return pstfx;
}

int eval(const std::string& post) {
  TStack<int, 100> stack;
  int num = 0;
  bool is_parsing_num = false;
  for (size_t i = 0; i < post.length(); ++i) {
    char ch = post[i];
    if (ch >= '0' && ch <= '9') {
      num = num * 10 + (ch - '0');
      is_parsing_num = true;
    } else if (ch == ' ') {
      if (is_parsing_num) {
        stack.push(num);
        num = 0;
        is_parsing_num = false;
      }
    } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
      if (is_parsing_num) {
        stack.push(num);
        num = 0;
        is_parsing_num = false;
      }
      int v2 = stack.pop();
      int v1 = stack.pop();
      if (ch == '+') stack.push(v1 + v2);
      else if (ch == '-') stack.push(v1 - v2);
      else if (ch == '*') stack.push(v1 * v2);
      else if (ch == '/') stack.push(v1 / v2);
    }
  }
  if (is_parsing_num) {
    stack.push(num);
  }
  return stack.pop();
}
