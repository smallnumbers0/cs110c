// Array-based List Class for Playlists
// Your name here: JAcky Choi
// CS110C


#include <string>
#include <iostream>
#include <stdexcept>
using namespace std;


template<class ItemType>
class List {
private:
    static const int CHUNK_SIZE=2;
    ItemType *list;
    int numItems;
    int maxItems;
public:
    // default constructor and destructor
    List() { numItems = 0; maxItems = CHUNK_SIZE;
        list = new ItemType[CHUNK_SIZE]; }
    ~List() { delete [] list; }
    
    // list member functions
    bool isEmpty()  const { return numItems==0; }
    int getLength() const { return numItems; }
    bool insert(int pos, const ItemType& item);
    bool remove(int pos);
    
    // clear the list
    // clear can simply set numItems to zero.  The array list may still contain
    // items already inserted into the list, but since numItems is zero, there
    // isn't any way to get at them using getEntry() or setEntry()
    void clear() { numItems = 0; }
    
    // return entry at postion pos
    // throw invalid_argument if pos<1 or pos>getLength()
    ItemType getEntry(int pos) const;
    
    // set entry at postion pos to item
    // throw invalid_argument if pos<1 or pos>getLength()
    void setEntry(int pos, const ItemType& item);
};

template<class ItemType>
bool List<ItemType>::insert(int pos, const ItemType& item) {
    bool canAdd;
    
    canAdd = ((pos > 0) && (pos <= numItems + 1) && (numItems <= maxItems));
    if (canAdd) {
        //allocate more memory if full
        if(numItems == maxItems) {
            maxItems += CHUNK_SIZE; 
            ItemType* newList = new ItemType[maxItems];
            for (int i = 0; i < numItems; ++i) {
                newList[i] = list[i];
            }
            delete[] list;
            list = newList;
        
        }
        // first, we have to move everything after our insertion point over one
        // position to make room for our new item.  start at the back of the list.
        // don't forget arrays start at postion zero and our list ADT starts at
        // position 1.
        for(int i=numItems; i>=pos; i--)
            list[i] = list[i-1];
        
        // now put our item at position pos-1
        list[pos-1] = item;
        
        numItems++;
    }
    
    return canAdd;
}

template<class ItemType>
ItemType List<ItemType>::getEntry(int pos) const {
    if(pos<1 || pos>getLength()) {
        throw invalid_argument("ERROR: getEntry() using invalid position");
    }
    return list[pos-1];
}

// TODO: add implementations for setEntry() and remove() functions

template<class ItemType>
void List<ItemType>::setEntry(int pos, const ItemType& item) {
    if(pos < 1 || pos > numItems) {
        throw invalid_argument("Position is not valid for setEntry()");
    }
    list[pos-1] = item;       
}

template<class ItemType>
bool List<ItemType>::remove(int pos) {
    if (pos < 1 || pos > numItems) {
        return false; 
    }
    for (int i = pos - 1; i < numItems - 1; i++) {
        list[i] = list[i + 1];
    }
    --numItems;
    return true;
}

// Utility function to input a track number with some input checking
// to make sure it's a number
int getTrack() {
    bool inputCheck;
    int trackNumber;
    
    do {
        inputCheck = true;
        cout << "Please enter the track number you'd like to view: ";
        if (!(cin >> trackNumber)) {
            cout << "Please enter numbers only.\n";
            cin.clear();
            cin.ignore(10000,'\n');
            inputCheck = false;
        }
    } while (!inputCheck);
    return trackNumber;
}


int main() {
    List<string> songs;
    char goAgain = 'y';
    int trackNumber;
    string trackName;
    
    
    cout<<"Inserting 4 songs when starting CHUNK_SIZE is 2"<<endl;
    songs.insert(1, "One More Saturday Night");
    songs.insert(1, "Friday I'm in Love");
    songs.insert(3, "Sunday Morning Coming Down");
    songs.insert(1, "California Love");
    
    cout << "Welcome!  There are " << songs.getLength() << " tracks.\n";
        
       
        cout<<"Setting entry 3 to a song called Solo"<<endl;
        songs.setEntry(3, "Solo");      
        //cout<<"Setting entry -1 to a song called Cool"<<endl;
        // songs.setEntry(-1, "Cool"); output 2 with exception for setEntry
        trackNumber = getTrack();
        try {
            trackName = songs.getEntry(trackNumber);
        }
        catch (invalid_argument arg) {
            cout << arg.what() << endl;
            trackName = "No Track";
        }
        cout << "Your track name is " << trackName << endl;
        cout<<"Removing traack 3"<<endl;
        songs.remove(3);
        trackNumber = getTrack();
        try {
            trackName = songs.getEntry(trackNumber);
        }
        catch (invalid_argument arg) {
            cout << arg.what() << endl;
            trackName = "No Track";
        }
         cout << "Your track name is " << trackName << endl;
    
    cout << "Rock on!\n";
    return 0;
}

/*
Output 1 showing setEntry and remove

jackychoi@Jackys-MacBook-Pro module2 % g++ assignment2.cpp
jackychoi@Jackys-MacBook-Pro module2 % ./a.out            
Inserting 4 songs when starting CHUNK_SIZE is 2
Welcome!  There are 4 tracks.
Setting entry 3 to a song called Solo
Please enter the track number you'd like to view: 3
Your track name is Solo
Removing traack 3
Please enter the track number you'd like to view: 3
Your track name is Sunday Morning Coming Down
Rock on!
jackychoi@Jackys-MacBook-Pro module2 % 
*/

/*
Output 2 showing setEntry Exception

jackychoi@Jackys-MacBook-Pro module2 % g++ assignment2.cpp
jackychoi@Jackys-MacBook-Pro module2 % ./a.out   
Inserting 4 songs when starting CHUNK_SIZE is 2         
Welcome!  There are 4 tracks.
Setting entry -1 to a song called Cool
libc++abi: terminating due to uncaught exception of type std::invalid_argument: Position is not valid for setEntry
zsh: abort      ./a.out
jackychoi@Jackys-MacBook-Pro module2 % 
*/