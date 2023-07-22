#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main()
{
    cout << "Welcome to your eBank!\n\n";

    // Start Menu options. Login or Create Account
    int startMenu = 0;
    while (startMenu != 1 && startMenu != 2)
    {
        cout << "\nWhat would you like to do?\n";
        cout << "1 = Login\n2 = Create Account\n";
        cin >> startMenu;
        if (startMenu == 1)
        {
            cout << "\nFill in your login information below\n";
        }
        else if (startMenu == 2)
        {
            cout << "\nLet's create a new account for you!\n";
        }
    }

    // Create Account 
    if (startMenu == 2)
    {
        // Create username
        cout << endl;
        cout << "Please create a new username.\n";
        cout << "Your username must be at least 6 characters long, \n";
        cout << "and must only contain letters and numbers.\n\n";
         
        string username;
        bool isUsernameValid = false;

        while (!isUsernameValid)                        // initiate while loop to check for a valid username input 
        {
            cout << "\tEnter your username here: ";
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
            else
            {
                cout << "\nInvalid username. Please ensure there are at least 6 characters.\n";
            }
        }

        if (isUsernameValid == true)
        {
            cout << "\n\tValid username.\n\tYour username is: " << username << endl;
        }

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
            cout << "\tEnter your password here: ";
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
