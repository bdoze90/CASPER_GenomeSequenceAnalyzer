//
//  GenomeReader.hpp
//  CASPER_GenomeSequenceAnalyzer
//
//  Created by Brian Mendoza on 7/5/18.
//  Copyright © 2018 University of Tennessee. All rights reserved.
//

#ifndef GenomeReader_hpp
#define GenomeReader_hpp

#include <stdio.h>
#include <string>

class GenomeReader {
public:
    Read() { }
    void setFileName(std::string name) { filename = name; }
    void openFile();
    std::string getLine();
    double getDouble();
    int getInt();
    std::string FirstLine();
    bool newLine();
    void closeFile();
    //For reading the finder code file
public:
    std::string getPAM();
    std::vector<std::string> getOPAMs();
    std::string getOrgCode();
    std::vector<std::string> getFileLocations();
    bool getAnti();
    int getOpamNum() {return opamnum;}
private:
    int opamnum;
    std::string filename;
    FILE* stream;
};

#endif /* GenomeReader_hpp */
