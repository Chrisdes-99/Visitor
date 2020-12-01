#include <iostream>
#include <string>
#include "lab04include.hpp"
#include "iterator.hpp"

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

    cout << "Success" << endl;


    return 0;
}
