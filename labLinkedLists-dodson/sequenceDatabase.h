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
#include "DNAList.h"
#include <fstream>
#include <string>

// Using declarations
using std::string;
using std::ofstream;


class SequenceDatabase {

private:

  // Output file for logging results of database commands
  ofstream output;

  // Linked list data structure to store sequences.
  DNAList  dna_list;

public:

  // Default constructor
  SequenceDatabase();

  // Constructor to use the given file as an output file.
  SequenceDatabase(string output_name);

  // Destructor
  ~SequenceDatabase();

  // Function to read database commands from the given file.
  void importEntries(string input_name);

};

#endif
