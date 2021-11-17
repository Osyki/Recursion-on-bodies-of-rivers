//
// Created by hloi on 11/5/2021.
//

#include "Rivers.h"
#include <string>
#include <iostream>

using namespace std;

double Rivers::acid_level = 7.0;

const string &Rivers::getRiverName() const {
    return river_name;
}

void Rivers::setRiverName(const string &riverName) {
    river_name = riverName;
}

double Rivers::getPh() const {
    return pH;
}

void Rivers::setPh(double pH) {
    this->pH = pH;
}

double Rivers::getDo() const {
    return DO;
}

void Rivers::setDo(double DO) {
    this->DO = DO;
}

list<Rivers *> &Rivers::getRivers() {
    return rivers;
}

void Rivers::setRivers(const list<Rivers *> &rivers) {
    this->rivers = rivers;
}

Rivers::Rivers(string name, double ph, double DO, list<Rivers *> rivers) {
    this->river_name = name;
    this->pH = ph;
    this->DO = DO;
    this->rivers = rivers;
}

void Rivers::make_river(Rivers *river) {
    rivers.push_back(river);
}

string Rivers::list_acidic_rivers(Rivers *rivers) {
    list<Rivers *>::const_iterator begin = rivers->getRivers().begin();
    list<Rivers *>::const_iterator end = rivers->getRivers().end();
    if (rivers->pH < 7) {
        string rn = rivers->river_name;
        return rn + " " + list_acidic_tributaries(begin, end);
    }
    return list_acidic_tributaries(begin, end);

}

string Rivers::list_acidic_tributaries(list<Rivers *>::const_iterator begin, list<Rivers *>::const_iterator end) {
    if (begin == end) {
        return "";
    }
    Rivers *front = *begin++;
    return list_acidic_rivers(front) + list_acidic_tributaries(begin, end);
}

string Rivers::list_acidic_rivers() {
    return list_acidic_rivers(this);
}

void Rivers::setAcidLevel(double acidLevel) {
    acid_level = acidLevel;
}

bool Rivers::unhealthy() {
    return unhealthy(this);
}

bool Rivers::unhealthy(Rivers *rivers) {
    list<Rivers *>::const_iterator begin = rivers->getRivers().begin();
    list<Rivers *>::const_iterator end = rivers->getRivers().end();

    return bad_numbers(rivers) || unhealthy_trib(begin, end);
}

bool Rivers::unhealthy_trib(list<Rivers *>::const_iterator begin, list<Rivers *>::const_iterator end) {
    if (begin != end) {
        Rivers *front = *begin++;
        return unhealthy(front) || unhealthy_trib(begin, end);
    }
    return false;
}

bool Rivers::bad_numbers(Rivers *river) {
    //cout << river->river_name << "  " << river->pH << "    " << river->DO << endl;
    return (river->pH < 6.5 || river->pH > 8.5 || river->DO < 6);
}

Rivers *Rivers::lower_all_ph() {
    list<Rivers *> mainListCopy;
    Rivers *mainRiverCopy = new Rivers(getRiverName(), getPh() - 0.1, getDo(),mainListCopy); //create copy of main river being lowered
    return lower_all_ph(this, mainRiverCopy); //pass to helper function to finish copying rest of list
}

Rivers *Rivers::lower_all_ph(Rivers *currentRiver, Rivers *newRivers) {
    list<Rivers*>::const_iterator begin = currentRiver->getRivers().begin();
    list<Rivers*>::const_iterator end = currentRiver->getRivers().end();
    update_ph(begin,end,&newRivers->getRivers());

    return newRivers;
}

list<Rivers*> Rivers::update_ph(list<Rivers *>::const_iterator begin, list<Rivers *>::const_iterator end, list<Rivers *> *newRivers) {

    if (begin == end) {
        return *newRivers;
    }
        Rivers *origRiver = *begin; //copy address of river to be used
        list<Rivers*> listCopy; //create a copy list for river being passed
        Rivers *riverCopy = new Rivers(origRiver->getRiverName(),origRiver->getPh()-0.1,origRiver->DO,listCopy); //create copy
        newRivers->push_back(riverCopy); //push to river
        lower_all_ph(origRiver,riverCopy);
        begin++;

    return update_ph(begin,end,newRivers);
}

Rivers *Rivers::find_subsystem(string name) {
    return find_subsystem(this,name);
}

Rivers *Rivers::find_subsystem(Rivers *rivers, string name) {
    return nullptr;
}

Rivers *Rivers::find_in_list(list<Rivers *>::const_iterator begin, list<Rivers *>::const_iterator end, string name) {
    return nullptr;
}

void Rivers::print(Rivers *rivers, int level) {
    list<Rivers *>::const_iterator begin = rivers->getRivers().begin();
    list<Rivers *>::const_iterator end = rivers->getRivers().end();
    for (int x = 0; x < level; x++) {
        std::cout << "  ";
    }
    std::cout << rivers->river_name << " " << rivers->pH << " " << rivers->DO << std::endl;
    print(begin, end, level + 1);
}

void Rivers::print(list<Rivers *>::const_iterator begin, list<Rivers *>::const_iterator end, int level) {
    if (begin != end) {
        Rivers *front = *begin++;
        print(front, level);
        print(begin, end, level);
    }
}

void Rivers::print() {
    print(this);
}


