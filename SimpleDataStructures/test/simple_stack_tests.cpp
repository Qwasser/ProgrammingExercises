#include <stdexcept>
#include <iostream>

#include "gtest/gtest.h"

#include <SimpleDataStructures/simple_stack.h>


TEST(simple_stack_test, empty_stack_exceptions)
{
    SimpleStack<int> stack;
    try {
        stack.Pop();
        FAIL() << "Expected std::out_of_range";
    }
    catch(std::out_of_range const & err) {

    }
    catch(...) {
        FAIL() << "Expected std::out_of_range";
    }

    try {
        stack.Peek();
        FAIL() << "Expected std::out_of_range";
    }
    catch(std::out_of_range const & err) {

    }
    catch(...) {
        FAIL() << "Expected std::out_of_range";
    }
}

TEST(simple_stack_test, stack_push_and_pop)
{
    SimpleStack<int> stack;
    ASSERT_TRUE(stack.is_empty());
    ASSERT_EQ(0, stack.size());

    int test_item = 1;
    stack.Push(test_item);
    ASSERT_FALSE(stack.is_empty());
    ASSERT_EQ(1, stack.size());

    int pop_item = stack.Pop();
    ASSERT_TRUE(stack.is_empty());
    ASSERT_EQ(0, stack.size());
    ASSERT_EQ(test_item, pop_item);
}

TEST(simple_stack_test, stack_peek)
{
    SimpleStack<int> stack;

    int test_item = 8;
    stack.Push(test_item);

    int peek_item = stack.Peek();
    ASSERT_FALSE(stack.is_empty());
    ASSERT_EQ(1, stack.size());
    ASSERT_EQ(test_item, peek_item);
}

class MockWithCopyException {
public:

   MockWithCopyException() {}

    MockWithCopyException (const MockWithCopyException & other) {
        throw std::logic_error("Copied secind time!");
    }
};

TEST(simple_stack_test, pop_exception_safety)
{
    SimpleStack<MockWithCopyException> stack;

    stack.Push(MockWithCopyException());
    ASSERT_EQ(1, stack.size());

    try {
        stack.Pop();
        FAIL() << "Expected std::logical_error";
    }
    catch(std::logic_error const & err) {

    }
    catch(...) {
        FAIL() << "Expected std::logical_error";
    }

    ASSERT_EQ(0, stack.size());

}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
