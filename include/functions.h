//
// Created by Me on 2025-01-12.
//
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <fstream>

#include "Heap.h"

void printMenu();

int checkInput(Heap* &blue, Heap* &red, std::string move);

void processCmd( Heap* &blue, Heap* &red,std::string line = "");

void file(Heap* &blue, Heap* &red);

int inputSel();

#endif //FUNCTIONS_H
