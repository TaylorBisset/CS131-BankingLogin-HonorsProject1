#include <iostream>
#include <string>

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
        cout << endl;
        cout << "Please create a new username\n";
        cout << "Your username must be at least 6 characters long, \n";
        cout << "and must only contain letters and numbers.\n";
        
        string username;
        bool usernameValid = false;
        
        while (!usernameValid)
        {
            getline(cin, username);
            if (username.size() > 5)
            {
                for (int i = 0; i < username.size(); i++)
                {
                    if (!isdigit(username.at(i)) && !isalpha(username.at(i)))
                    {
                        cout << "Invalid username. Please try another.\n";
                    }
                    else
                    {
                        usernameValid = true;
                    }
                }
            }
            else
            {
                cout << "Invalid username.";
            }
        }
    }
}
