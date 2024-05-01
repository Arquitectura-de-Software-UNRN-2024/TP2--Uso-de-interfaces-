#include "../../include/cli.hpp"
#include "../../include/dummy_stackable_object.hpp"
#include "../../include/stack_user.hpp"
#include <cstring>
#include <iostream>

int main(int argc, char *argv[]) {
  if (cli::needs_help(argc, argv)) {
    std::cout << cli::help_str << std::endl;
    exit(0);
  }
  StackUser stack(cli::parse_args(argc, argv));
  DummyStackableObject obj1;
  stack.push(&obj1);
  DummyStackableObject obj2;
  stack.push(&obj2);
  DummyStackableObject obj3;
  stack.push(&obj3);
  DummyStackableObject obj4;
  stack.push(&obj4);
  DummyStackableObject obj5;
  stack.push(&obj5);
  DummyStackableObject obj6;
  stack.push(&obj6);
  stack.print();
  return 0;
}
