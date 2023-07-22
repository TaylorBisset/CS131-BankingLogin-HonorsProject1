#include <iostream>
#include <string>
#include <cctype>

using namespace std;

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

    // Create Account 
    if (startMenu == 2)
    {
        

        // Create password 
        cout << endl;
        cout << "Please create a password for your new account.\n";
        cout << "Your password must be at least 8 characters long, \n";
        cout << "and must contain at least:\n";
        cout << "2 letters, 2 numbers,\n2 standard special characters (e.g. !@#$%^&*()),\nand no spaces.\n\n";
        cout << "Remember to NEVER share your password with anyone.\n\n";

        string password;
        bool isPasswordValid = false;

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
                        cout << "\nInvalid password. Please do not use spaces.\n";
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
                    if (c == '!' || c == '@' ||(c >= '#' && c <= '&') || (c >= '(' && c <= '*')) // checks for special characters 
                    {
                        specialCount++;
                    }
                }
            }
            else
            {
                cout << "\nInvalid password. Please ensure there are at least 8 characters.\n";
            }
            if (alphaCount < 2)
            {
                cout << "\nInvalid password. You must use at least 2 letters.\n";
                isPasswordValid = false;
            }
            if (digitCount < 2)
            {
                cout << "\nInvalid password. You must use at least 2 numbers.\n";
                isPasswordValid = false;
            }
            if (specialCount < 2)
            {
                cout << "\nInvalid password. You must use at least 2 standard special characaters (e.g. !@#$%^&*()).\n";
                isPasswordValid = false;
            }
        }

        if (isPasswordValid == true)
        {
            cout << "\n\tValid password.\n\tYour password is: " << password << endl;
        }
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
    // get username using function
    // get password using function
}

string getValidUsername()
{
    string username;
    bool isUsernameValid = false;

    cout << endl;
    cout << "Please create a new username.\n";
    cout << "Your username must be at least 6 characters long,\n";
    cout << "and must only contain letters and numbers.\n\n";

}
