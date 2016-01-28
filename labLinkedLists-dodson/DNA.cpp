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
DNA::DNA() : label(""), id(0), sequence(""), length(0), cDNAStartIndex(-1) { }

// Constructor to set each member
DNA::DNA(string _label, int _id, string _sequence, int _length, int _cDNAStartIndex) :
  label(_label), id(_id), sequence(_sequence), length(_length), cDNAStartIndex(_cDNAStartIndex) { 
  // Empty body. All initialization done in initializer list.
}

// Print the information for this DNA strand
void DNA::print() const {
  cout << "Label: " << label << "\tID: " << id << "\tSequence: "
       << sequence << "\tLength:" << length << "\tcDNAStartIndex: "
       << cDNAStartIndex << endl;
}

// Getter methods ----------------
// Get the label of a DNA sequence
string DNA::getLabel() const {
  return label;
}
  
// Get the id of a DNA sequence
int DNA::getId() const {
  return id;
}

// Get the content of a DNA sequence
string DNA::getSequence() const {
  return sequence;
}

// Get the length of a DNA sequence
int DNA::getLength() const {
  return length;
}
  
// Get the index of the coding region for a DNA sequence
int DNA::getStartIndex() const {
  return cDNAStartIndex;
}
// End of getter methods ---------

// Setter methods ----------------
// Set the label of a DNA sequence
void DNA::setLabel(string new_label) {
  label = new_label;
}

// Set the id of a DNA sequence
void DNA::setId(int new_id) {
  id = new_id;
}

// Set the content of a DNA sequence
void DNA::setSequence(string new_sequence) {
  sequence = new_sequence;
}

// Set the length of a DNA sequence
void DNA::setLength(int new_length) {
  length = new_length;
}

// Set the index of the coding region for a DNA sequence
void DNA::setStartIndex(int new_startIndex) {
  cDNAStartIndex = new_startIndex;
}
// End of setter methods ---------
