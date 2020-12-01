#ifndef __OP_HPP__
#define __OP_HPP__

#include "base.hpp"
#include <string>


class Op: public Base {

    private:
        double val; 

    public:
        Op(double value) : val(value) { }
        virtual double evaluate() { return val; }
        virtual std::string stringify() { return std::to_string(val);}

        //NEW
        virtual Iterator* create_iterator() { return new NullIterator(this); }

        virtual Base* get_left() { return nullptr; }

        virtual Base* get_right() { return nullptr; }

};

#endif //__OP_HPP__
