//
// Created by Ekyso on 11/17/2021.
// Copyright [2021]

#ifndef RIVERS2_TESTRIVERS_H
#define RIVERS2_TESTRIVERS_H

#include <cxxtest/TestSuite.h>
#include "Rivers.h"

class newCxxTest : public CxxTest::TestSuite {
public:

    //All tests should start with the word 'test' followed by
    //the name of the function being tested.

    void testGettersandSetters() {
        ////////////////////////////////////////////////////////
        list<Rivers *> mainlist;
        Rivers *Missouri = new Rivers("Missouri", 6.5, 6.5, mainlist);
        list<Rivers *> rs11;
        Rivers *Gallatin = new Rivers("Gallatin", 6.8, 7.2, rs11);
        Missouri->make_river(Gallatin);
        //////////////////////////////////////////////////////////////

        Gallatin->setRiverName("Gallatin2");
        TS_ASSERT_EQUALS(Gallatin->getRiverName(), "Gallatin2");
        Gallatin->setPh(6.9);
        TS_ASSERT_EQUALS(Gallatin->getPh(), 6.9);
        Gallatin->setDo(7.3);
        TS_ASSERT_EQUALS(Gallatin->getDo(), 7.3);//->getDo()
        list<Rivers *> rs2;
        Gallatin->setRivers(rs2);
        TS_ASSERT_EQUALS(Gallatin->getRivers(), rs2);

    }

    void testProgram() {
        std::stringstream redirectStream;
        std::stringstream check2;
        std::streambuf *oldbuffer = std::cout.rdbuf(redirectStream.rdbuf());

        //////////////////**Make River System**/////////////////////////
        list<Rivers *> mainlist;
        Rivers *Missouri = new Rivers("Missouri", 6.5, 6.5, mainlist);
        list<Rivers *> list1;
        Rivers *Jefferson = new Rivers("Jefferson", 7.0, 6.2, list1);
        Missouri->make_river(Jefferson);
        list<Rivers *> rs3;
        Rivers *Beaverhead = new Rivers("Beaverhead", 6.2, 6.7, rs3);
        Jefferson->make_river(Beaverhead);
        list<Rivers *> rs4;
        Rivers *Bighole = new Rivers("Bighole", 7.0, 7.5, rs4);
        Jefferson->make_river(Bighole);
        list<Rivers *> rs5;
        Rivers *Sun = new Rivers("Sun", 7.5, 7.0, rs5);
        Missouri->make_river(Sun);
        list<Rivers *> rs6;
        Rivers *Yellowstone = new Rivers("Yellowstone", 7.0, 7.5, rs6);
        Missouri->make_river(Yellowstone);
        list<Rivers *> rs7;
        Rivers *Gardner = new Rivers("Gardner", 7.1, 6.9, rs7);
        Yellowstone->make_river(Gardner);
        list<Rivers *> rs8;
        Rivers *Shields = new Rivers("Shields", 7.9, 8.0, rs8);
        Yellowstone->make_river(Shields);
        list<Rivers *> rs9;
        Rivers *Boulder = new Rivers("Boulder", 8.5, 5.5, rs9);
        Yellowstone->make_river(Boulder);
        list<Rivers *> rs10;
        Rivers *Madison = new Rivers("Madison", 8.0, 8.0, rs10);
        Missouri->make_river(Madison);
        list<Rivers *> rs11;
        Rivers *Gallatin = new Rivers("Gallatin", 6.8, 7.2, rs11);
        Missouri->make_river(Gallatin);
        //////////////////////////////////////////////////////////////

        std::cout << Missouri->list_acidic_rivers() << std::endl;
        std::cout << std::boolalpha << Gallatin->unhealthy() << std::endl;
        check2 << "Missouri Beaverhead Gallatin " << std::endl;
        check2 << "false" << std::endl;

        Jefferson->print();
        check2 << "Jefferson 7 6.2" << std::endl;
        check2 << "  Beaverhead 6.2 6.7" << std::endl;
        check2 << "  Bighole 7 7.5" << std::endl;

        Rivers *r12 = Jefferson->lower_all_ph();
        r12->print();
        check2 << "Jefferson 6.9 6.2" << std::endl;
        check2 << "  Beaverhead 6.1 6.7" << std::endl;
        check2 << "  Bighole 6.9 7.5" << std::endl;

        Rivers *r13 = Missouri->find_subsystem("Yellowstone");
        r13->print();

        check2 << "Yellowstone 7 7.5" << std::endl;
        check2 << "  Gardner 7.1 6.9" << std::endl;
        check2 << "  Shields 7.9 8" << std::endl;
        check2 << "  Boulder 8.5 5.5" << std::endl;

        Rivers *r14 = Missouri->find_subsystem("Assabet");
        r14->print();

        TS_ASSERT_EQUALS(check2.str(), redirectStream.str());
        std::cout.rdbuf(oldbuffer);
    }
};

#endif //RIVERS2_TESTRIVERS_H
