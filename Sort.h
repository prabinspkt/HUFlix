#ifndef SORT_H
#define SORT_H

#include "Video.h"

class Sort{     // class declaration
   public:
	 		// Static function is declared so that an object need not be created for calling this function
      static void InsertionSort(vector<Video>& items);
   };
#endif