#include <iostream>
#include "Heap.h"
// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {
    Heap heap1 = Heap(0);
    Heap heap2 = Heap(0);
    heap1.insert(10);
    heap1.insert(20);
    heap1.insert(30);
    heap1.insert(40);
    heap1.insert(50);
    heap1.insert(60);
    heap1.insert(70);
    heap1.insert(80);
    heap1.insert(90);
    heap1.insert(100);
    heap2.insert(1);
    heap2.insert(2);
    heap2.insert(3);
    heap2.insert(4);
    heap2.insert(0);
    heap2.insert(5);
    heap1.printHeap();
    std::cout <<"____________________"<< std::endl;
    heap2.printHeap();
    std::cout <<"____________________"<< std::endl;
    heap1.Heap::mergeHeap(&heap2);
    heap1.printHeap();


    return 0;
}

