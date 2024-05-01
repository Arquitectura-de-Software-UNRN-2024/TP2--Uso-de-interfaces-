#include "stack_interface.hpp"
#include <cstring>

namespace cli {

extern const char *help_str;

bool needs_help(int argc, char *argv[]);
Stack *parse_args(int argc, char *argv[]);

} // namespace cli
