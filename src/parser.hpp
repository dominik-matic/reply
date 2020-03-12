#pragma once
#include <bits/stdc++.h>
#include "structs.hpp"

Data parseData(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    ifstream inputFile;
    string fileName="../build/a_solar.txt";
    
    inputFile.open(fileName);

    unsigned int width, height;
   
    inputFile >> width;
    inputFile >> height;

    Data parsedData;

    string mapRow;

    for(int i=0; i<height; i++){
        inputFile >> mapRow;

        for(int j=0; j<width; j++){
            if(mapRow[j]=='#'){
                parsedData.blocked.insert(make_pair(j, i));
            }
            if(mapRow[j]=='_'){
                parsedData.devPos.insert(make_pair(j, i));
            }
            if(mapRow[j]=='M'){
                parsedData.manPos.insert(make_pair(j, i));
            }
        }
    }

    unsigned int devNum, manNum;

    inputFile >> devNum;
    string textRow;
    string company;
    unsigned int bonus;
    int skillNum;
    string skill;
    set<string> skills;

    inputFile.ignore();

    for(int i=0; i<devNum; i++){
        getline(inputFile, textRow);
        stringstream ss(textRow);
        ss >> company;
        ss >> bonus;
        ss >> skillNum;

        for(int j=0; j<skillNum; j++){
            ss >> skill;
            skills.insert(skill);
        }

        parsedData.developers.emplace_back(Developer{.company=company, .bonus=bonus, .skills=skills});
    }

    inputFile >> manNum;

    inputFile.ignore();

    for(int i=0; i<manNum; i++){
        getline(inputFile, textRow);
        stringstream ss(textRow);

        ss >> company;
        ss >> bonus;

        parsedData.managers.emplace_back(Manager{.company=company, .bonus=bonus});
    }

    return parsedData;
}



