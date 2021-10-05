// EvaluationTreeSort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "handler.h"

int main()
{

    /*
    int size = 1000;

    int * data = new int[size];


    for (int i = 0; i < size; i++) data[i] = i + 1;

    evalTree testBed(data, size);

    //testBed.printTree();

    printf("\n");

    for (int i = 0; i < size; i++)
    {
        printf("(%d) ",testBed.takeRoot(i+1));
        //testBed.printTree();
    }
    */

    handler testBed(10000000,false,10);
    testBed.randExperiment();

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
