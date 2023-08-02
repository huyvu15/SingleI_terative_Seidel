#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

void clearScreen()
{
    system("cls");
}

void setTextColor(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void printHighlightedText(const string& text)
{
    setTextColor(31); // M�u xanh da tr?i
    cout << "????????????????????" << endl;
    cout << "?    " << text << "     ?" << endl;
    cout << "????????????????????" << endl;
    setTextColor(15); // M�u tr?ng
}

void printNormalText(const string& text)
{
    cout << "  " << text << endl;
}

void setupMenu()
{
    int choice = 0;
    int maxChoice = 6;
    char key;

    while (true)
    {
        clearScreen();

        cout << "+--------------------+" << endl;
        cout << "�       MENU         �" << endl;
        cout << "+--------------------+" << endl;

        for (int i = 0; i <= maxChoice; i++)
        {
            if (i == choice)
            {
                printHighlightedText(  ". Option "  );
            }
            else
            {
                printNormalText(   ". Option "   );
            }
        }

        key = getch();

        switch (key)
        {
            case 'w':
            case 'W':
            case 72: // Arrow Up
                if (choice > 0)
                {
                    choice--;
                }
                break;
            case 's':
            case 'S':
            case 80: // Arrow Down
                if (choice < maxChoice)
                {
                    choice++;
                }
                break;
            case '\r':
                clearScreen();
                if (choice == maxChoice)
                {
                    cout << "Thoat chuong trinh." << endl;
                    exit(0);
                }
                else
                {
                    cout << "Ban da lua chon: " << choice + 1 << endl;
                    // Th?c hi?n ch?c nang tuong ?ng v?i l?a ch?n
                    cout << "Nhan phim bat ki de tiep tuc...";
                    getch();
                }
                break;
        }
    }
}

int main()
{
    setupMenu();
    return 0;
}

