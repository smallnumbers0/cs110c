//This program is the creation of the UML diagram of Song class
//CS110C Jacky Choi

#include <iostream>
using namespace std;

class Song {
    string name;
    string artist;
public:
    void setName(string n) {
        name = n;
    }
    void setArtist(string a) {
        artist = a;
    }
    string getName() {
        return name;
    }
    string getArtist() {
        return artist;
    }
};

int main() {
    Song song;

    string songName;
    string artistName;
    cout<<"What is the song name?"<<endl;
    getline(cin, songName);
    cout<<"What is the artist name?"<<endl;
    getline(cin, artistName);
    song.setName(songName);
    song.setArtist(artistName);
    
    cout<<"The song name is "<<song.getName()<<endl;
    cout<<"The artist name is "<<song.getArtist()<<endl;
    return 0;
}

/*
jackychoi@Jackys-MacBook-Pro week1 % ./a.out
What is the song name?
told
What is the artist name?
you
The song name is told
The artist name is you
jackychoi@Jackys-MacBook-Pro week1 % 
*/