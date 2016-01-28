/*
FILE: sequenceDatabase.cpp
AUTH: Jordan Dodson
DATE: 1/22/2016
INFO: Implementation file for a class that maintains a database of labeled DNA sequences.
*/

// Headers
#include "sequenceDatabase.h"

// Using declarations
using std::ifstream;
using std::endl;

// Constructor to use the given file as an output file.
SequenceDatabase::SequenceDatabase(string output_name) {
  output.open(output_name);
}

// Destructor
SequenceDatabase::~SequenceDatabase() {
  output.close();
}

// Function to read database commands from the given file.
void SequenceDatabase::importEntries(string input_name) {
  ifstream input;        // The stream object used to read the input file.
  char     command;      // Character representing a database command
  string   label, sequence;          // Variables to hold the sequence information
  int      id, length, startIndex;   // when parsing a line of the input file.

  // Open our input file for reading
  input.open(input_name);

  // Record that we are parsing the given file
  output << "Importing " << input_name << " ..." << endl;

  // Read the first command
  input >> command;

  // Read commands until the end of the input file is reached.
  // Dispatch based on the command and perform the appropriate action.
  while (input) {
    switch (command) {
      // Add a new sequence to the database
      case 'D' : // Parse and store the entry data
                 input >> label >> id >> sequence >> length >> startIndex;

                 // Allocate memory for a new DNA object. This is
                 // a memory leak to be corrected in the next project.
                 new DNA(label, id, sequence, length, startIndex);

                 output << "Adding " << id << " ..." << endl << endl;
                 break;

      // Display info on a particular sequence
      case 'P' : input >> id;
                 output << "Printing " << id << " ..." << endl << endl;
                 break;

      // Obliterate the sequence with the given id.
      case 'O' : input >> id;
                 output << "Obliterating " << id << " ..." << endl << endl;
                 break;

      // Display the number of entries in the database
      case 'S' : output << "Entries: NYI" << endl << endl;
                 break;

      // With a properly formatted input file, this will never be reached
      default  : output << "If you are reading this, the input file was corrupted." << endl;
    }

    // Read the next command
    input >> command;
  }

  // All commands have been read. Close the input file.
  input.close();
}

