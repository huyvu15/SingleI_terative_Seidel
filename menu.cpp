#include <iostream>
#include <conio.h>
#include <windows.h>
#include <math.h>

using namespace std;

void clearScreen() {
    system("cls");
}

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int whereX() {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
        return csbi.dwCursorPosition.X;
    return -1;
}

int whereY() {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
        return csbi.dwCursorPosition.Y;
    return -1;
}

void setTextColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void printHighlightedOption(const string& text) {
    setTextColor(11); // màu xanh lá cây
    cout << "  " << text << "  ";
    setTextColor(15); // màu tr?ng
}

void printNormalOption(const string& text) {
    cout << "  " << text << "  ";
}

void printBorder(int width, int height) {
    setTextColor(10); // màu tr?ng
    for (int i = 0; i <= 120; i++) {
        gotoxy(i, 0); printf("%c", 205);
        gotoxy(i, 29); printf("%c", 205);
    }
    gotoxy(18, 0); printf(" BAI TAP LON KTLT CHU DE 5 ");
    gotoxy(3, 2); printf(" GIAI GAN DUNG HE PHUONG TRINH AX = b BANG PHUONG PHAP LAP DON, LAP SEIDELDAY CUNG ");

    gotoxy(0, 0); printf("%c", 201);
    gotoxy(70, 0); printf("%c", 187);

    for (int i = 0; i <= 14; i++) {
        gotoxy(0, 14 - i); printf("%c", 186);
        gotoxy(0, 14 + i); printf("%c", 186);
        gotoxy(, 14 - i); printf("%c", 186);
        gotoxy(70, 14 + i); printf("%c", 186);
    }
    gotoxy(0, 0); printf("%c", 201);
    gotoxy(70, 0); printf("%c", 187);
    gotoxy(0, 29); printf("%c", 200);
    gotoxy(70, 29); printf("%c", 188);

    gotoxy(6, 21); printf("$$$     $$$  $$$$$$$$$$$ $$$     $$$      $$$$$$$$$$\n");
    gotoxy(6, 22); printf("$$$     $$$  $$$$        $$$     $$$      $$      $$\n");
    gotoxy(6, 23); printf("$$$$$$$$$$$  $$$$$$$$$$$ $$$     $$$      $$      $$\n");
    gotoxy(6, 24); printf("$$$$$$$$$$$  $$$$$$$$$$$ $$$     $$$      $$      $$\n");
    gotoxy(6, 25); printf("$$$     $$$  $$$$        $$$     $$$      $$      $$\n");
    gotoxy(6, 26); printf("$$$     $$$  $$$$$$$$$$$ $$$$$$$ $$$$$$$  $$$$$$$$$$\n");
}

void setupMenu() {
    int choice = 0;
    int maxChoice = 6;
    char key;

    while (true) {
        clearScreen();

        int width = 60;
        int height = 30;
        printBorder(width, height);

        gotoxy(width / 2 - 1, 1);
        cout << "MENU";

        gotoxy(width / 2 - 1, 2);
        cout << "====";

        gotoxy(width / 2 - 4, 3);
        cout << "CHUONG TRINH " << choice + 1;

        for (int i = 0; i <= maxChoice; i++) {
            gotoxy(2, i + 5);
            if (i == choice) {
                printHighlightedOption("->");
                switch (i) {
                    case 0:
                        printHighlightedOption("1. Nhap vao A, b theo khuon dang cua ma tran");
                        break;
                    case 1:
                        printHighlightedOption("2. Kiem tra tinh cheo troi cua ma tran A va su hoi tu cua phuong phap");
                        break;
                    case 2:
                        printHighlightedOption("3. Tinh chuan cua ma tran A doi voi he da cho.");
                        break;
                    case 3:
                        printHighlightedOption("4. Tinh nghiem gan dung voi so lan lap k cho truoc va danh gia sai so.");
                        break;
                    case 4:
                        printHighlightedOption("5. Tinh nghiem gan dung voi sai so e cho truoc.");
                        break;
                    case 5:
                        printHighlightedOption("6. Tinh nghiem gan dung X(k) thoa man: ||X(k)-X(k-1)|| <= e cho truoc");
                        break;
                    case 6:
                        printHighlightedOption("Thoat");
                        break;
                }
            }
            else {
                printNormalOption("  ");
                switch (i) {
                    case 0:
                        printNormalOption("  1. Nhap vao A, b theo khuon dang cua ma tran");
                        break;
                    case 1:
                        printNormalOption("  2. Kiem tra tinh cheo troi cua ma tran A va su hoi tu cua phuong phap");
                        break;
                    case 2:
                        printNormalOption("  3. Tinh chuan cua ma tran A doi voi he da cho.");
                        break;
                    case 3:
                        printNormalOption("  4. Tinh nghiem gan dung voi so lan lap k cho truoc va danh gia sai so.");
                        break;
                    case 4:
                        printNormalOption("  5. Tinh nghiem gan dung voi sai so e cho truoc.");
                        break;
                    case 5:
                        printNormalOption("  6. Tinh nghiem gan dung X(k) thoa man: ||X(k)-X(k-1)|| <= e cho truoc");
                        break;
                    case 6:
                        printNormalOption("  Thoat");
                        break;
                }
            }
        }

        key = _getch();
        if (key == 13) { // Enter
            if (choice == maxChoice) {
                break;
            }
            else {
                // X? lý l?a ch?n
                // ...
            }
        }
        else if (key == 72) { // Up arrow
            choice--;
            if (choice < 0) {
                choice = maxChoice;
            }
        }
        else if (key == 80) { // Down arrow
            choice++;
            if (choice > maxChoice) {
                choice = 0;
            }
        }
    }
}

int main() {
    setupMenu();
    return 0;
}

