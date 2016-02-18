/*
File: AA.cpp
Auth: Jordan Dodson
Date: 2/18/16
Info: Defines methods for a subclass of Sequence to represent amino acid sequences
*/

#include "AA.h"
#include <iostream>

using std::cout;
using std::endl;

// Default constructor
AA::AA() : Sequence("", -1, "", 0), openReadingFrame(0) { /* empty body */ }

// Constructor to set each of the members
AA::AA(string _label, int id, string _sequence, int _length, int _openReadingFrame) : Sequence(_label, id, _sequence, _length), openReadingFrame(_openReadingFrame) { /* empty body */ }

// Overridding the pure virtual method in the sequence base class
void AA::print(ostream& out) const {

  out << "AA:\t" << "Label: " << label << "\tID: " << id << "\tSequence: "
       << sequence << "\tLength: " << length << "\tORF: "
       << openReadingFrame << endl;
}

// Get the open reading frame for this amino acid sequence
int AA::getOpenReadingFrame() const {
  return openReadingFrame;
}

// Set the open reading frame for this amino acid sequence
void AA::setOpenReadingFrame(int newFrame) {
  openReadingFrame = newFrame;
}
