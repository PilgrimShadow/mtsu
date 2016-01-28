/*
File: DNAList.h
Auth: Jordan Dodson
Date: 1/23/16
Info: Specification file for a class representing a list of DNA sequences.
*/

#ifndef DNALIST_H
#define DNALIST_H

#include "DNA.h"

class DNAList {

private:

  // Struct that will be form the nodes of the linked list.
  struct DNANode {
    DNANode *next;
    DNA*     dna;
  };

  // Pointer to head of list
  DNANode* head;

  // The number of items in the list
  int _size;

public:

  // Default constructor
  DNAList();

  ~DNAList();

  // Add a new sequence to the list
  void push_back(DNA* newDNA);

  // Return a pointer to the sequence with the given id or NULL
  // if no match is found
  DNA* find(int id) const;

  bool obliterate(int id);

  // Return the number of items in the list.
  int size() const;
};

#endif
