#include <bits/stdc++.h>

using namespace std;

struct Developer{
    string company;
    unsigned long long bonus;
    set<string> skills;
};

struct Manager{
    string company;
    unsigned long long bonus;
};

struct Data {
    list<Developer> developers;
    list<Manager> managers;
    set<pair<int, int>> blocked;
    set<pair<int, int>> devPos;
    set<pair<int, int>> manPos;
};