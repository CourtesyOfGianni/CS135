#include <iostream>
#include <string>
using namespace std;

class Profile {
private:
    string username;
    string displayname;
public:
    // Profile constructor for a user (initializing 
    // private variables username=usrn, displayname=dspn)
    Profile(string usrn, string dspn);
    // Default Profile constructor (username="", displayname="")
    Profile();
    // Return username
    string getUsername();
    // Return name in the format: "displayname (@username)"
    string getFullName();
    // Change display name
    void setDisplayName(string dspn);
    string printUsername();
};

Profile::Profile(string usrn, string dspn) {
    username = usrn;
    displayname = dspn;
}

Profile::Profile() {
    username = "";
    displayname = "";
}

string Profile::getUsername() {
    return username;
}

string Profile::getFullName(){
    return displayname + " (@" + username + ")";
}

void Profile::setDisplayName(string dspn){
    displayname = dspn;
}

string Profile::printUsername(){
    return "\"@" + username + "\"";
}

// New struct for posts
struct Post{
    string username;
    string message;
};

class Network {
private:
    static const int MAX_USERS = 20; // max number of user profiles
    int numUsers;                    // number of registered users
    Profile profiles[MAX_USERS];     // user profiles array:
                                   // mapping integer ID -> Profile
    bool following[MAX_USERS][MAX_USERS];
    static const int MAX_POSTS = 100;         // new
    int numPosts;                             // new
    Post posts[MAX_POSTS];                    // new
    // Returns user ID (index in the 'profiles' array) by their username
    // (or -1 if username is not found)
    int findID (string usrn);
public:
    // Constructor, makes an empty network (numUsers = 0)
    Network();
    // Attempts to sign up a new user with specified username and displayname
    // return true if the operation was successful, otherwise return false
    bool addUser(string usrn, string dspn);
    bool follow(string usrn1, string usrn2); // new
    void printDot();  
    bool writePost(string usrn, string msg);  // new
    bool printTimeline(string usrn);          // new
};

int Network::findID (string usrn){
    for(int i = 0; i < numUsers; i++) {
        //profiles[i] is a profile object
        if (profiles[i].getUsername() == usrn ) {
            return i;
        }
    }
    return -1;    //if username is not in use
}

Network::Network() {
    numUsers = 0;
    numPosts = 0;  // Initialize numPosts to 0
    //initialize 2d array
    for (int i = 0; i < MAX_USERS; i++) {
        for (int j = 0; j < MAX_USERS; j++) {
            following[i][j] = false;
        }
    }
}

bool Network::addUser(string usrn, string dspn){
    //username must contain text
    if (usrn == "") {
        return false;
    }
    //network must have space and the username must be unique
    if (numUsers < MAX_USERS && findID(usrn) == -1) {
        //username must be alphanumeric
        for(int i = 0; i < usrn.length(); i++) {
            if(!isalnum(usrn[i])) {
                return false; //not valid username
            }
        }
        //all conditions are met
        Profile p(usrn, dspn);
        profiles[numUsers] = p;
        numUsers++;
        return true;
    } else { //username is not unique or profiles are at max capacity
        return false;
    }
}

bool Network::follow(string usrn1, string usrn2) {
    int id1 = findID(usrn1); //-1 if usrn1 not in network
    int id2 = findID(usrn2);

    //both usrns exist
    if (id1 != -1 && id2 != -1) {
        following[id1][id2] = true;
        return true;
    } else {
        return false; //operation not successful
    }
}

void Network::printDot() {
    cout << "digraph {" << endl;

    //print all users in network
    for(int i = 0; i < numUsers; i++) {
        cout << profiles[i].printUsername() << endl;
    }
    cout << endl;
    //print all following relationships
    for(int i = 0; i < numUsers; i++) {
        for (int j = 0; j < numUsers; j++) {
            if (following[i][j] == true) {
                cout << profiles[i].printUsername() << " -> ";
                cout << profiles[j].printUsername() << endl;
            }
        }
    }
    cout << "}" << endl;
}

// Add a new post
bool Network::writePost(string usrn, string msg) {
    int userId = findID(usrn);
    
    // Check if user exists and posts array is not full
    if (userId != -1 && numPosts < MAX_POSTS) {
        // Add post to the posts array
        posts[numPosts].username = usrn;
        posts[numPosts].message = msg;
        numPosts++;
        return true;
    }
    
    return false;
}

// Print user's timeline
bool Network::printTimeline(string usrn) {
    int userId = findID(usrn);
    
    // Check if user exists
    if (userId == -1) {
        return false;
    }
    
    // Loop through all posts in reverse order (newest first)
    for (int i = numPosts - 1; i >= 0; i--) {
        Post currentPost = posts[i];
        int postAuthorId = findID(currentPost.username);
        
        // Print posts by the user or by people they follow
        if (currentPost.username == usrn || following[userId][postAuthorId]) {
            // Get the profile of the post author to access their display name
            Profile postAuthor = profiles[postAuthorId];
            // Print in format: Displayname (@username): message
            cout << postAuthor.getFullName() << ": " << currentPost.message << endl;
        }
    }
    
    return true;
}

int main() {
  Network nw;
  // add three users
  nw.addUser("mario", "Mario");
  nw.addUser("luigi", "Luigi");
  nw.addUser("yoshi", "Yoshi");
   
  nw.follow("mario", "luigi");
  nw.follow("luigi", "mario");
  nw.follow("luigi", "yoshi");
  nw.follow("yoshi", "mario");

  // write some posts
  nw.writePost("mario", "It's a-me, Mario!");
  nw.writePost("luigi", "Hey hey!");
  nw.writePost("mario", "Hi Luigi!");
  nw.writePost("yoshi", "Test 1");
  nw.writePost("yoshi", "Test 2");
  nw.writePost("luigi", "I just hope this crazy plan of yours works!");
  nw.writePost("mario", "My crazy plans always work!");
  nw.writePost("yoshi", "Test 3");
  nw.writePost("yoshi", "Test 4");
  nw.writePost("yoshi", "Test 5");

  cout << endl;
  cout << "======= Mario's timeline =======" << endl;
  nw.printTimeline("mario");
  cout << endl;

  cout << "======= Yoshi's timeline =======" << endl;
  nw.printTimeline("yoshi");
  cout << endl;
}