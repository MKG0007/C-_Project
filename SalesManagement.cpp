#include <iostream>
#include <fstream>
#include <cstring>
#include <climits>

#define MAX_FLAVORS 10

using namespace std;

struct Flavor {
    char name[20];
    int quantity;
};

Flavor flavorList[MAX_FLAVORS];
int totalFlavors = 0;
int index;

bool login() {
    bool isAuthenticated = false;
    char inputUsername[100], inputPassword[100];
    const char validUsers[3][100] = {"A", "B", "C"};

    cout << "Welcome To AI Ice-Cream Parlor\n\n";

    cout << "Enter username: ";
    cin >> inputUsername;

    cout << "Enter password: ";
    cin >> inputPassword;

    for (index = 0; index < 3; index++) {
        if (strcmp(validUsers[index], inputUsername) == 0 && strcmp(inputPassword, "pass123") == 0) {
            isAuthenticated = true;
            break;
        }
    }

    if (isAuthenticated) {
        cout << "\n------------------------------------------\n";
        cout << "            || ACCESS GRANTED ||          \n";
        cout << "------------------------------------------\n\n";
        cout << "Welcome " << inputUsername << "\n";
    } else {
        cout << "\nUNAUTHORIZED ACCESS. Please enter valid credentials.\n";
    }

    return isAuthenticated;
}

void addFlavor(char* flavorName, int quantity) {
    if (totalFlavors == MAX_FLAVORS) {
        cout << "\nCannot add more flavors. Limit reached.\n";
        return;
    }

    for (index = 0; index < totalFlavors; index++) {
        if (strcmp(flavorList[index].name, flavorName) == 0) {
            cout << "\n" << flavorName << " flavor already exists.\n";
            return;
        }
    }

    Flavor newFlavor;
    strcpy(newFlavor.name, flavorName);
    newFlavor.quantity = quantity;
    flavorList[totalFlavors] = newFlavor;
    totalFlavors++;

    cout << "\n" << flavorName << " flavor added successfully.\n";

    ofstream file("flavors.txt", ios::app);
    if (file.is_open()) {
        file << flavorName << "-" << quantity << "\n";
        file.close();
    } else {
        cout << "Error writing to file.\n";
    }
}

void removeFlavor(char* flavorName) {
    int j;
    for (index = 0; index < totalFlavors; index++) {
        if (strcmp(flavorList[index].name, flavorName) == 0) {
            for (j = index; j < totalFlavors - 1; j++) {
                flavorList[j] = flavorList[j + 1];
            }
            totalFlavors--;
            cout << "\n" << flavorName << " flavor removed successfully.\n";
            return;
        }
    }
    cout << "\n" << flavorName << " flavor not found.\n";
}

void displayFlavors() {
    cout << "\nAvailable Flavors:\n";
    for (index = 0; index < totalFlavors; index++) {
        cout << flavorList[index].name << " - " << flavorList[index].quantity << "\n";
    }
}

int main() {
    if (!login()) return 0;

    int userChoice, quantity;
    char flavorName[20];

    do {
        char choice;
        cout << "\nPlease choose an option:\n";
        cout << "1. Add Flavor\n";
        cout << "2. Remove Flavor\n";
        cout << "3. View Available Flavors\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        userChoice = choice-'0';


        switch (userChoice) {
            case 1:
                cout << "Enter flavor name: ";
                cin >> flavorName;
                cout << "Enter quantity: ";
                cin >> quantity;
                addFlavor(flavorName, quantity);
                break;

            case 2:
                cout << "Enter flavor name: ";
                cin >> flavorName;
                removeFlavor(flavorName);
                break;

            case 3:
                displayFlavors();
                break;

            case 4:
                cout << "\nExit Successful. Thank you!\n";
                break;

            default:
                cout << "\nInvalid choice. Please try again.\n";
                cin.clear();
                break;
        }

    } while (userChoice != 4);

    return 0;
}
