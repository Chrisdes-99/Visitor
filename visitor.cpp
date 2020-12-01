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

void CountVisitor::visit_op() {
    
}

int CountVisitor::op_count() {
    
}

void CountVisitor::visit_rand() {
    
}

int CountVisitor::rand_count() {
    
}

void CountVisitor::visit_mult() {
    
}

int CountVisitor::mult_count() {
    
}

void CountVisitor::visit_div() {
    
}

int CountVisitor::div_count() {
    
}

void CountVisitor::visit_add() {
    
}

int CountVisitor::add_count() {
    
}
