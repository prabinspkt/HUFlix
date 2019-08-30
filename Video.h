#ifndef VIDEO_H
#define VIDEO_H
 
#include <string>
using namespace std; 

class Video {
 public:
    Video();              // default constructor
    Video(string title, string genre, string duration, string user_rating, string rating, string year); // non-default constructor
    string getTitle();        // accessor
    string getGenre();     // accessors
    string getDuration();  // accessor
    string getUserRating();   // accessor
    string getRating();  // accessor
    string getYear();   // accessor
    void setYear(string video_year); // mutator
    void setDuration(string duration_to_set); // mutator                                                       
 protected:
    string title;   
    string duration;                                               // protected data member
    string genre;                                                  // protected data member
    string rating;                                                 // protected data member
    string user_rating;                                            // protected data member
    string year;                                                   // protected data member
};
#endif