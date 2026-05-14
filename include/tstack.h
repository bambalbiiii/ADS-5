// Copyright 2025 NNTU-CS
#ifndef INCLUDE_TSTACK_H_
#define INCLUDE_TSTACK_H_

template<typename T, int size>
class TStack {
 private:
  T data[size];
  int top;
 public:
  TStack() : top(-1) {}
  void push(T value) {
    if (top < size - 1) data[++top] = value;
  }
  T pop() {
    return (top >= 0) ? data[top--] : T();
  }
  T get() const {
    return (top >= 0) ? data[top] : T();
  }
  bool isEmpty() const {
    return top == -1;
  }
};
#endif  // INCLUDE_TSTACK_H_
