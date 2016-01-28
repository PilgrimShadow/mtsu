/*
FILE: sequenceDatabase.h
AUTH: Jordan Dodson
DATE: 1/22/2016
INFO: Specification file for a class that maintains a database of labeled DNA sequences.
*/

#ifndef SEQUENCE_DATABASE_H
#define SEQUENCE_DATABASE_H

// Headers
#include "DNA.h"
#include <fstream>
#include <string>

// Using declarations
using std::string;
using std::ofstream;


// A class for storing and managing a collection of dna sequences and their metadata.
class SequenceDatabase {

private:

  // Output file for logging results of database commands
  ofstream output;

public:

  // Constructor to use the given file as an output file.
  SequenceDatabase(string output_name);

  // Destructor
  ~SequenceDatabase();

  // Function to read database commands from the given file.
  void importEntries(string input_name);

};

#endif
