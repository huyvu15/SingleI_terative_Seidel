#include <iostream>
#include <conio.h>
#include <windows.h>
#include <math.h>
#include <fstream>

using namespace std;

void clearScreen()
{
    system("cls");
}

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void setTextColor(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void printHighlightedOption(const string& text)
{
    setTextColor(11);
    cout << "  " << text << "  ";
    setTextColor(15);
}

void printNormalOption(const string& text) {
    cout << "  " << text << "  ";
}

void setupSubMenu()
{
    int choice = 0;
    int maxChoice = 2;
    char key;

    while (true) {
        clearScreen();

        cout << "              =======================================================================================        " << endl;
        cout << "              | Menu Con                                                                             |          " << endl;
        cout << "              =======================================================================================        " << endl;

        for (int i = 0; i <= maxChoice; i++) {
            gotoxy(0, i + 3);
            if (i == choice) {
                printHighlightedOption(">>");
                switch (i) {
                case 0:
                    cout << "        |";
                    printHighlightedOption("   1. Chuc nang 1");
                    cout << "                                                                                     |";
                    break;
                case 1:
                    cout << "        |";
                    printHighlightedOption("   2. Chuc nang 2");
                    cout << "                                                                                     |";
                    break;
                case 2:
                    cout << "        |";
                    printHighlightedOption("   Thoat");
                    cout << "                                                                                     |";
                    break;
                }
            }
            else {
                printNormalOption("  ");
                switch (i) {
                case 0:
                    cout << "        |";
                    printNormalOption("   1. Chuc nang 1");
                    cout << "                                                                                     |";
                    break;
                case 1:
                    cout << "        |";
                    printNormalOption("   2. Chuc nang 2");
                    cout << "                                                                                     |";
                    break;
                case 2:
                    cout << "        |";
                    printNormalOption("   Thoat");
                    cout << "                                                                                     |";
                    break;
                }
            }
        }
        cout << endl;
        cout << "              =======================================================================================        " << endl;

        key = getch();

        switch (key) {
        case 'w':
        case 'W':
        case 72:
            if (choice > 0)
            {
                choice--;
                gotoxy(0, choice + 4);
                printHighlightedOption(">>");
                gotoxy(0, choice + 5);
                printNormalOption("  ");
            }
            break;
        case 's':
        case 'S':
        case 80:
            if (choice < maxChoice)
            {
                choice++;
                gotoxy(0, choice + 2);
                printHighlightedOption(">>");
                gotoxy(0, choice + 1);
                printNormalOption("  ");
            }
            break;
        case '\r':
            clearScreen();
            if (choice == maxChoice) {
                return; // Thoát menu con và quay lại menu ban đầu
            }
            else {
                cout << "Ban da lua chon: ";
                cout << endl;
                switch (choice) {
                case 0:
                    setTextColor(10);
                    // Thực hiện chức năng 1
                    break;
                case 1:
                    setTextColor(12);
                    // Thực hiện chức năng 2
                    break;
                }
            }

            setTextColor(15);
            cout << endl;
            cout << "Nhan phim bat ki de tiep tuc...";
            getch();
            break;
        }
    }
}

void setupMenu()
{
    int choice = 0;
    int maxChoice = 6;
    char key;
    // bool inSubMenu = false; // Biến để kiểm tra xem có đang ở trong menu con hay không

    while (true) {
        clearScreen();

        cout << "              =======================================================================================        " << endl;
        cout << "              |  GIAI GAN DUNG HE PHUONG TRINH AX = b BANG PHUONG PHAP LAP DON, LAP SEIDELDAY CUNG  |          " << endl;
        cout << "              =======================================================================================        " << endl;

        for (int i = 0; i <= maxChoice; i++) {
            gotoxy(0, i + 3);
            if (i == choice) {
                printHighlightedOption(">>");
                switch (i) {
                case 0:
                    cout << "        |";
                    printHighlightedOption("   1. Nhap vao A, b theo khuon dang cua ma tran");
                    cout << "                                            |";
                    break;
                case 1:
                    cout << "        |";
                    printHighlightedOption("   2. Kiem tra tinh cheo troi cua ma tran A va su hoi tu cua phuong phap");
                    cout << "         |";
                    break;
                case 2:
                    cout << "        |";
                    printHighlightedOption("   3. Tinh chuan cua ma tran A doi voi he da cho.");
                    cout << "                                                  |";
                    break;
                case 3:
                    cout << "        |";
                    printHighlightedOption("   4. Tinh nghiem gan dung voi so lan lap k cho truoc, danh gia sai so.");
                    cout << "                 |";
                    break;
                case 4:
                    cout << "        |";
                    printHighlightedOption("   5. Tinh nghiem gan dung voi sai so e cho truoc.");
                    cout << "                                              |";
                    break;
                case 5:
                    cout << "        |";
                    printHighlightedOption("   6. Tinh nghiem gan dung X(k) thoa man: ||X(k)-X(k-1)|| <= e cho truoc");
                    cout << "         |";
                    break;
                case 6:
                    cout << "        |";
                    printHighlightedOption("   Thoat");
                    cout << "                                                                                     |";
                    break;
                }
            }
            else {
                printNormalOption("  ");
                switch (i) {
                case 0:
                    cout << "        |";
                    printNormalOption("   1. Nhap vao A, b theo khuon dang cua ma tran");
                    cout << "                                            |";
                    break;
                case 1:
                    cout << "        |";
                    printNormalOption("   2. Kiem tra tinh cheo troi cua ma tran A va su hoi tu cua phuong phap");
                    cout << "         |";
                    break;
                case 2:
                    cout << "        |";
                    printNormalOption("   3. Tinh chuan cua ma tran A doi voi he da cho.");
                    cout << "                                                  |";
                    break;
                case 3:
                    cout << "        |";
                    printNormalOption("   4. Tinh nghiem gan dung voi so lan lap k cho truoc, danh gia sai so.");
                    cout << "                 |";
                    break;
                case 4:
                    cout << "        |";
                    printNormalOption("   5. Tinh nghiem gan dung voi sai so e cho truoc.");
                    cout << "                                              |";
                    break;
                case 5:
                    cout << "        |";
                    printNormalOption("   6. Tinh nghiem gan dung X(k) thoa man: ||X(k)-X(k-1)|| <= e cho truoc");
                    cout << "         |";
                    break;
                case 6:
                    cout << "        |";
                    printNormalOption("   Thoat");
                    cout << "                                                                                     |";
                    break;
                }
            }
        }
        cout << endl;
        cout << "              =======================================================================================        " << endl;

        key = getch();

        switch (key) {
        case 'w':
        case 'W':
        case 72:
            if ( choice > 0)
            {
                choice--;
                gotoxy(0, choice + 4);
                printHighlightedOption(">>");
                gotoxy(0, choice + 5);
                printNormalOption("  ");
            }
            
            // else if (inSubMenu)
            // {
            //     setupSubMenu();
            //     inSubMenu = false;
            // }
            break;
        case 's':
        case 'S':
        case 80:
            if (choice < maxChoice)
            {
                choice++;
                gotoxy(0, choice + 2);
                printHighlightedOption(">>");
                gotoxy(0, choice + 1);
                printNormalOption("  ");
            }
            // else if (inSubMenu)
            // {
            //     setupSubMenu();
            //     inSubMenu = false;
            // }
            break;
        case '\r':
            clearScreen();
            if (choice == maxChoice) {
                cout << "Thoat chuong trinh." << endl;
                exit(0);
            }
            else {
                cout << "Ban da lua chon: ";
                cout << endl;
                switch (choice) {
                case 0:
                    setTextColor(10);
                    setupSubMenu();
                    // inSubMenu = true; // Đã chuyển sang menu con
                    break;
                case 1:
                    setTextColor(12);
                    // Thực hiện chức năng 2
                    break;
                case 2:
                    setTextColor(14);
                    // Thực hiện chức năng 3
                    break;
                case 3:
                    setTextColor(9);
                    // Thực hiện chức năng 4
                    break;
                case 4:
                    setTextColor(13);
                    // Thực hiện chức năng 5
                    break;
                case 5:
                    setTextColor(11);
                    // Thực hiện chức năng 6
                    break;
                }
            }

            setTextColor(15);
            cout << endl;
            cout << "Nhan phim bat ki de tiep tuc...";
            getch();
            break;
        }
    }
}

int main()
{
    setupMenu();
    return 0;
}
