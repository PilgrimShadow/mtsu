/*
FILE: DNA.h
AUTH: Jordan Dodson
DATE: 1/22/2016
INFO: Specification file for a class that represents a labeled DNA sequence.
*/

#ifndef DNA_H
#define DNA_H

// Headers
#include <string>

// Using declarations
using std::string;

class DNA {

private:

  string label, sequence;         // Members to store the label and content of a DNA sequence
  int id, length, cDNAStartIndex; // Members to store the id, length, and coding region index for
                                  // a DNA sequence

public:

  // Default constructor
  DNA();

  // Constructor to set each member
  DNA(string _label, int _id, string _sequence, int _length, int _cDNAStartIndex);

  // Print the information for this DNA strand
  void print() const;

  // Getter methods
  // Get the label of a DNA sequence
  string getLabel() const;

  // Get the id of a DNA sequence
  int getId() const;

  // Get the content of a DNA sequence
  string getSequence() const;

  // Get the length of a DNA sequence
  int getLength() const;
  
  // Get the index of the coding region for a DNA sequence
  int getStartIndex() const;

  // Setter methods
  // Set the label of a DNA sequence
  void setLabel(string new_label);

  // Set the id of a DNA sequence
  void setId(int new_id);

  // Set the content of a DNA sequence
  void setSequence(string new_sequence);

  // Set the length of a DNA sequence
  void setLength(int new_length);

  // Set the index of the coding region for a DNA sequence
  void setStartIndex(int new_startIndex);

};

#endif
