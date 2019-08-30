#ifndef SEARCH_H
#define SEARCH_H

#include "Video.h"

class Search{ // class declaration
   public:
	 		// Static function so that an object need not be declared to call this function
      static int binarySearch(vector<Video>& playlist, int size, string value);
   };
#endif