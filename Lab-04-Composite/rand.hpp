#ifndef __RAND_HPP__
#define __RAND_HPP__

#include "base.hpp"
#include <string>
#include <stdlib.h>


class Rand : public Base {

    private:
        double value;

    public:
        Rand() : value(rand() % 100) { }
        virtual double evaluate() { return value; }
        virtual std::string stringify() { return std::to_string(value); }

        //NEW
        virtual Iterator* create_iterator() { return new NullIterator(this); }

        virtual Base* get_left() { return nullptr; }

        virtual Base* get_right() { return nullptr; }
};

#endif //__RAND_HPP__
