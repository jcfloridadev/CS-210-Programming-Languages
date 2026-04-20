/*
* CS-210 Project 1: Chada Tech Clock
* Developer: Justin Carlo Florida
*/

#include <iostream>
#include <string>
using namespace std;

string Format_12hr(int time_Hour, int time_Min, int time_Sec) {
    int displayHour;
    string ampm;

    if (time_Hour == 0) {
        displayHour = 12;
        ampm = "AM";
    }
    else if (time_Hour < 12) {
        displayHour = time_Hour;
        ampm = "AM";
    }
    else if (time_Hour == 12) {
        displayHour = 12;
        ampm = "PM";
    }
    else {
        displayHour = time_Hour - 12;
        ampm = "PM";
    }

    string hh = (displayHour < 10 ? "0" : "") + to_string(displayHour);
    string mm = (time_Min < 10 ? "0" : "") + to_string(time_Min);
    string ss = (time_Sec < 10 ? "0" : "") + to_string(time_Sec);

    return hh + ":" + mm + ":" + ss + " " + ampm;
}

string Format_24hr(int time_Hour, int time_Min, int time_Sec) {

    string hh = (time_Hour < 10 ? "0" : "") + to_string(time_Hour);
    string mm = (time_Min < 10 ? "0" : "") + to_string(time_Min);
    string ss = (time_Sec < 10 ? "0" : "") + to_string(time_Sec);

    return hh + ":" + mm + ":" + ss;
}

void DisplayTime(int time_Hour, int time_Min, int time_Sec) {

	string time12 = Format_12hr(time_Hour, time_Min, time_Sec); //calling format_12hr
	string time24 = Format_24hr(time_Hour, time_Min, time_Sec); //calling format_24hr

	cout << "\n12-Hour Clock: " << time12 << endl;
	cout << "24-Hour Clock: " << time24 << endl;

    //DisplayTime() done executing, going back to main()
}

void DisplayOption() {

    cout << "\n1 - Add One Hour" << endl;
    cout << "2 - Add One Minute" << endl;
    cout << "3 - Add One Second" << endl;
    cout << "4 - Exit Program" << endl;
    cout << "Choose an option: ";

    //DisplayOption() done executing, going back to main()

}

void AddHour(int& time_Hour) {

    time_Hour++;

    if (time_Hour > 23) {
        time_Hour = 0;
    }
}

void AddMin(int& time_Hour, int& time_Min) {
    time_Min++;

    if (time_Min > 59) {
        time_Min = 0;
        time_Hour++;

        if (time_Hour > 23) {
            time_Hour = 0;
        }
    }

}

void AddSec(int& time_Hour, int& time_Min, int& time_Sec) {
    time_Sec++;

    if (time_Sec > 59) {
        time_Sec = 0;
        time_Min++;
    }
    if (time_Min > 59) {
        time_Min = 0;
        time_Hour++;
    }
    if (time_Hour > 23) {
        time_Hour = 0;
    }
}

int main() {

    int time_Hour;
    int time_Min;
    int time_Sec;
    int optionAdd = 0;

    bool validTime = false; //using bool to keep looping until valid time inputted

    while (!validTime) {
        cout << "Enter hour: ";
        cin >> time_Hour;
        if (!cin) { //terminate program after non-integer input to avoid crashing.
            cout << "Invalid input. Please rerun the program." << endl;
            return 0;
        }

        cout << "Enter minute: ";
        cin >> time_Min;
        if (!cin) { //terminate program after non-integer input to avoid crashing.
            cout << "Invalid input. Please rerun the program." << endl;
            return 0;
        }

        cout << "Enter second: ";
        cin >> time_Sec;
        if (!cin) { //terminate program after non-integer input to avoid crashing.
            cout << "Invalid input. Please rerun the program." << endl;
            return 0;
        }

        if (time_Hour >= 0 && time_Hour <= 23 && time_Min >= 0 && time_Min <= 59 && time_Sec >= 0 && time_Sec <= 59) { //check validation

            validTime = true;
        }
        else {
            cout << "Invalid time-range entered: please try again." << endl;
        }
    }

    while (optionAdd != 4) { //keep on looping until option 4 is picked.

        DisplayTime(time_Hour, time_Min, time_Sec); //calling DisplayTime()
        DisplayOption(); //calling DisplayOption()
        cin >> optionAdd;

        //option #1
        if (optionAdd == 1) {
            AddHour(time_Hour); //calling AddHour()
        }

        //option #2
        else if (optionAdd == 2) {
            AddMin(time_Hour, time_Min); //calling AddMin()
        }
        //option #3
        else if (optionAdd == 3) {
            AddSec(time_Hour, time_Min, time_Sec); //calling AddSec()
        }
        //option #4
        else if (optionAdd == 4) {
            cout << "\n\n__________________________________\n\nProgram terminated.\n\nThank you for giving us your time!\n\nSincerely,\n\nChada Tech\nDeveloper: Justin Carlo Florida" << endl;
        }
        else {
            cout << "Invalid option. Try again: " << endl;
        }
    }

return 0;
  
}

