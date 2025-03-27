//Gianni Russell
//Csci 135
//Prof Tong Yi 
//Lab 11 Task C

#include <string>
#include <iostream>
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


class Network {
private:
  static const int MAX_USERS = 20; // max number of user profiles
  int numUsers;                    // number of registered users
  Profile profiles[MAX_USERS];     // user profiles array:
                                   // mapping integer ID -> Profile
  bool following[MAX_USERS][MAX_USERS];
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
    following [id1][id2] = true;
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
        for (int j = 0; j <numUsers; j++) {
            if (following[i][j] == true) {
                cout << profiles[i].printUsername() << " -> ";
                cout << profiles[j].printUsername() << endl;
            }
        }
    }
    cout << "}" << endl;
}

int main() {
    Network nw;
    // add three users
    nw.addUser("mario", "Mario");
    nw.addUser("luigi", "Luigi");
    nw.addUser("yoshi", "Yoshi");

    // make them follow each other
    nw.follow("mario", "luigi");
    nw.follow("mario", "yoshi");
    nw.follow("luigi", "mario");
    nw.follow("luigi", "yoshi");
    nw.follow("yoshi", "mario");
    nw.follow("yoshi", "luigi");

    // add a user who does not follow others
    nw.addUser("wario", "Wario");
    
    // add clone users who follow @mario
    for(int i = 2; i < 6; i++) {
        string usrn = "mario" + to_string(i);
        string dspn = "Mario " + to_string(i);
        nw.addUser(usrn, dspn);
        nw.follow(usrn, "mario");
    }
    // additionally, make @mario2 follow @luigi
    nw.follow("mario2", "luigi");

    nw.printDot();
}