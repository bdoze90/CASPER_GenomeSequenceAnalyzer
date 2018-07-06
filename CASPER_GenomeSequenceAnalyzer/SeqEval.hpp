//
//  SeqEval.hpp
//  CASPER_GenomeSequenceAnalyzer
//
//  Created by Brian Mendoza on 7/5/18.
//  Copyright © 2018 University of Tennessee. All rights reserved.
//

#ifndef SeqEval_hpp
#define SeqEval_hpp

#include <stdio.h>
#include <vector>
#include <string>

class pamEval {
public:
    std::string regexPAM(std::string p) {
        std::string retpam = "(?=(";  //initializes lookahead structure
        // Iterate across the pam and generate regex characters for degenerates
        for(int i=0;i<p.size();i++) {
            if (p[i] == 'N') {
                retpam += '.';
            } else if (p[i] == 'A' || p[i] == 'T' || p[i] == 'C' || p[i] == 'G') {
                retpam += p[i];
            } else {
                retpam += degenerateRegex(p[i]);
            }
        }
        // finish the lookahead regex structure:
        retpam += ")).";
        std::cout << retpam << std::endl;
        return retpam;
    };
private:
    // Function for assigning a regex code for a degenerate nucleotide code
    std::string degenerateRegex(char c) {
        std::string reg_s;
        switch (c) {
            case 'W':
                reg_s = "[AT]";
                break;
            case 'S':
                reg_s = "[CG]";
                break;
            case 'M':
                reg_s = "[AC]";
                break;
            case 'K':
                reg_s = "[GT]";
                break;
            case 'R':
                reg_s = "[AG]";
                break;
            case 'Y':
                reg_s = "[CT]";
                break;
            case 'B':
                reg_s = "[TCG]";
                break;
            case 'D':
                reg_s = "[ATG]";
                break;
            case 'H':
                reg_s = "[ATC]";
                break;
            case 'V':
                reg_s = "[AGC]";
                break;
        }
        return reg_s;
    };
};


#endif /* SeqEval_hpp */
