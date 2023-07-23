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
                    cout << "Invalid username. Please only use letters and numbers.\n";
                    break;
                }
            }
        }
        else if (username.size() < 6)
        {
            cout << "Invalid username. Please ensure there are at least 6 characters.\n";
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
    string password;
    bool isPasswordValid = false;

    cout << endl;
    cout << "Please create a password for your new account.\n";
    cout << "Your password must be at least 8 characters long, \n";
    cout << "and must contain at least:\n";
    cout << "2 letters, 2 numbers,\n2 standard special characters (e.g. !@#$%^&*()),\nand no spaces.\n\n";
    cout << "Remember to NEVER share your password with anyone.\n";

    while (!isPasswordValid)                        // initiate while loop to check for a valid password input 
    {
        cout << "\n\tEnter your password here: ";
        getline(cin, password);                     // user inputs their desired password 
        int alphaCount = 0;
        int digitCount = 0;
        int specialCount = 0;

        if (password.size() > 7)
        {
            isPasswordValid = true;                 // set true, until proven otherwise 
            for (char c : password)                 // range-based for loop 
            {
                if (isspace(c))                     // checks if password contains a space 
                {
                    isPasswordValid = false;
                    cout << "Invalid password. Please do not use spaces.\n";
                    break;
                }
                if (isalpha(c))                     // checks password for letters 
                {
                    alphaCount++;
                }
                if (isdigit(c))                     // checks password for numbers 
                {
                    digitCount++;
                }
                if (c == '!' || c == '@' || (c >= '#' && c <= '&') || (c >= '(' && c <= '*')) // checks for special characters 
                {
                    specialCount++;
                }
            }
        }
        else
        {
            cout << "Invalid password. Please ensure there are at least 8 characters.\n";
        }
        if (alphaCount < 2)
        {
            cout << "Invalid password. You must use at least 2 letters.\n";
            isPasswordValid = false;
        }
        if (digitCount < 2)
        {
            cout << "Invalid password. You must use at least 2 numbers.\n";
            isPasswordValid = false;
        }
        if (specialCount < 2)
        {
            cout << "Invalid password. You must use at least 2 standard special characaters (e.g. !@#$%^&*()).\n";
            isPasswordValid = false;
        }
    }

    if (isPasswordValid == true)
    {
        cout << "\n\tValid password.\n\tYour password is: " << password << endl;
    }
}