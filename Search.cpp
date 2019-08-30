#include <iostream>
#include <string>
#include <vector>

using namespace std;

#include "Search.h"
#include "Video.h"

int Search::binarySearch(vector<Video>& playlist, int size, string value){
    int first = 0,             // First array element
        last = size - 1,       // Last array element
        middle,                // Mid point of search
        position = -1;         // Position of search value
    bool found = false;        // Flag

    while (!found && first <= last){
        middle = (first + last) / 2;     // Calculate mid point
        if (playlist[middle].getTitle() == value){      // If value is found at mid
            found = true;
            position = middle;
        }
        else if (playlist[middle].getTitle() > value){  // If value is in lower half
            last = middle - 1;
				}
        else {
            first = middle + 1;           // If value is in upper half
				}
    }
    return position;
}