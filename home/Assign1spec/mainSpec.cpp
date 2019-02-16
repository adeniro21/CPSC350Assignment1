#include "spec.h"
#include <iostream>
#include <cmath>
#include <fstream>
#include <string>

using namespace std;


int main()
{
  Nucleotide Nuc;
  int number = 1;
  while(number == 1)
  {
    Nuc.getFile();
    Nuc.readFile();
    Nuc.lines();
    Nuc.sum();
    Nuc.mean();
    Nuc.variance();
    Nuc.stdev();
    Nuc.aProb();
    Nuc.cProb();
    Nuc.tProb();
    Nuc.gProb();
    Nuc.aaProb();
    Nuc.acProb();
    Nuc.atProb();
    Nuc.agProb();
    Nuc.caProb();
    Nuc.ccProb();
    Nuc.ctProb();
    Nuc.cgProb();
    Nuc.taProb();
    Nuc.tcProb();
    Nuc.ttProb();
    Nuc.tgProb();
    Nuc.gaProb();
    Nuc.gcProb();
    Nuc.gtProb();
    Nuc.ggProb();
    Nuc.generateDna();
    Nuc.displayinfo();
    Nuc.writeFile();
    char answer;
    cout << "Would you like to process another list (y/n)? ";
    cin >> answer;
    if(answer == 'y')
    {
      continue;
    }
    else if(answer == 'n')
    {
      number = 0;
    }
    else
    {
      cout << "not a valid response" << endl;
      number = 0;
    }
  }
  return 0;
}
