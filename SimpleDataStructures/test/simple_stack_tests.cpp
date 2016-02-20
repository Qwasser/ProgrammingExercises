#include "gtest/gtest.h"

#include <simple_stack.h>


TEST(simple_stack_test, empty_stack_exceptions)
{
    SimpleStack<int> stack;
    try {
        stack.pop();
        FAIL() << "Expected std::out_of_range";
    }
    catch(std::out_of_range const & err) {

    }
    catch(...) {
        FAIL() << "Expected std::out_of_range";
    }

    try {
        stack.peek();
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
    ASSERT_TRUE(stack.isEmpty());
    ASSERT_EQ(0, stack.size());

    int test_item = 1;
    stack.push(test_item);
    ASSERT_FALSE(stack.isEmpty());
    ASSERT_EQ(1, stack.size());

    int pop_item = stack.pop();
    ASSERT_TRUE(stack.isEmpty());
    ASSERT_EQ(0, stack.size());
    ASSERT_EQ(test_item, pop_item);
}

TEST(simple_stack_test, stack_peek)
{
    SimpleStack<int> stack;

    int test_item = 8;
    stack.push(test_item);

    int peek_item = stack.peek();
    ASSERT_FALSE(stack.isEmpty());
    ASSERT_EQ(1, stack.size());
    ASSERT_EQ(test_item, peek_item);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}