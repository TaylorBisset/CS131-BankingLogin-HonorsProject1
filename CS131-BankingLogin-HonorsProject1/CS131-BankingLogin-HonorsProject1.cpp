#include <iostream>
#include <string>
#include <cctype>

using namespace std;

// Function prototypes
int displayStartMenu();
void login();
void createAccount();
string getValidUsername();

int main()
{
    cout << "Welcome to your eBank!\n\n";

    // Start Menu. Login or Create Account
    int startMenu = displayStartMenu();
    switch (startMenu)
    {
    case 1: 
        login();
        break;
    case 2: 
        // createAccount();
        break;
    default: 
        cout << "\nInvalid option. Please try again.\n";
        break;
    }
    return 0;
}

/* - - - - - FUNCTIONS - - - - - */

// Start Menu function
int displayStartMenu()
{
    int startMenu = 0;
    while (startMenu != 1 && startMenu != 2)
    {
        cout << "\nWhat would you like to do?\n";
        cout << "1 = Login\n2 = Create Account\n";
        cin >> startMenu;
        cin.ignore();
    }
    return startMenu;
}

// Login function
void login()
{
    cout << "\nFill in your login information below\n";
    // Login logic goes here
}

void createAccount()
{
    cout << "\nLet's create a new account for you!\n";
    string username = getValidUsername();
    string password = getValidPassword();
}

string getValidUsername()
{
    string username;
    bool isUsernameValid = false;

    cout << endl;
    cout << "Please create a new username.\n";
    cout << "Your username must be at least 6 characters long,\n";
    cout << "and must only contain letters and numbers.\n";

    while (!isUsernameValid)                        // initiate while loop to check for a valid username input 
    {
        cout << "\n\tEnter your username here: ";
        getline(cin, username);                     // user inputs their desired username 

        if (username.size() > 5)
        {
            isUsernameValid = true;                 // set true, until proven otherwise 
            for (char c : username)                 // range-based for loop 
            {
                if (!isalnum(c) || isspace(c))      // checks if each character is NOT alphanumeric or is a space 
                {
                    isUsernameValid = false;
                    cout << "\nInvalid username. Please only use letters and numbers.\n";
                    break;
                }
            }
        }
        else if (username.size() < 6)
        {
            cout << "\nInvalid username. Please ensure there are at least 6 characters.\n";
        }
    }

    if (isUsernameValid == true)
    {
        cout << "\n\tValid username.\n\tYour username is: " << username << endl;
    }
    return username;
}

string getValidPassword()
{

}