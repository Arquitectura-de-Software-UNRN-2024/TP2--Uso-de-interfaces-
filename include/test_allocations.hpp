#include <cstddef>

void *operator new(std::size_t size);

void *operator new[](std::size_t count);

void operator delete(void *ptr) noexcept;

void operator delete[](void *ptr) noexcept;
