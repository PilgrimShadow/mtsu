/*
File: RNA.cpp
Auth: Jordan Dodson
Date: 2/18/16
Info: Defines the methods for a subclass of Sequence to represent RNA sequences
*/

#include "RNA.h"
#include <iostream>

using std::cout;
using std::endl;

// Default constructor
RNA::RNA() : Sequence("", -1, "", 0), RNAType(mRNA) { /* empty body */ }

// Constructor to set each of the members
RNA::RNA(string _label, int _id, string _sequence, int _length, string _RNAType) : Sequence(_label, _id, _sequence, _length) {
  // Call setter method to set RNAType
  setRNAType(_RNAType);
}

// Print the information for this RNA sequence
void RNA::print(ostream& out) const {
  out << "RNA:\t" << "Label: " << label << "\tID: " << id << "\tSequence: "
       << sequence << "\tLength: " << length << "\tType: "
       << getRNAType() << endl;
}

// Get the open reading frame for this RNA sequence
string RNA::getRNAType() const {

  switch(RNAType) {
    case mRNA : return "mRNA"; break;
    case rRNA : return "rRNA"; break;
    case tRNA : return "tRNA"; break;
  }

}

// Set the open reading frame for this RNA sequence
void RNA::setRNAType(string newRNAType) {

  if (newRNAType == "mRNA") {
    RNAType = mRNA;
  } else if (newRNAType == "rRNA") {
    RNAType = rRNA;
  } else if (newRNAType == "tRNA") {
    RNAType = tRNA;
  }

}

