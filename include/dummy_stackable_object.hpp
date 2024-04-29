#include "stack_interface.hpp"

class DummyStackableObject : public StackableObject {
public:
  DummyStackableObject();
  DummyStackableObject(DummyStackableObject &&) = delete;
  DummyStackableObject(const DummyStackableObject &) = delete;
  DummyStackableObject &operator=(DummyStackableObject &&) = delete;
  DummyStackableObject &operator=(const DummyStackableObject &) = delete;
  ~DummyStackableObject() = default;

  virtual void print() override;

private:
  static int count;
  int id;
};
