#include "spec.h"
#include <iostream>
#include <cmath>
#include <fstream>
#include <string>

using namespace std;

Nucleotide::Nucleotide()
{

}

Nucleotide::~Nucleotide()
{

}
//variables
string file;
string input;
double lines = -1;
double sum = 0;
double mean = 0;
double var = 0;
double stdev = 0;
double aProb = 0;
double cProb = 0;
double tProb = 0;
double gProb = 0;
double aaProb = 0;
double acProb = 0;
double atProb = 0;
double agProb = 0;
double caProb = 0;
double ccProb = 0;
double ctProb = 0;
double cgProb = 0;
double taProb = 0;
double tcProb = 0;
double ttProb = 0;
double tgProb = 0;
double gaProb = 0;
double gcProb = 0;
double gtProb = 0;
double ggProb = 0;
string display;

void Nucleotide::getFile() //getting the file name from the user
{
  cout << "What is the text file you want to read in from: ";
  cin >> ::file;
}

void Nucleotide::whatisfile() //checking to see if file variable is filled
{
  cout << ::file << endl;
}

void Nucleotide::readFile() //reading from a file and appending all nucleotides into allLines to be used by for loops
{
  string line;
  ifstream myFile;
  myFile.open(::file);
  if(myFile.is_open())
  {
    while(!myFile.eof())
    {
      getline(myFile, line);
      if(line.size() % 2 != 0) //shortening line to an even length
      {

        string st = line.substr(0, line.size()-1); //not sure if remove is correct syntax
        ::input.append(st);// not sure if append is correct syntax
      }
      else
      {
        string st = line.substr(0, line.size()-2);
        ::input.append(st);
      }
    }
    myFile.close();
  }
  else cout << "not a valid file" << endl;
  //cout << ::input << endl;
  myFile.close();
}

void Nucleotide::whatisinput()
{
  cout << ::input << endl;
}

void Nucleotide::lines()
{
  string line;
  ifstream myFile;
  myFile.open(::file);
  if(myFile.is_open())
  {
    while(myFile.good())
    {
      getline(myFile, line);
      ::lines++;
    }
    myFile.close();
  }
  else cout << "not a valid file" << endl;
  myFile.close();
}

void Nucleotide::sum() //calculating sum of length of nucleotides
{
  for (int i = 0; i < ::input.size(); i++)
  {
    char letter = tolower(::input[i]);
    if(letter == 'a')
      ::sum ++;
    else if(letter == 'c')
      ::sum ++;
    else if(letter == 't')
      ::sum ++;
    else if(letter == 'g')
      ::sum ++;
  }
}

void Nucleotide::mean()
{
  double mean = ::sum/::lines;
  ::mean = mean;
}

void Nucleotide::variance()
{
  double vars = 0;
  string line;
  ifstream myFile;
  myFile.open(::file);
  if(myFile.is_open())
  {
    while(myFile.good())
    {
      getline(myFile, line);
      if(line.size() % 2 != 0)
      {
        string st = line.substr(0, line.size()-1); //shortening line to an even length
        vars += pow((::mean - st.size()),2);
      }
      else
      {
        string st = line.substr(0, line.size()-2);
        var += pow((::mean - st.size()),2);
      }
    }
    myFile.close();
  }
  else cout << "not a valid file" << endl;
  myFile.close();
  double var2 = vars/::lines;
  ::var = var2;
}
void Nucleotide::stdev()
{
  double stdevs = sqrt(::var);
  ::stdev = stdevs;
}

int Nucleotide::count(char letter)
{
  int letterCount = 0;
  for (int i = 0; i < ::input.size(); i++)
  {
    char letters = tolower(input[i]);
    if(letters == letter)
      letterCount ++;
  }
  return letterCount;
}

void Nucleotide::aProb()
{
  double counts = count('a');
  double aProbs = counts/::sum;
  ::aProb = aProbs;
}

void Nucleotide::cProb()
{
  double counts = count('c');
  double cProbs = counts/::sum;
  ::cProb = cProbs;
}

void Nucleotide::tProb()
{
  double counts = count('t');
  double tProbs = counts/::sum;
  ::tProb = tProbs;
}

void Nucleotide::gProb()
{
  double counts = count('g');
  double gProbs = counts/::sum;
  ::gProb = gProbs;
}

int Nucleotide::biCount(char letter1, char letter2)
{
  int bi = 0;
  string bigram = " ";
  int bigramCount = 0;
  for (int i = 0; i < ::input.size(); i++)
  {
    char letter = tolower(::input[i]);
    bi ++;
    if(bi <= 2)
    {
      bigram += letter;
      if(bi == 2)
      {
        if(bigram.at(1) == letter1 & bigram.at(2) == letter2)
        {
          bigramCount++;
          bi = 0;
          bigram = " ";
        }
        else
        {
          bi = 0;
          bigram = " ";
        }
      }
    }
  }
  return bigramCount;
}

void Nucleotide::aaProb()
{
  double biCounts = biCount('a', 'a');
  double biSum = ::sum/2;
  double aaProbs = biCounts/biSum;
  ::aaProb = aaProbs;
}

void Nucleotide::acProb()
{
  double biCounts = biCount('a', 'c');
  double biSum = ::sum/2;
  double acProbs = biCounts/biSum;
  ::acProb = acProbs;
}

void Nucleotide::atProb()
{
  double biCounts = biCount('a', 'g');
  double biSum = ::sum/2;
  double atProbs = biCounts/biSum;
  ::atProb = atProbs;
}

void Nucleotide::agProb()
{
  double biCounts = biCount('a', 'g');
  double biSum = ::sum/2;
  double agProbs = biCounts/biSum;
  ::agProb = agProbs;
}

void Nucleotide::caProb()
{
  double biCounts = biCount('c', 'a');
  double biSum = ::sum/2;
  double caProbs = biCounts/biSum;
  ::caProb = caProbs;
}

void Nucleotide::ccProb()
{
  double biCounts = biCount('c', 'c');
  double biSum = ::sum/2;
  double ccProbs = biCounts/biSum;
  ::ccProb = ccProbs;
}

void Nucleotide::ctProb()
{
  double biCounts = biCount('c', 't');
  double biSum = ::sum/2;
  double ctProbs = biCounts/biSum;
  ::ctProb = ctProbs;
}

void Nucleotide::cgProb()
{
  double biCounts = biCount('c', 'g');
  double biSum = ::sum/2;
  double cgProbs = biCounts/biSum;
  ::cgProb = cgProbs;
}

void Nucleotide::taProb()
{
  double biCounts = biCount('t', 'a');
  double biSum = ::sum/2;
  double taProbs = biCounts/biSum;
  ::taProb = taProbs;
}

void Nucleotide::tcProb()
{
  double biCounts = biCount('t', 'c');
  double biSum = ::sum/2;
  double tcProbs = biCounts/biSum;
  ::tcProb = tcProbs;
}

void Nucleotide::ttProb()
{
  double biCounts = biCount('t', 't');
  double biSum = ::sum/2;
  double ttProbs = biCounts/biSum;
  ::ttProb = ttProbs;
}

void Nucleotide::tgProb()
{
  double biCounts = biCount('t', 'g');
  double biSum = ::sum/2;
  double tgProbs = biCounts/biSum;
  ::tgProb = tgProbs;
}

void Nucleotide::gaProb()
{
  double biCounts = biCount('g', 'a');
  double biSum = ::sum/2;
  double gaProbs = biCounts/biSum;
  ::gaProb = gaProbs;
}

void Nucleotide::gcProb()
{
  double biCounts = biCount('g', 'c');
  double biSum = ::sum/2;
  double gcProbs = biCounts/biSum;
  ::gcProb = gcProbs;
}

void Nucleotide::gtProb()
{
  double biCounts = biCount('g', 't');
  double biSum = ::sum/2;
  double gtProbs = biCounts/biSum;
  ::gtProb = gtProbs;
}

void Nucleotide::ggProb()
{
  double biCounts = biCount('g', 'g');
  double biSum = ::sum/2;
  double ggProbs = biCounts/biSum;
  ::ggProb = ggProbs;
}

string Nucleotide::generateDna()
{
  double pi = 3.14159265358979;
  double a = ((double) rand() / (RAND_MAX));
  double b = ((double) rand() / (RAND_MAX));
  double cDist = sqrt(-2 * log(a)) * cos(2 * pi * b);
  int length = round(::stdev * cDist + ::mean);
  string dna;
  for (int i = 0; i < length; i++)
  {
    double random = ((double) rand() / (RAND_MAX));
    if(random <= ::aProb)
    {
      dna += 'A';
    }
    random -= ::aProb;
    if(random <= ::cProb)
    {
      dna += 'C';
    }
    random -= ::cProb;
    if(random <= ::tProb)
    {
      dna += 'T';
    }
    random -= ::tProb;
    if(random <= ::gProb)
    {
      dna += 'G';
    }
  }
  return dna;
}

void Nucleotide::displayinfo()
{
  string name = "Anthony DeNiro";
  string studentID = "2257558";
  string displays = "Name: " + name + "     " + "Student ID: " + studentID;
  ::display = displays;
}

void Nucleotide::writeFile() //writing to a file
{
  ofstream newFile;
  newFile.open("DeNiro.out", fstream::app);
  newFile << ::display << endl;
  newFile << "mean: " << ::mean << endl;
  newFile << "variance: " << ::var << endl;
  newFile << "standard deviation: " << ::stdev << endl;
  newFile << "Probability of A nucleotide: " << ::aProb << endl;
  newFile << "Probability of C nucleotide: " << ::cProb << endl;
  newFile << "Probability of T nucleotide: " << ::tProb << endl;
  newFile << "Probability of G nucleotide: " << ::gProb << endl;
  newFile << "Probability of AA bigram: " << ::aaProb << endl;
  newFile << "Probability of AC bigram: " << ::acProb << endl;
  newFile << "Probability of AT bigram: " << ::atProb << endl;
  newFile << "Probability of AG bigram: " << ::agProb << endl;
  newFile << "Probability of CA bigram: " << ::caProb << endl;
  newFile << "Probability of CC bigram: " << ::ccProb << endl;
  newFile << "Probability of CT bigram: " << ::ctProb << endl;
  newFile << "Probability of CG bigram: " << ::cgProb << endl;
  newFile << "Probability of TA bigram: " << ::taProb << endl;
  newFile << "Probability of TC bigram: " << ::tcProb << endl;
  newFile << "Probability of TT bigram: " << ::ttProb << endl;
  newFile << "Probability of TG bigram: " << ::tgProb << endl;
  newFile << "Probability of GA bigram: " << ::gaProb << endl;
  newFile << "Probability of GC bigram: " << ::gcProb << endl;
  newFile << "Probability of GT bigram: " << ::gtProb << endl;
  newFile << "Probability of GG bigram: " << ::ggProb << endl;
  for (int i = 0; i < 1001; i++)
  {
    string dna = generateDna();
    newFile << i << ". " << dna << endl;
  }
  newFile.close();
}
