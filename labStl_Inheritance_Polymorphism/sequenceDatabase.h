/*
FILE: sequenceDatabase.h
AUTH: Jordan Dodson
DATE: 1/22/2016
INFO: Specification file for a class that maintains a database of labeled biological sequences.
*/

#ifndef SEQUENCE_DATABASE_H
#define SEQUENCE_DATABASE_H

// Headers
#include "sequence.h"
#include "DNA.h"
#include "RNA.h"
#include "AA.h"
#include <fstream>
#include <string>
#include <list>

// Using declarations
using std::string;
using std::ofstream;
using std::list;


class SequenceDatabase {

private:

  // Output file for logging results of database commands
  ofstream output;

  // Linked list data structure to store sequences.
  list<Sequence*>  seq_list;

  // Look for a sequence with the given id.
  Sequence* find(int id);

  // Obliterate the sequence with the given id.
  bool obliterate(int id);

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
