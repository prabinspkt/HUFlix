#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>
#include <iomanip>
#include <cctype>
#include<bits/stdc++.h> // stl library imported for conversion of string to lower case

#include "Video.h"
#include "Sort.h"
#include "Search.h"

using namespace std;

int main() {
	// The vector that will store the movie/show selected based on user input.
	vector<Video> video_playlist; 

	ifstream myfile;  // File stream
	// Open file and declare some variables which will be used to read data from file.
	myfile.open("FavoriteTVShowMovies.txt");  // opens the file
	string title, genre, duration, user_rating, rating, year;
	string time_to_watch, rating_to_previous, genre_to_watch;
	string user_title, original_genre;   
	int user_title_index;

  cout << "*******************************************"<< endl;
  cout << "* Partners - Anmol Gautam, Prabin Sapkota *"<< endl;
  cout << "* Final Assignment.                       *"<< endl;
  cout << "* Creating a Playlist for the User.       *"<< endl;
  cout << "*******************************************" << endl;
  cout << endl << endl; 

	// Ask for user input
	cout << "Enter the free time you have to watch a show:"<< endl;
	getline(cin, time_to_watch);  // user input for free time
	cout << "Enter the rating you gave to the previous show:"<< endl;
	getline(cin, rating_to_previous);   // user input for previous rating
	cout << "Enter the genre you want to watch: "<< endl;
	getline(cin, genre_to_watch);   // user input for their preferred 
	cout << endl;
  
  // Read the first line of the file and ignore it.
	getline(myfile, title, '\t'); 
	getline(myfile, genre, '\t');
	getline(myfile, duration, '\t');
	getline(myfile, user_rating, '\t');
	getline(myfile, rating, '\t');
	getline(myfile, year, '\n');

  // Read from the file until the end of the file
	while(!myfile.eof()) {
    try{
			// If any of the user input is empty, ask throw a runtime_error and ask for user input again
      if (time_to_watch.empty() || rating_to_previous.empty() ||genre_to_watch.empty()){
        throw runtime_error("One of the values that you entered is empty. Please try again: ");
      }
      
      getline(myfile, title, '\t');
      getline(myfile, genre, '\t');
      getline(myfile, duration, '\t');
      getline(myfile, user_rating, '\t');
      getline(myfile, rating, '\t');
      getline(myfile, year, '\n');

			// Transform user input genre to lowercase for comparison later
      transform(genre_to_watch.begin(), genre_to_watch.end(), genre_to_watch.begin(), ::tolower);
			// Store genre before transforming it into lower case for comparison
      original_genre = genre;  
			// Transform genre read from file to lowercase for comparison later
      transform(genre.begin(), genre.end(), genre.begin(), ::tolower);

			// Decide whether the movie/show read from file is appropriate to be in the playlist of the user
			// The show/movie is fit to be in the playlist if its duration is less than or equal to time user has and if the genre user entered is one of the genre of show/movie and if the rating of the movie/show is greater than or equal to the genre of the rating user gave to the last show/movie. 
      if ((stoi(duration) <= stoi(time_to_watch)) &&  (genre.find(genre_to_watch) != std::string::npos) && (stoi(user_rating) >= stoi(rating_to_previous))){
        Video video_item(title, original_genre, duration, user_rating, rating, year);
        video_playlist.push_back(video_item);
        }
		// Catch exception if the user enters non-numeric values for rating and free time
		// Ask user for input again if exception is caught
    } catch(invalid_argument& e) { 
        cerr << "Invalid values entered. Please try again." <<  endl;
        cout << endl;
        cout << "***************************************" << endl;
        cout << "Enter the free time you have to watch a show:"<< endl;
        getline(cin, time_to_watch);
        cout << "Enter the rating you gave to the previous show:"<< endl;
        getline(cin, rating_to_previous);
        cout << "Enter the genre you want to watch:"<< endl;
        getline(cin, genre_to_watch);
        cout << endl;
		// Catch a runtime exception and ask user for input again if exception is caught
    } catch(runtime_error& r){
        cerr << r.what() << endl;
        cout << "***************************************" << endl;
        cout << "Enter the free time you have to watch a show:"<< endl;
        getline(cin, time_to_watch);
        cout << "Enter the rating you gave to the previous show:"<< endl;
        getline(cin, rating_to_previous);
        cout << "Enter the genre you want to watch:"<< endl;
        getline(cin, genre_to_watch);
        cout << endl;
      }
    }
    try{
			// If the playlist is empty, throw an int exception which is caught below
      if (video_playlist.size() == 0){
        throw 10;
      }
			// Sort the elements in the playlist to simplify searching process
      Sort::InsertionSort(video_playlist);
			// Display the movie/shows from the playlist of the user
      cout << "Video items in your playlist are: " << endl;
      for (int i = 0; i < video_playlist.size(); i++) {
        cout << video_playlist[i].getTitle() << endl;
      }
      cout << endl;

			// Ask for the name of the show/movie that the user wants details of
      cout << "Enter the title of movie/show you want the details of: " << endl;
      getline(cin, user_title);  // user input of title user wants details of
      user_title_index = Search::binarySearch(video_playlist, video_playlist.size(), user_title);
      // Throw a char exception if the name/title of movie/show user entered is not present in the playlist
			if (user_title_index == -1){
        throw 'n';
      }
      cout << endl;

      // Detail of the requested show/movie if found in the playlist
      cout << "Details of the requested show:" << endl;
      cout << "Title: " << video_playlist[user_title_index].getTitle() << endl;
      cout << "Genre: " << video_playlist[user_title_index].getGenre() << endl;
      cout << "Duration (minutes): " << video_playlist[user_title_index].getDuration() << endl;
      cout << "User Rating: " << video_playlist[user_title_index].getUserRating() << endl;
      cout << "Rating: " << video_playlist[user_title_index].getRating() << endl;
      cout << "Year: " << video_playlist[user_title_index].getYear() << endl;
      cout << endl;
    } 
		// Catch the int exception and display message saying there are no items to put in user's playlist
    catch (int a){
    cout << endl;
    cout << "Sorry! there are no items to put in your playlist." << endl;
    } 
    // Catch the char exception and display a message saying that the item whose details the user requested is not in his/her playlist
    catch (char b){
      cout << endl;
      cout << "Sorry! this item is not in your playlist."<< endl;
    }
	return 0;
}