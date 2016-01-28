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

// Default constructor
SequenceDatabase::SequenceDatabase() {
  output.open("output.txt");
}

// Constructor to use the given file as an output file.
SequenceDatabase::SequenceDatabase(string output_name) {
  output.open(output_name);
}

// Destructor
SequenceDatabase::~SequenceDatabase() {

  // Close the output file
  output.close();
}

// Function to read database commands from the given file.
void SequenceDatabase::importEntries(string input_name) {
  ifstream input;                    // The stream object used to read the input file.
  char     cmd;                      // Character representing a database command.
  string   label, sequence;          // Variables to hold the sequence information
  int      id, length, startIndex;   // when parsing a line of the input file.
  DNA*     dna_ptr;                  // Will store the result of the DNAList::find() method.

  // Open our input file for reading
  input.open(input_name);

  // Record that we are parsing the given file
  output << "Importing " << input_name << " ..." << endl;

  // Get the first command
  input >> cmd;

  // Read commands until the end of the input file is reached.
  // Dispatch based on the command and perform the appropriate action.
  while (input) {
    switch (cmd) {
      // Add a new sequence to the database
      case 'D' : // Parse and store the entry data
                 input >> label >> id >> sequence >> length >> startIndex;

                 // Allocate memory for a new DNA object and add it to the database
                 dna_list.push_back(new DNA(label, id, sequence, length, startIndex));

                 output << "Adding " << id << " ..." << endl << endl;
                 break;

      // Display info on a particular sequence
      case 'P' : input >> id;
                 output << "Printing " << id << " ..." << endl;
                 dna_ptr = dna_list.find(id);
                 if (dna_ptr == NULL) {
                   output << "Can not find item (" << id << ")!";
                 } else {
                   output << "DNA:\tLabel: " << dna_ptr->getLabel() << "\tID: " << id
                          << "\tSequence: " << dna_ptr->getSequence() << "\tLength: "
                          << dna_ptr->getLength() << "\tcDNAStartIndex: " << dna_ptr->getStartIndex();
                 }
                 output << endl << endl;
                 break;

      // Obliterate a particular sequence
      case 'O' : input >> id;
                 output << "Obliterating " << id << " ..." << endl;
                 if (!dna_list.obliterate(id)) {
                   output << "Can not delete DNA (" << id << "), NOT found!" << endl;
                 }
                 output << endl;
                 break;

      // Display the number of entries in the database
      case 'S' : output << "Entries: " << dna_list.size() << endl << endl;
                 break;
      default  : ;
    }

    // Get the next command
    input >> cmd;
  }

  // Close the input file
  input.close();
}

