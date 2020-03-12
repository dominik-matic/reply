#ifndef __STRUCTS_HPP
#define __STRUCTS_HPP
#include "structs.hpp"

template typename<T, K>
unsigned int calcTotalPotential(T r1, K r2) {
    unsigned int bonusPotential = 0;
    unsigned int workPotential = 0;

    //bonus potential
    if(r1.company == r2.company) {
        bonusPotential = r1.bonus * r2.bonus;
    }
}



#endif