//
// Created by hloi on 11/5/2021.
// Copyright [2021]

#ifndef CSC211CH07RIVERSWPI_RIVERS_H
#define CSC211CH07RIVERSWPI_RIVERS_H

#include <list>
#include <string>

using std::string;
using std::list;

class Rivers {

public:

    Rivers(string name, double ph, double DO, list<Rivers *> rivers);


    const string &getRiverName() const;

    void setRiverName(const string &riverName);

    double getPh() const;

    void setPh(double pH);

    double getDo() const;

    void setDo(double DO);

    list<Rivers *> &getRivers();

    void setRivers(const list<Rivers *> &rivers);

    void make_river(Rivers *river);

    /**
     * checks a river system with an acidic river, and also with a river considered non-acidic
     * (on the boundary at acid_level.  The default is 7.)
     * the acidic river is listed, the river with pH=6.5 is not
     * @return name of the rivers.
     */
    string list_acidic_rivers();

    /**
     * any-unhealthy?:  River -> Boolean
     * consumes a river system and returns true if any river in the system has a pH less than 6.5 or greater than 8.5,
     * @return true or false
     */
    bool unhealthy();

    /**
     * lower-all-ph:  River -> River
     * consumes a river system and produces a river system the same as the original,
     * except all pH readings are 0.1 lower
     * @return Rivers*
     */
    Rivers *lower_all_ph();

    /**
     * find-subsystem:  River String-> River OR #false
     * consumes a river system and the name of the river.  The function returns that
     * part of the system that has the named river as its root (or returns false
     * if there is no river in the system with the given name)
     * @param a
     * @return river or NULL
     */
    Rivers *find_subsystem(string name);


    /**
     * print out the rivers with indented (4 space) for the sub-rivers.
     * @param rivers
     * @param level
     */
    void print();


    /**
     * checks a river system with an acidic river, and also with a river considered non-acidic
     * (on the boundary at acid_level.  The default is 7.0)
     * the acidic river is listed, the river with pH=7.0 is not
     * @return name of the rivers.
     */
    string list_acidic_tributaries(list<Rivers *>::const_iterator begin,
                                   list<Rivers *>::const_iterator end);

    string list_acidic_rivers(Rivers *rivers);

    /**
     * any-unhealthy?:  River -> Boolean
     * consumes a river and produces true if the river's ph is under 6.5 or over 8.5,
     * or if the DO is less than 6ppm
     * @return true or false
     */
    bool unhealthy(Rivers *rivers);

    bool unhealthy_trib(list<Rivers *>::const_iterator begin,
                        list<Rivers *>::const_iterator end);

    /**
     *  consumes a river and produces true if the river's ph is under 6.5 or over 8.5,
     *  or if the DO is less than 6ppm
     * @param river
     * @return true or false
     */
    bool bad_numbers(Rivers *river);

    /**
     * lower-all-ph:  River -> River
     * consumes a river system and produces a river system the same as the original,
     * except all pH readings are 0.1 lower
     * @return Rivers*
     */
    Rivers *lower_all_ph(Rivers *rivers, Rivers *newRivers);

    list<Rivers *> update_ph(list<Rivers *>::const_iterator begin,
                             list<Rivers *>::const_iterator end, list<Rivers *> *newRivers);


    /**
     * find-subsystem:  River String-> River OR #false
     * consumes a river system and the name of the river.  The function returns that
     * part of the system that has the named river as its root (or returns false
     * if there is no river in the system with the given name)
     * @param a
     * @return river or NULL
     */
    Rivers *find_subsystem(Rivers *rivers, string name);

    /**
     * find-in-list:  ListOfRiver String -> River OR #false
     * consumes a list of rivers and the name of a river.  The function returns the river system in the list
     * that has the river with the given name as its root.  If no such named river exists, the function returns
     * false.
     * @param alor
     * @param name
     * @return River or NULL
     */
    Rivers *find_in_list(list<Rivers *>::const_iterator begin,
                         list<Rivers *>::const_iterator end, string name);

    /**
     * print out the rivers with indented (4 space) for the sub-rivers.
     * @param rivers
     * @param level
     */
    void print(Rivers *rivers, int level = 0);

    void print(list<Rivers *>::const_iterator begin,
               list<Rivers *>::const_iterator end, int level);

    static void setAcidLevel(double acidLevel);

private:
    string river_name;
    double pH;
    double DO;
    list<Rivers *> rivers;
    static double acid_level;
};


#endif //CSC211CH07RIVERSWPI_RIVERS_H
