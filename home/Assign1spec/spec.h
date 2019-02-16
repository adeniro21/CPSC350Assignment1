#include <iostream>
#include <cmath>
#include <fstream>
#include <string>

using namespace std;

class Nucleotide
{
  public:
    Nucleotide();
    ~Nucleotide();
    void getFile();
    void whatisfile();
    void whatisinput();
    void readFile();
    void sum();
    void lines();
    void mean();
    void variance();
    void stdev();
    int count(char letter);
    void aProb();
    void cProb();
    void tProb();
    void gProb();
    int biCount(char letter1, char letter2);
    void aaProb();
    void acProb();
    void atProb();
    void agProb();
    void caProb();
    void ccProb();
    void ctProb();
    void cgProb();
    void taProb();
    void tcProb();
    void ttProb();
    void tgProb();
    void gaProb();
    void gcProb();
    void gtProb();
    void ggProb();
    string generateDna();
    void displayinfo();
    void writeFile();
};
