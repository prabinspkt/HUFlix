#include <iostream>
#include <vector>
using namespace std;

#include "Sort.h"

// Insertion sort function that sorts the shows/movies based on the title of the show/movie
void Sort::InsertionSort(vector<Video>& items){
typedef std::vector<Video>::size_type size_type;
	for ( size_type i = 1; i < items.size(); ++i ) {
		Video tmp = items[i];
		size_type j = i;
		for ( ; j !=  0 && tmp.getTitle() < items[j-1].getTitle(); --j ){
				items[j] = items[j-1];
		}
		if ( j != i ) items[j] = tmp;
}

}