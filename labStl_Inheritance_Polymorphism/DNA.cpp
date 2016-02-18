/*
FILE: DNA.cpp
AUTH: Jordan Dodson
DATE: 1/22/2016
INFO: Implementation file for a class that represents a labeled DNA sequence.
*/

// Headers
#include "DNA.h"
#include <iostream>

// Using declarations
using std::cout;
using std::endl;

// Default constructor
DNA::DNA() : Sequence("", -1, "", 0), cDNAStartIndex(-1) { /* empty body */ }

// Constructor to set each member
DNA::DNA(string _label, int _id, string _sequence, int _length, int _cDNAStartIndex) : Sequence(_label, _id, _sequence, _length), cDNAStartIndex(_cDNAStartIndex) { /* empty body*/ }

// Print the information for this DNA strand
void DNA::print(ostream& out) const {
  out << "DNA:\t" << "Label: " << label << "\tID: " << id << "\tSequence: "
       << sequence << "\tLength: " << length << "\tcDNAStartIndex: "
       << cDNAStartIndex << endl;
}

// Get the index of the coding region for a DNA sequence
int DNA::getStartIndex() const {
  return cDNAStartIndex;
}

// Set the index of the coding region for a DNA sequence
void DNA::setStartIndex(int new_startIndex) {
  cDNAStartIndex = new_startIndex;
}
