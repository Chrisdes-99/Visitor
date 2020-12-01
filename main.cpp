#include <iostream>
#include <string>
#include "lab04include.hpp"
#include "iterator.hpp"
#include "visitor.hpp"

using namespace std;

int main() { 
    Op* seven = new Op(7);
    Op* two = new Op(2);

    Add* add = new Add(seven, two);

    Iterator* test = add->create_iterator();

    while(!test->is_done()) {
        cout << test->current()->stringify();
        cout << endl;
        test->next();
    }
    cout << "====Done with 1st Test====" << endl;



    Sub* sub = new Sub(add, two);
    Op* random = new Op(0);
    Iterator* test2 = new PreorderIterator(sub);
    
    test2->first();
    //test2->next();
    
    while(!test2->is_done()) {
        cout << test2->current()->stringify() << endl;
        test2->next();
    }


    cout << "====Done with 2nd Test====" << endl;

    Mult* multTest = new Mult(sub, two);
    Iterator* test3 = new PreorderIterator(multTest);
    test3->first();

    CountVisitor counter;

 
    while (!test3->is_done()) {
        cout << "Test: " << test3->current()->stringify() << endl;
        test3->current()->accept(&counter);
        cout << "AddTest: " << counter.add_count() << endl;
        cout << "OpTest: " << counter.op_count() << endl;
        cout << "MultTest: " << counter.mult_count() << endl;
        cout << "SubTest: " << counter.sub_count() << endl;
        test3->next();
    }

    cout << "====Done with 3rd test====" << endl;

    Op* num1 = new Op(3);
    Op* num2 = new Op(7);

    Pow* temp = new Pow(num1, num2);
    Add* dummy = new Add(temp, num2);

    Iterator* it = new PreorderIterator(dummy);//dummy->create_iterator();

    CountVisitor* visit = new CountVisitor();
    it->first();
    while(!it->is_done()) {
        Base* phase = it->current();
        phase->accept(visit);
        cout << "Current Branch: " << phase->stringify() << endl;
        if (phase->get_left() !=  nullptr){
        cout << "LEFT: " << phase->get_left()->stringify() << endl;
        }
        if (phase->get_right() != nullptr) {
        cout << "RIGHT: " << phase->get_right()->stringify() << endl;
        }
        it->next();
    }
    cout << "OPS: " << visit->op_count() << endl;
    


    cout << "====PRGM END====" << endl;
    return 0;
}





























