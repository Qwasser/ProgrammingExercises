/* Problem 3.4
 * Write a program that solves HanoiTowers
 */
#include <cassert>
#include <iostream>

#include "SimpleDataStructures/simple_stack.h"

class HanoiTowers {
public:
    HanoiTowers(size_t N) {
        problem_size = N;
        for (size_t i = N; i > 0; --i) {
            stack_A.push(i);
        }
    }

    void run(bool verbose = false) {
        print_states = verbose;
        movePyramid(problem_size, stack_A, stack_C, stack_B);
    }

private:
    void printState() {
        printStack(stack_A);
        printStack(stack_B);
        printStack(stack_C);
        std::cout << "-----------" << std::endl;
    }

    void printStack(SimpleStack<size_t> & stack) {
        std::vector<size_t> vec = stack.toVector();
        for (auto itr = vec.rbegin(); itr != vec.rend(); ++itr) {
            std::cout << *itr << " ";
        }
        std::cout << std::endl;
    }

    size_t problem_size;
    bool print_states = false;

    SimpleStack<size_t> stack_A;
    SimpleStack<size_t> stack_B;
    SimpleStack<size_t> stack_C;

    void moveSingle(SimpleStack<size_t> & from, SimpleStack<size_t> & to) {
        assert(!from.isEmpty());
        assert(from.peek() < to.peek());

        to.push(from.pop());

        if(print_states) {
            printState();
        }
    }

    void movePyramid(size_t pyramid_size,
                     SimpleStack<size_t> & from,
                     SimpleStack<size_t> & to,
                     SimpleStack<size_t> & temp) {
        if (pyramid_size == 0) {
            return;
        }

        movePyramid(pyramid_size - 1, from, temp, to);
        moveSingle(from, to);
        movePyramid(pyramid_size - 1, temp, to, from);
    }
};

int main(int argc, char **argv) {
    HanoiTowers towers(10);
    towers.run(true);
}
