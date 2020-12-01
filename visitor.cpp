#include "visitor.hpp"

CountVisitor::CountVisitor() {
    ops = 0;
    rands = 0;
    mults = 0;
    divs = 0;
    add = 0;
    sub = 0;
    pow = 0;
}

// Op ==========================
void CountVisitor::visit_op() {
   ops++; 
}

int CountVisitor::op_count() {
    return ops;   
}

//Rand =========================
void CountVisitor::visit_rand() {
    rands++;   
}

int CountVisitor::rand_count() {
    return rands;   
}

//Mult =========================
void CountVisitor::visit_mult() {
    mults++;   
}

int CountVisitor::mult_count() {
    return mults;   
}

//Div ==========================
void CountVisitor::visit_div() {
    divs++;   
}

int CountVisitor::div_count() {
    return divs;   
}

//Add ==========================
void CountVisitor::visit_add() {
    add++;       
}

int CountVisitor::add_count() {
    return add;   
}


//Sub ==========================
void CountVisitor::visit_sub() {
    sub++;
}

int CountVisitor::sub__count() {
    return sub;
}

//Pow ===========================
void CountVisitor::visit_pow() {
    pow++;
}

int CountVisitor::pow_count() {
    return pow;
}

