#include <bits/stdc++.h>

using namespace std;

class Developer{
    public:
        string company;
        unsigned long long bonus;
        set<string> skills;
};

class Manager{
    public:
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