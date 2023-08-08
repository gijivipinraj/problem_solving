//
//  main.cpp
//  TowerOfHanoi
//
//  Created by Giji Vipinraj on 08/08/23.
//

#include <iostream>
#include <string>

using namespace std;


/**
 * Tower Of Hanoi Problem
 *      A         B         C
 *      |           |          |
 *    |       |        |          |
 *   |            |     |          |
 *  Rules :
 *   1. One disc can move at a time
 *   2. Should not place big disc above small disc
 *
 * Function towerOfhanoi() will move the disc in a recurssive maner to another rod.
 * Solution: First it always target to move n-1 discs from rod A to C, then it will move the
 * nth rod to B. It gain move the n-1 discs from C to B. You will be thinking that how it will
 * move n-1 discs at a time? It will again perform the same steps to divide the discs as n-2
 * and move the (n-1)th disc. The same carried out recurrsively till it reach one disc.
 *
 *Arguments:
 * n - number of discs to move in a rod
 * srcRod - The rod number from which we have to move the disc
 * destRod - The destination rod to which the discs have to be moved
 * spareRod - The rod which is not used in this movement
 *
 *Return:
 *  None
 */
void towerOfHanoi(int n, char srcRod, char destRod, char spareRod)
{
    if (n == 1)
    {
        cout << "Moving the disc from " << srcRod << " to " << destRod << endl;
        return;
    }
    
    towerOfHanoi(n-1, srcRod, spareRod, destRod);
    cout << "Moving the disc from " << srcRod << " to " << destRod << endl;
    towerOfHanoi(n-1, spareRod, destRod, srcRod);
}



int main(int argc, const char * argv[]) {
    // insert code here...
    
    if (argc < 2) {
        cout << "Invalid Arguments!" << endl;
        cout << "Usage : ./TowerOfHanoi num\n \
        num - Number of discs" << endl;
        return -1;
    }
    
    cout <<  "TOWER OF HANOI" << endl;
    cout <<  endl << "Going to shift " << argv[1] << " discs!"<< endl << endl;
    towerOfHanoi(stoi(argv[1]), 'A', 'C', 'B');
    
    
    return 0;
}
