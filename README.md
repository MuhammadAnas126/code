#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <ctime>
#include <chrono>
#include <thread> // For sleep functionality
using namespace std;
using namespace std::this_thread;
using namespace std::chrono;

// Using string for storing months
int indexmonths, committees, luckydraw;
vector<string> members;
string months[12] = {
    "January", "February", "March", "April", "May", "June",
    "July", "August", "September", "October", "November", "December"
};

// Adding functions for better Readability
// Function to display header
void displayEnhancement() {
    cout << "====================================\n";
    cout << "         Committee System      \n";
    cout << "====================================\n\n";
}

// Function to get committee details
void getCommitteeInformation() {
    int count;
    cout << "How many committees do you want? ";
    cin >> committees;

    cout << "\nEnter the Starting month of committee between (1-12): ";
    cin >> indexmonths;

    //using if to avoid out of bound errors
    if (indexmonths < 1 || indexmonths > 12) {
        cout << "Invalid month! Please enter a value between 1 and 12.\n";
        exit(0);
    }

//Calculating starting and ending months
    int endMonth = (indexmonths + committees - 2) % 12;
    cout << "\nYour committee will run from *" << months[indexmonths - 1] 
         << "* to *" << months[endMonth] << "*\n" << endl;

    cout << "How many volunteers do you want: ";
    cin >> count;
    members.resize(count);
    //Taking members for committee
    for (int i = 0; i < count; i++) {
        cout << "Enter the name of volunteer " << i + 1 << ": ";
        cin >> members[i];
    }
}

// Function for lucky draw selection
void luckyDraw() {
    cout << "\nHow do you want to conduct the lucky draw?\n";
    cout << "1. All at once\n";
    cout << "2. One per month\n";
    cout << "Enter your choice (1 or 2): ";
    cin >> luckydraw;

    switch (luckydraw) {
        case 1:
        case 2:
            cout << "\nConducting Lucky Draw...\n";
            sleep_for(milliseconds(700));
            cout << "====================================\n";
            cout << "       LUCKY DRAW WINNERS      \n";
            cout << "====================================\n\n";
            break;
        default:
            cout << "Invalid choice! Please select 1 or 2.\n";
            return;
    }
}

// Function to announce winners
void announceWinners() {
    if (luckydraw != 1 && luckydraw != 2) {
        cout << "Invalid lucky draw choice. Cannot proceed.\n";
        return;
    }

    for (int i = 0; i < committees; i++) {
        int winner = rand() % members.size();
        cout << "Winner of Committee " << i + 1 << " is: **" 
             << members[winner] << "** (Month: " 
             << months[(indexmonths + i - 1) % 12] << ")\n";
    }
// Using sleep for suspense
    cout << "\nAnnouncing Prize Winners...\n";
    sleep_for(milliseconds(1000));
//Now it will announce winners
    cout << "\n====================================\n";
    cout << "    Announcing Prize Winners   \n";
    cout << "====================================\n\n";

    for (int i = 0; i < committees; i++) {
        int moneyWinner = rand() % members.size();
        cout << members[moneyWinner] << " has won the prize of 100,000 PKR" << endl;
    }
}

int main() {
    srand(time(0)); // Using this so that it will not repeat winners and committee
    //Calling all functions
    displayEnhancement();
    getCommitteeInformation();
    luckyDraw();
    announceWinners();

    cout << "\n====================================\n";
    cout << "   Thank you for using the system!  \n";
    cout << "====================================\n";
    //Using this for exe. files because exe. file won't work without this
    cout << "\nPress Enter to exit...";
    cin.ignore();
    cin.get();
    
    return 0;
}
