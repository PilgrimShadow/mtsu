/*
FILE: DNA.h
AUTH: Jordan Dodson
DATE: 1/22/2016
INFO: Specification file for a class that represents a labeled DNA sequence.
*/

#ifndef DNA_H
#define DNA_H

// Headers
#include "sequence.h"
#include <string>

// Using declarations
using std::string;

class DNA : public Sequence {

private:

  int cDNAStartIndex; // Member to store the  coding region index for a DNA sequence

public:

  // Default constructor
  DNA(); 

  // Constructor to set each member
  DNA(string _label, int _id, string _sequence, int _length, int _cDNAStartIndex);

  // Overridding the pure virtual method in the sequence base class
  void print(ostream& out) const;

  // Get the index of the coding region for a DNA sequence
  int getStartIndex() const;

  // Set the index of the coding region for a DNA sequence
  void setStartIndex(int new_startIndex);
};

#endif
