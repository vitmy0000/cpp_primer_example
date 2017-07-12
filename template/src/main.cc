#include <iostream>

#include "my_stack.hh"

using namespace my_template;

int main(void)
{
  MyStack<int> int_stack;
  int_stack.push(1);
  int_stack.push(2);
  int_stack.push(3);
  std::cout << int_stack.pop() << std::endl;

  MyStack<char> char_stack;
  char_stack.push('A');
  char_stack.push('B');
  char_stack.push('C');
  std::cout << char_stack.pop() << std::endl;
  return 0;
}
