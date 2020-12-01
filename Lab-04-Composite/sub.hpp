#ifndef __SUB_HPP__
#define __SUB_HPP__

#include "base.hpp"
#include "op.hpp"

class Sub : public Base {
    private:
        Base* left = nullptr;
        Base* right = nullptr;

    public:
        Sub(Base* left_child, Base* right_child) {this->left = left_child; this->right = right_child; }
        virtual double evaluate() { return left->evaluate() - right->evaluate(); }
        virtual std::string stringify() { return std::to_string(left->evaluate()) + " - " + std::to_string(right->evaluate()); }

        //NEW
        virtual Iterator* create_iterator() { return new BinaryIterator(this); }

        virtual Base* get_left() { return this->left; }

        virtual Base* get_right() { return this->right; }

        virtual void accept(CountVisitor* var){var->visit_sub();}
};

#endif //__SUB_HPP__
