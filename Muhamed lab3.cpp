#include <iostream>
#include <string>

using namespace std;

// Function prototypes
void dispStatus(int);//active cases as an input then display which zone 
void getInput(string &, int &, int &, int &, int &);//f total cases, new cases, total death, and total recovered
void dispOutput(string, int); // call function dipStatus to display the active cases and zones 
double calcAverage(int, double); //calculate the average number of active cases per state. 

int main() {
    string state;
    int totalCases, newCases, totalDeath, totalRecovered, activeCases, totalActiveCases, states;
    double average;

    while (true) { // infinite loop to make the user enter a valid state (input)
        cout << "Enter a state name or press ENTER to exit: ";
        getline(cin, state);

        if (state.empty()) {//if the user pressed ENTER without typing anything 
            break; // the break statement is executed, which exits the loop
        }

        getInput(state, totalCases, newCases, totalDeath, totalRecovered);

        activeCases = totalCases + newCases - totalDeath - totalRecovered;
        dispOutput(state, activeCases);

        totalActiveCases += activeCases;
        states++;
    }

    if (states > 0) { // If states is greater than zero the code within the if block executes else its skipped
        average = calcAverage(states, totalActiveCases);
        cout << "\nAverage number of active cases per state: " << average << endl;
    }

    return 0;
}

void dispStatus(int activeCases) { //  will take an integer "activeCases" as a parameter and wont return any value 
    if (activeCases > 40) {
        cout << "Red ZONE" << endl; 
    } else if (activeCases >= 21 && activeCases <= 40) {
        cout << "Orange ZONE" << endl;
    } else if (activeCases >= 1 && activeCases <= 20) {
        cout << "Yellow ZONE" << endl;
    } else {
        cout << "Green ZONE" << endl;
    }
}

void getInput(string &state, int &totalCases, int &newCases, int &totalDeath, int &totalRecovered) {
    cout << "Enter the total number of cases for " << state << ": ";
    cin >> totalCases;
    cout << "Enter the number of new cases for " << state << ": ";
    cin >> newCases;
    cout << "Enter the total number of deaths for " << state << ": ";
    cin >> totalDeath;
    cout << "Enter the total number of recoveries for " << state << ": ";
    cin >> totalRecovered;
}

void dispOutput(string state, int activeCases) {
    cout << "For " << state << ":\n";
    cout << "Number of active cases: " << activeCases << endl;
    dispStatus(activeCases);
}

double calcAverage(int states, double totalActiveCases) {
    return totalActiveCases / states;
}