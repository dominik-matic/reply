#ifndef __STRUCTS_HPP
#define __STRUCTS_HPP
#include "structs.hpp"

typename<T, K>
unsigned int calcTotalPotential(T r1, K r2) {
    unsigned int bonusPotential = 0;
    unsigned int workPotential = 0;

    //bonus potential
    if(r1.company == r2.company) {
        bonusPotential = r1.bonus * r2.bonus;
    }


    //work potential
    if(Developer d1 = dynamic_cast<Developer>(r1)
        && Developer d2 = dynamic_cast<Developer>(r2)) {
        unsigned int common = 0;
        set<string> disjunct;
        disjunct.insert(d1.skills.begin(), d1.skills.end());
        disjunct.insert(d2.skills.begin(), d2.skills.end());
        for(string s1 : d1.skills) {
            for(string s2 : d2.skills) {
                if(s1 == s2) {
                    disjunct.erase(s1);
                    ++common;
                    break;
                }
            }
        }
    }

    return bonusPotential + workPotential;
}



#endif