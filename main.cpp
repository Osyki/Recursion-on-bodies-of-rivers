#include <iostream>
#include "Rivers.h"
using namespace std;

int main() {
    list<Rivers*> mainlist;
    Rivers* Missouri = new Rivers("Missouri",  6.5,  6.5, mainlist);

    list<Rivers*> list1;
    Rivers* Jefferson = new Rivers("Jefferson", 7.0, 6.2, list1);
    Missouri->make_river(Jefferson);

    list<Rivers*> rs3;
    Rivers* Beaverhead = new Rivers("Beaverhead",  6.2, 6.7, rs3);
    Jefferson->make_river(Beaverhead);

    list<Rivers*> rs4;
    Rivers* Bighole = new Rivers("Bighole",  7.0, 7.5, rs4);
    Jefferson->make_river(Bighole);

    list<Rivers*> rs5;
    Rivers* Sun = new Rivers("Sun", 7.5, 7.0, rs5);
    Missouri->make_river(Sun);

    list<Rivers*> rs6;
    Rivers* Yellowstone = new Rivers("Yellowstone", 7.0, 7.5, rs6);
    Missouri->make_river(Yellowstone);

    list<Rivers*> rs7;
    Rivers* Gardner = new Rivers("Gardner", 7.1, 6.9, rs7);
    Yellowstone->make_river(Gardner);

    list<Rivers*> rs8;
    Rivers* Shields = new Rivers("Shields", 7.9, 8.0, rs8);
    Yellowstone->make_river(Shields);

    list<Rivers*> rs9;
    Rivers* Boulder = new Rivers("Boulder", 8.5, 5.5, rs9);
    Yellowstone->make_river(Boulder);

    list<Rivers*> rs10;
    Rivers* Madison = new Rivers("Madison", 8.0, 8.0, rs10);
    Missouri->make_river(Madison);

    list<Rivers*> rs11;
    Rivers* Gallatin = new Rivers("Gallatin", 6.8, 7.2, rs11);
    Missouri->make_river(Gallatin);

//    cout << r2->list_acidic_rivers() << endl;
    Rivers::setAcidLevel(6.5);
    cout << Missouri->list_acidic_rivers() << endl;

    cout << boolalpha << Gallatin->unhealthy() << endl;

//    r1->print();

    Jefferson->print();
    std::cout << "\n--------------\n\n";
    Rivers* r12 = Jefferson->lower_all_ph();
    r12->print();
    std::cout << "\n--------------\n\n";
    Jefferson->print();


//    Rivers* r13 = r1->find_subsystem("Yellowstone");
//    r13->print();

//    Rivers* r13 = r1->find_subsystem("Assabet");
//    r13->print();
//    r1->print();
    return 0;
}
