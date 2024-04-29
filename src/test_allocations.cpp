#include <criterion/alloc.h>
#include <cstddef>
#include <iostream>

extern "C" {

void *__wrap_malloc(size_t size) { return cr_malloc(size); }

void *__wrap_calloc(size_t nmemb, size_t size) {
  return cr_calloc(nmemb, size);
}

void *__wrap_realloc(void *ptr, size_t size) { return cr_realloc(ptr, size); }

void __wrap_free(void *ptr) { 
  std::cout << "free\n";
	return cr_free(ptr); }
}

void *operator new(std::size_t size) {
  std::cout << "new\n";
  return cr_malloc(size);
}

void *operator new[](std::size_t count) {
  std::cout << "new[]\n";
  return cr_malloc(count);
}

void operator delete(void *ptr) noexcept {
  std::cout << "delete\n";
  return cr_free(ptr);
}

void operator delete[](void *ptr) noexcept {
  std::cout << "delete[]\n";
  return cr_free(ptr);
}
