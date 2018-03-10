#include <string>
#include <math.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

int main(int argc , char** argv){
  cout << "======================\n";
  cout << "Name: Rabah Habiss \n Student ID: 2268381 \n";
  cout << "====================== \n\n";

bool repeat = true;

while (repeat == true){  //keep the program alive

  //File input
  string filename;
  cout << "Type the file name: " << endl;
  cin >> filename;

  ifstream inputfile;
  inputfile.open(filename);

  string dnastring;
  string sequence;

  int i=0;

  if (inputfile.is_open()){
    while (!inputfile.eof()){
      getline(inputfile,sequence);
      dnastring.append(sequence);
      dnastring.append("\n");
      }
    }
    inputfile.close();

  //initialize counters
  int counter = 0;  //number of sequences
  int A= 0;
  int C= 0;
  int T= 0;
  int G= 0;

  //counting the letters
  for (i =0; i<dnastring.size(); ++i) {
    if (dnastring[i] == 'A' || dnastring[i] == 'a')
      A++;
    else if (dnastring[i] == 'C' || dnastring[i] == 'c')
      C++;
    else if (dnastring[i] == 'T' || dnastring[i] == 't')
      T++;
    else if (dnastring[i] == 'G' || dnastring[i] == 'g')
      G++;
    else if (dnastring[i] == '\n')
      counter++;
  }

  //number of letters
  int totalLetters = dnastring.size() - counter;

  //relative probability of each nucleotide
  double relA = A/double(totalLetters);
  double relC = C/double(totalLetters);
  double relT = T/double(totalLetters);
  double relG = G/double(totalLetters);

  cout << "Relative probability of each nucleotide: \n";
  cout << "A: " << relA << "\n";
  cout << "C: " << relC << "\n";
  cout << "T: " << relT << "\n";
  cout << "G: " << relG << "\n";
  cout << "======================== \n";

  //initializing bigrams
  int AA= 0;
  int AC= 0;
  int AT= 0;
  int AG= 0;
  int CA= 0;
  int CC= 0;
  int CT= 0;
  int CG= 0;
  int TA= 0;
  int TC= 0;
  int TT= 0;
  int TG= 0;
  int GA= 0;
  int GC= 0;
  int GT= 0;
  int GG= 0;
  int bigramCount = 0;

  //counting bigrams
  for (i =0; i<dnastring.size(); ++i) {
    if ((dnastring[i] == 'A' || dnastring[i] == 'a') && (dnastring[i+1] == 'A' || dnastring[i+1] == 'a')){
      AA++;
      bigramCount++;}
    else if ((dnastring[i] == 'A' || dnastring[i] == 'a') && (dnastring[i+1] == 'C' || dnastring[i+1] == 'c')){
      AC++;
      bigramCount++;}
    else if ((dnastring[i] == 'A' || dnastring[i] == 'a') && (dnastring[i+1] == 'T' || dnastring[i+1] == 't')){
      AT++;
      bigramCount++;}
    else if ((dnastring[i] == 'A' || dnastring[i] == 'a') && (dnastring[i+1] == 'G' || dnastring[i+1] == 'g')){
      AG++;
      bigramCount++;}
      else if ((dnastring[i] == 'C' || dnastring[i] == 'c') && (dnastring[i+1] == 'A' || dnastring[i+1] == 'a')){
        CA++;
        bigramCount++;}
      else if ((dnastring[i] == 'C' || dnastring[i] == 'c') && (dnastring[i+1] == 'C' || dnastring[i+1] == 'c')){
        CC++;
        bigramCount++;}
      else if ((dnastring[i] == 'C' || dnastring[i] == 'c') && (dnastring[i+1] == 'T' || dnastring[i+1] == 't')){
        CT++;
        bigramCount++;}
      else if ((dnastring[i] == 'C' || dnastring[i] == 'c') && (dnastring[i+1] == 'G' || dnastring[i+1] == 'g')){
        CG++;
        bigramCount++;}
        else if ((dnastring[i] == 'T' || dnastring[i] == 't') && (dnastring[i+1] == 'A' || dnastring[i+1] == 'a')){
          TA++;
          bigramCount++;}
        else if ((dnastring[i] == 'T' || dnastring[i] == 't') && (dnastring[i+1] == 'C' || dnastring[i+1] == 'c')){
          TC++;
          bigramCount++;}
        else if ((dnastring[i] == 'T' || dnastring[i] == 't') && (dnastring[i+1] == 'T' || dnastring[i+1] == 't')){
          TT++;
          bigramCount++;}
        else if ((dnastring[i] == 'T' || dnastring[i] == 't') && (dnastring[i+1] == 'G' || dnastring[i+1] == 'g')){
          TG++;
          bigramCount++;}
          else if ((dnastring[i] == 'G' || dnastring[i] == 'g') && (dnastring[i+1] == 'A' || dnastring[i+1] == 'a')){
            GA++;
            bigramCount++;}
          else if ((dnastring[i] == 'G' || dnastring[i] == 'g') && (dnastring[i+1] == 'C' || dnastring[i+1] == 'c')){
            GC++;
            bigramCount++;}
          else if ((dnastring[i] == 'G' || dnastring[i] == 'g') && (dnastring[i+1] == 'T' || dnastring[i+1] == 't')){
            GT++;
            bigramCount++;}
          else if ((dnastring[i] == 'G' || dnastring[i] == 'g') && (dnastring[i+1] == 'G' || dnastring[i+1] == 'g')){
            GG++;
            bigramCount++;}
  }

  //
  //relative probability of each nucleotide bigram
  double relAA = AA/double(bigramCount);
  double relAC = AC/double(bigramCount);
  double relAT = AT/double(bigramCount);
  double relAG = AG/double(bigramCount);
  double relCA = CA/double(bigramCount);
  double relCC = CC/double(bigramCount);
  double relCT = CT/double(bigramCount);
  double relCG = CG/double(bigramCount);
  double relTA = TA/double(bigramCount);
  double relTC = TC/double(bigramCount);
  double relTT = TT/double(bigramCount);
  double relTG = TG/double(bigramCount);
  double relGA = GA/double(bigramCount);
  double relGC = GC/double(bigramCount);
  double relGT = GT/double(bigramCount);
  double relGG = GG/double(bigramCount);

  cout << "Relative probability of each nucleotide bigram: \n";
  cout << "AA: " << relAA << "\n";
  cout << "AC: " << relAC << "\n";
  cout << "AT: " << relAT << "\n";
  cout << "AG: " << relAG << "\n";
  cout << "CA: " << relCA << "\n";
  cout << "CC: " << relCC << "\n";
  cout << "CT: " << relCT << "\n";
  cout << "CG: " << relCG << "\n";
  cout << "TA: " << relTA << "\n";
  cout << "TC: " << relTC << "\n";
  cout << "TT: " << relTT << "\n";
  cout << "TG: " << relTG << "\n";
  cout << "GA: " << relGA << "\n";
  cout << "GC: " << relGC << "\n";
  cout << "GT: " << relGT << "\n";
  cout << "GG: " << relGG << "\n";
  cout << "======================== \n";


  //sum
  cout << "Sum: " << totalLetters << "\n";

  //mean
  double mean = totalLetters/(double)counter;
  cout << "Mean: " << mean << "\n";

  //variance
  double seqLength=0;

  inputfile.open(filename);
  while (!inputfile.eof()){
    getline(inputfile,sequence);
    seqLength += pow((sequence.length())-mean,2); //each line squared to calculate variance
    }


  double variance= seqLength/(((double)counter)-1); //n-1 to calculate for sample variance
  cout << "Sample Variance: " << variance << "\n";

  //standard deviation
  double sd = sqrt(variance);
  cout << "Standard Deviation: " << sd << "\n";
  cout << "======================== \n";


  /* DNA Reproduction */

  //Gaussian Distribution
  double a = ((double)rand() / (RAND_MAX));
  double b = ((double)rand() / (RAND_MAX));

  double c = sqrt(-2 * log(a)) * cos(2*M_PI*b); //C value

  double d = sd*c + mean; //D value

  /*
  int j=0;
  string newstring = "";
  string dnaletters = "ACTG";
  while (j < 1000){

    for (i=0; i<d; ++i){
      //newstring[d];
      newstring.append(dnaletters,d,2);
    }

    if (d>0){ j++; } //making sure D is not a negative number
  }
  cout << newstring << endl;
  */

  //Prompt user to try another file
  char entry;

  cout << "Do you want to process another file? (y/n)" << endl;
  cin >> entry;
  if (entry=='y' || entry=='Y'){
  repeat = true;}

  else return 0;

 } //end of while loop

}//end of main
