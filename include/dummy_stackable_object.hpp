/**
 * @file dummy_stackable_object.hpp
 * @author Pojmaevich Mirko (mirkopoj@gmail.com)
 *         Torletti Lara (lara.a.torletti@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-05-01
 *
 * @copyright Copyright (c) 2024
 *
 */
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
