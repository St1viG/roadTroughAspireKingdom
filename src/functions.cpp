//
// Created by Me on 2025-01-12.
//
#include "../include/functions.h"

void printMenu() {
    std::cout<<"1. Buy blue and red bags: V"<<std::endl;
    std::cout<<"2. Gift blue and red bag to the poor: B"<<std::endl;
    std::cout<<"3. Find diamond of value x: D[x]"<<std::endl;
    std::cout<<"4. Find moissanite of value x: M[x]"<<std::endl;
    std::cout<<"5. Encounter traveling merchant: T"<<std::endl;
    std::cout<<"6. Encounter traveling baker: P"<<std::endl;
    std::cout<<"7. Approach border cross: G"<<std::endl;
    std::cout<<"8. Thief attack: L"<<std::endl;
    std::cout<<"9. Encounter a rare traveling merchant: R[k]"<<std::endl;
    std::cout<<"10. End game: X"<<std::endl;
    std::cout <<"_____________________"<< std::endl;
}
int checkInput(Heap* &blue, Heap* &red, std::string move) {
    if (!(move[0]=='V'||move[0]=='Q'||move[0]=='X') && blue == nullptr) {
        return 1;
    }
    return 0;
}
void processCmd( Heap* &blue, Heap* &red,std::string line) {
    int wasFile = 1;
    if (line.empty()) {
        std::cin>>line;
        wasFile = 0;
    }
    if (checkInput(blue, red, line)) {
        std::cout <<"_____________________"<< std::endl<<"There are no bags to be used"<<std::endl;
        if (!wasFile)
            processCmd(blue, red);
        return;
    }
    int p = line[0] - 'A';
    if (line.length() == 1) {
        switch (p) {
            //V - Buy blue and red bags
            case 21:
                if (blue != nullptr) {
                    std::cout<<"_____________________"<< std::endl<<"Already bought bags"<<std::endl;
                    break;
                }
                blue = new Heap();
                red = new Heap(false);
                break;
                //B - Gift blue and red bag to the poor
            case 1:
                blue->freeRoots();
                red->freeRoots();
                delete blue;
                delete red;
                blue = nullptr;
                red = nullptr;
                break;
                //T - Encounter traveling merchant
            case 19:
                blue->remove();
                break;
                //P - Encounter traveling baker
            case 15:
                red->remove();
                break;
                //G - Approach border cross
            case 6:
                if (!blue) {
                    std::cout <<"____________________"<< std::endl<<"There are no bags to be shown"<<std::endl;
                    break;
                }
                std::cout <<"____________________"<< std::endl<<"Blue bag:"<<std::endl;
                blue->printHeap();
                std::cout <<"_ _ _ _ _ _ _ _ _ _ _"<< std::endl<<"Red bag:"<<std::endl;
                red->printHeap();
                break;
                //L - Thief attack
            case 11:
                if (blue->numberOfNodes >= red->numberOfNodes) {
                    blue->mergeHeap(red);
                    red = new Heap();
                }else {
                    red->mergeHeap(blue);
                    blue = new Heap();
                }
                break;
                //Q - Print menu
            case 16:
                printMenu();
                break;
                //X - End game
            case 23:
                return;
            default:
                std::cout <<"____________________"<< std::endl<<"Unknown move"<<std::endl;
        }
    }
    else {
        int pos = line.find(']');
        if(line[pos-1]=='[' || line[1]!='['){
            std::cout<<"Invalid syntax"<<std::endl;
        }
        else{
            int number = stoi(line.substr(2,pos - 2));
            switch (p) {
                //D - Find diamond of value x
                case 3:
                    blue->insert(number);
                    break;
                    //M - Find moissanite of value x
                case 12:
                    red->insert(number);
                    break;
                    //R - Encounter a rare traveling merchant
                case 17:
                    if (number/2 > red->numberOfNodes || number/2 > blue->numberOfNodes)
                        std::cout<<"Not enough jewels in one of the bags"<<std::endl;
                    else {
                        for (int i=0; i < number/2; i++)
                            blue->remove();
                        for (int i=0; i < number/2; i++)
                            red->remove();
                    }
                    break;
                default:
                    std::cout <<"____________________"<< std::endl<<"Unknown move"<<std::endl;
            }
        }
    }
    if (!wasFile)
        processCmd(blue, red);
}
void file(Heap* &blue, Heap* &red) {
    std::string fileName, move;
    std::cout<<"Enter name of file:";
    std::cin>>fileName;
    std::ifstream stream(fileName);
    if (!stream.good()) {
        std::cout<<"File not found"<<std::endl;
    }

    while (getline(stream,move)) {
        if (move.empty())
            continue;
        processCmd(blue,red, move);
    }
}
int inputSel() {
    std::cout<<"DURING THE GAME PRESS Q FOR MENU"<<std::endl<<"_____________________"<< std::endl<<"Select input:"<<std::endl<<"1. Console input"<<std::endl<<"2. File input"<<std::endl;
    int mode;
    std::cin>>mode;
    return mode - 1;
}