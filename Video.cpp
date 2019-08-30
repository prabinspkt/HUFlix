#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <fstream>
#include <iomanip>

using namespace std;

#include "Video.h"

Video::Video(){                                                                      // default constructor
   duration = "none";
   title = "none";
   genre = "none";
   rating = "none";
   user_rating = "none";
   year = "none";
}

Video::Video(string title, string genre,string duration, string user_rating, string rating, string year){   //non-default constructor
   this->title = title;
   this->genre = genre;
   this->duration = duration;
   this->user_rating = user_rating;
   this->rating = rating;
   this->year = year;
   }

string Video::getTitle(){                // accessor
   return title;
   }

void Video::setYear(string video_year){    // mutator
   year = video_year;
   }
string Video::getGenre(){              // accessor 
   return genre;
   }
   
string Video:: getDuration(){            // accessor
   return duration;
   }

string Video::getUserRating(){          // accessor
   return user_rating;
   }

string Video::getRating() {           // accessor
   return rating;
   }

string Video::getYear() {            // accessor
   return year;
   }

void Video::setDuration(string duration_to_set){     // mutator
   duration = duration_to_set;
   }