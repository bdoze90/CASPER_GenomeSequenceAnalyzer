//
//  Report.hpp
//  CASPER_GenomeSequenceAnalyzer
//
//  Created by Brian Mendoza on 7/5/18.
//  Copyright © 2018 University of Tennessee. All rights reserved.
//

#ifndef Report_hpp
#define Report_hpp

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctype.h>
#include "CrisprGroup.h"
#include "gRNA.h"

using namespace std;

class WriteFile {
public:
    WriteFile();
    ~WriteFile();
public:
    void setFileName(string fn);
    void retrieveData(CrisprGroup*,std::vector<std::string>);
    void printInfo(CrisprGroup*);
private:
    void inputData(gRNA* g);
    void entry();
    int charToInt(char c);
    std::string compressSequence(std::string s);
private:
    string filename;
    ofstream outputfile;
    int chromosome;
    std::string position;
    char strand;
    string sequence;
    string score;
    vector<int> chromosomeseqcount;
};


#endif /* Report_hpp */
