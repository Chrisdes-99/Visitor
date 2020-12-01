#ifndef __ADD_HPP__
#define __ADD_HPP__

#include "base.hpp"
#include "op.hpp"
#include "../iterator.hpp"

#include <string>

class Add : public Base {
    private:
        Base* left = nullptr;
        Base* right = nullptr;

    public:
        Add(Base* left_child, Base* right_child) {this->left = left_child; this->right = right_child; }
        //Add(MockOp* left, MockOp* right) : Base() { };
        virtual double evaluate() { return left->evaluate() + right->evaluate(); }
        //virtual double evaluate() {return 5; }
        virtual std::string stringify() { return std::to_string(left->evaluate()) + " + " + std::to_string(right->evaluate()); }

        //NEW
        virtual Iterator* create_iterator() { return new BinaryIterator(this); }

        virtual Base* get_left() { return this->left; }

        virtual Base* get_right() { return this->right; }
};

#endif //__ADD_HPP__
