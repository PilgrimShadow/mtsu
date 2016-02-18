/*
File: RNA.h
Auth: Jordan Dodson
Date: 2/18/16
Info: Declares a subclass of Sequence to represent RNA sequences
*/

#ifndef RNA_H
#define RNA_H

#include "sequence.h"
#include <string>

using std::string;

class RNA : public Sequence {

private:

  enum RNATypes {mRNA, rRNA, tRNA};
  int RNAType;

public:

  // Default constructor
  RNA();

  // Constructor to set each of the members
  RNA(string _label, int _id, string _sequence, int _length, string RNAType);

  // Overridding the pure virtual method in the sequence base class
  void print(ostream& out) const;

  // Get the open reading frame for this RNA sequence
  string getRNAType() const;

  // Set the open reading frame for this RNA sequence
  void setRNAType(string newRNAType);

};

#endif
