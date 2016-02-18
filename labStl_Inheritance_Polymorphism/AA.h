/*
File: AA.h
Auth: Jordan Dodson
Date: 2/18/16
Info: Declares a subclass of Sequence to represent amino acid sequences
*/

#ifndef AA_H
#define AA_H

#include "sequence.h"
#include <string>

using std::string;

class AA : public Sequence {

private:

  int openReadingFrame;

public:

  // Default constructor
  AA();

  // Constructor to set each of the members
  AA(string _label, int id, string _sequence, int _length, int openReadingFrame);


  // Overridding the pure virtual method in the sequence base class
  void print(ostream& out) const;

  // Get the open reading frame for this amino acid sequence
  int getOpenReadingFrame() const;

  // Set the open reading frame for this amino acid sequence
  void setOpenReadingFrame(int newFrame);

};

#endif
