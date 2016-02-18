/*
FILE: sequenceDatabase.cpp
AUTH: Jordan Dodson
DATE: 1/22/2016
INFO: Implementation file for a class that maintains a database of labeled biological sequences.
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

  // Free all sequence objects in the database
  for (Sequence* seq_ptr : seq_list) {
    delete seq_ptr;
  }

  // Close the output file
  output.close();
}

// Look for a sequence with the given id.
Sequence* SequenceDatabase::find(int id) {
  for (Sequence* seq_ptr : seq_list) {
    if (seq_ptr->getId() == id) {
      return seq_ptr;
    }
  }

  // We didn't find a sequence with the given id.
  return nullptr;
}

// Obliterate the sequence with the given id.
bool SequenceDatabase::obliterate(int id) {

  list<Sequence*>::iterator iter;

  for (iter = seq_list.begin(); iter != seq_list.end(); iter++) {
    if ((*iter)->getId() == id) {
      seq_list.erase(iter);
      return true;
    }
  }

  // No matching id was encountered
  return false;
}

// Function to read database commands from the given file.
void SequenceDatabase::importEntries(string input_name) {
  ifstream  input;                       // The stream object used to read the input file.
  char      cmd;                         // Character representing a database command.
  string    label, sequence, type;       // Variables to hold the sequence information
  int       id, length, startIndex, orf; // when parsing a line of the input file.
  Sequence* seq_ptr;                     // Will store the result of the find() method.

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
                 seq_list.push_back(new DNA(label, id, sequence, length, startIndex));

                 output << "Adding " << id << " ..." << endl << endl;
                 break;

      case 'R' : 
                 input >> label >> id >> sequence >> length >> type;

                 seq_list.push_back(new RNA(label, id, sequence, length, type));

                 output << "Adding " << id << " ..." << endl << endl;
                 break;

      case 'A' : 
                 input >> label >> id >> sequence >> length >> orf;

                 seq_list.push_back(new AA(label, id, sequence, length, orf));

                 output << "Adding " << id << " ..." << endl << endl;
                 break;

      // Display info on a particular sequence
      case 'P' : input >> id;
                 output << "Printing " << id << " ..." << endl;
                 seq_ptr = find(id);
                 if (seq_ptr == nullptr) {
                   output << "Can not find item (" << id << ")!" << endl;
                 } else {
                   seq_ptr->print(output);
                 }
                 output << endl;
                 break;

      // Obliterate a particular sequence
      case 'O' : input >> id;
                 output << "Obliterating " << id << " ..." << endl;
                 if (!obliterate(id)) {
                   output << "Can not delete item (" << id << "), NOT found!" << endl;
                 }
                 output << endl;
                 break;

      // Display the number of entries in the database
      case 'S' : output << "Entries: " << seq_list.size() << " total" << endl << endl;
                 break;
      default  : ;
    }

    // Get the next command
    input >> cmd;
  }

  // Close the input file
  input.close();
}

