#include <iostream>
#include "arrayProblems.h"


int main()
{
    ArrayProblems arrProblems;
    // arrProblems.reverseArray(std::vector<int>({2,3,4,51,2,1}));

    // arrProblems.matchingStrings(std::vector<string>(
    //     {
    //         "jnxxywqnxgnyabsmrs","ibdfpmdhobidhmugti","fgokibonqxxpjigf", "fgokibonqxxpjigf", "hteskqcnbwzjzengwif"
    //         "inacrtucwutmwhrqoz", "inacrtucwutmwhrqoz", "kyphgaustpou", "kyphgaustpou", "tbsepxhwlcvzjvgqrlc",
    //         "tbsepxhwlcvzjvgqrlc", "xtjmloebounfttn", "bxegtivkpowmgxmnvp", "xskqtqccmqrvp", "nsppardjoovpol"
    //     }
    // ),vector<string>({
    //     {
    //         "nsppardjoovpol","bfkodbwixevvmrutjfd","pnfjlnlmpmgiv", "vuqrnzqvwwtcgkeasd", "kyphgaustpou",
    //         "syjaorepkxkalfdk", "syjaorepkxkalfdk", "fgokibonqxxpjigf", "hgnxyuifblafjfahpla", "inacrtucwutmwhrqoz"
    //     }
    // }));
    
    // arrProblems.rotateLeft(2, std::vector<int>({1,2,3,4,5}));

    arrProblems.printKMax(std::vector<int>({3,5,7,2,1,2,3}),3);
    return 0;
}