/*
File: sequence.h
Auth: Jordan Dodson
Date: 2/18/16
Info: Abstract base class to represent a biological sequence
*/


#ifndef SEQUENCE_H
#define SEQUENCE_H

#include <string>
#include <iostream>

using std::ostream;
using std::string;

class Sequence {

protected:

  string label, sequence;         // Members to store the label and content of a sequence
  int id, length; // Members to store the id, length, and coding region index for a sequence

public:

  Sequence();

  // No constructors - abstract base class
  Sequence(string _label, int _id, string _sequence, int _length);

  // *** pure virtual method ***
  virtual void print(ostream& out) const = 0;

  // Getter methods
  // Get the label of a sequence
  string getLabel() const;

  // Get the id of a sequence
  int getId() const;

  // Get the content of a sequence
  string getSequence() const;

  // Get the length of a sequence
  int getLength() const;
  
  // Setter methods
  // Set the label of a sequence
  void setLabel(string new_label);

  // Set the id of a sequence
  void setId(int new_id);

  // Set the content of a sequence
  void setSequence(string new_sequence);

  // Set the length of a sequence
  void setLength(int new_length);

};

#endif
