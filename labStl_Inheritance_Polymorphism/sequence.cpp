/*
FILE: sequence.cpp
AUTH: Jordan Dodson
DATE: 1/22/2016
INFO: Implementation file for a class that represents a biological sequence.
*/

// Headers
#include "sequence.h"

Sequence::Sequence() : label(""), sequence(""), id(-1), length(0) { /* empty body */}

Sequence::Sequence(string _label, int _id, string _sequence, int _length) : label(_label), sequence(_sequence), id(_id), length(_length) { /* empty body */}

// Getter methods ----------------
// Get the label of a Sequence
string Sequence::getLabel() const {
  return label;
}
  
// Get the id of a Sequence
int Sequence::getId() const {
  return id;
}

// Get the content of a Sequence
string Sequence::getSequence() const {
  return sequence;
}

// Get the length of a Sequence
int Sequence::getLength() const {
  return length;
}
  
// End of getter methods ---------

// Setter methods ----------------
// Set the label of a Sequence
void Sequence::setLabel(string new_label) {
  label = new_label;
}

// Set the id of a Sequence
void Sequence::setId(int new_id) {
  id = new_id;
}

// Set the content of a Sequence
void Sequence::setSequence(string new_sequence) {
  sequence = new_sequence;
}

// Set the length of a Sequence
void Sequence::setLength(int new_length) {
  length = new_length;
}

// End of setter methods ---------
