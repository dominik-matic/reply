#ifndef __STRUCTS_HPP
#define __STRUCTS_HPP
#include "structs.hpp"

template <typename T, typename K> unsigned int calcTotalPotential(T r1, K r2) {
    unsigned int bonusPotential = 0;
    unsigned int workPotential = 0;

    //bonus potential
    if(r1.company == r2.company) {
        bonusPotential = r1.bonus * r2.bonus;
    }


    //work potential
    if(std::is_same<T, Developer>::value
        && std::is_same<K, Developer>::value) {
        unsigned int common = 0;
        set<string> disjunct;

        disjunct.insert(r1.skills.begin(), r1.skills.end());
        disjunct.insert(r2.skills.begin(), r2.skills.end());

        for(string s1 : r1.skills) {
            for(string s2 : r2.skills) {
                if(s1 == s2) {
                    disjunct.erase(s1);
                    ++common;
                    break;
                }
            }
        }
        workPotential = common * disjunct.size();
    }

    return bonusPotential + workPotential;
}



#endif