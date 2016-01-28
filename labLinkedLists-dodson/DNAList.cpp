/*
File: DNAList.cpp
Auth: Jordan Dodson
Date: 1/23/16
Info: Implementation file for a class representing a list of DNA sequences.
*/


#include "DNAList.h"

// Default constructor
DNAList::DNAList() {
  head = NULL;
  _size = 0;
}

DNAList::~DNAList() {
  // DNANode pointers used to iterate over the nodes in the list.
  DNANode *node_ptr, *tmp;

  node_ptr = head;

  // For each node in the list, delete the data that it references then
  // delete the node itself.
  while (node_ptr != NULL) {
    delete node_ptr->dna;
    tmp = node_ptr->next;
    delete node_ptr;
    node_ptr = tmp;
  }
}

// Add a new sequence to the list
void DNAList::push_back(DNA* newDNA) {

  // Allocate a new node for our list
  DNANode* new_node = new DNANode;

  // Set the data for the new node and add it to the list
  new_node->dna  = newDNA;
  new_node->next = head;
  head = new_node;

  // Increment the size of the list
  _size++;
}

// Return a pointer to the sequence with the given id or NULL
// if no match is found
DNA* DNAList::find(int id) const {
  // Pointer to iterate through the list nodes
  DNANode* node_ptr;

  // Start searching at the head
  node_ptr = head;

  // Examine nodes until a match is found or none remain
  while (node_ptr != NULL) {
    if (node_ptr->dna->getId() == id) {
      return node_ptr->dna;
    }
    node_ptr = node_ptr->next;
  }

  // Return NULL if no match is found
  return NULL;  
}

bool DNAList::obliterate(int id) {
  DNANode* node_ptr;

  // The list was empty
  if (_size == 0) {
    return false;
  }

  node_ptr = head;

  // Check the first item in the list
  if (node_ptr->dna->getId() == id) {
    head = node_ptr->next;
    delete node_ptr->dna;
    delete node_ptr;
    _size--;
    return true;
  }

  // Check the remaining items in the list
  while (node_ptr->next != NULL) {

    // See if the IDs match
    if (node_ptr->next->dna->getId() == id) {
      DNANode *tmp = node_ptr->next;
      node_ptr->next = node_ptr->next->next;
      delete tmp->dna;
      delete tmp;
      _size--;
      return true;
    }

    // Advance the node pointer to the next node
    node_ptr = node_ptr->next;
  }

  // Return false if the sequence was not found
  return false;
}

// Return the number of items in the list.
int DNAList::size() const {
  return _size;
}

