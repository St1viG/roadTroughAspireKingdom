//
// Created by Me on 2025-01-10.
//
#include "../include/Heap.h"
#include "../include/functions.h"

int main() {
    Heap* blue = nullptr, *red = nullptr;
    if (inputSel()) {
        file(blue,red);
    }else {
        processCmd(blue,red);
    }
    return 0;
}

