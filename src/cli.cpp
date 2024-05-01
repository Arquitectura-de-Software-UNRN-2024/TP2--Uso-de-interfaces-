#include "../include/cli.hpp"
#include "../include/dynamic_mem_stack.hpp"
#include "../include/dynamic_mem_stack_resizeable.hpp"
#include "../include/fixed_array_stack.hpp"
#include <string>

namespace cli {

const char *help_str = "aiuda";

bool needs_help(int argc, char *argv[]) {
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "--help") == 0 || strcmp(argv[i], "-h") == 0) {
            return true;
        }
    }
    return false;
}

Stack *parse_args(int argc, char *argv[]) {
    if (argc > 1) {
        if (strcmp(argv[1], "-f") == 0) {
            return new FixedArrayStack();
        }
        int n = 0;
        if (argc > 2) {
            try {
                n = std::stoi(argv[2]);
            } catch (std::exception &e) {
                n = 0;
            }
        }
        if (strcmp(argv[1], "-d") == 0) {
            return n < 1 ? new DynamicMemStack() : new DynamicMemStack(n);
        }
        if (strcmp(argv[1], "-r") == 0) {
            return n < 1 ? new DynamicMemStackResizeable()
                         : new DynamicMemStackResizeable(n);
        }
    }
    return new FixedArrayStack();
}

} // namespace cli
