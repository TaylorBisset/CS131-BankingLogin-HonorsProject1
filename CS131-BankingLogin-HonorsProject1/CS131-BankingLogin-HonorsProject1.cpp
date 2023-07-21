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
    
}
