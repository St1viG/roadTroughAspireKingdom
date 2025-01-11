#include <iostream>
#include "Heap.h"
// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {
    Heap heap1 = Heap();
    Heap heap2 = Heap();
    heap1.insert(10);
    heap1.insert(20);
    heap1.insert(30);
    heap2.insert(1);
    heap1.Heap::mergeHeap(&heap2);
    heap1.printHeap();
    // heap2.printHeap();

    return 0;
}

