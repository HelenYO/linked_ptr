#include <iostream>
#include "linked_ptr.h"
using namespace std;
struct B {
    int b = 9;

    B(int b) : b(b) {}
};
struct A {
    int a = 5;
    B b = 9;

    A(int a) : a(a), b(9) {}
    A(){}
};
int main() {

    A b(6);
    A c = 7;
    linked_ptr<A> l1(&b);
    cout << l1.get()->a;
//    linked_ptr<A> l2(std::move(l1));
//    //l2.reset();
//    linked_ptr<A> l3 = std::move(l2);
//
//    linked_ptr<A> l4(&c);
//    //l4 = new linked_ptr(&c);
//    l4 = l3;
//    linked_ptr<A> l5, l6, l7;
//    l5 = l3;
//    l6 = l3;
//    l7 = l3;
//    l7.reset();
//    l5.reset();
//    linked_ptr<A> l9(&b);
//    linked_ptr<B> l10(l9, &b.b);
//
//
//    cout << l10.get()->b << "\n";
    return 0;
}


//#include <iostream>
//#include <memory>
//#include "linked_ptr.h"
//using namespace std;
//
//struct B;
//struct A {
//    linked_ptr<B> b;
//    shared_ptr<B> b2;
//};
//
//int main() {
// A a;
//}