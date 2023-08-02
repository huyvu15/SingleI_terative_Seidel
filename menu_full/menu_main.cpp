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

void printNormalOption(const string& text)
{
    cout << "  " << text << "  ";
}

///////////////////////////////////////////

void NhapMaTran(double a[100][100], int dong, int cot)
{
    for (int i = 0; i < dong; i++)
    {
        for (int j = 0; j < cot; j++)
        {
            cin >> a[i][j];
        }
    }
}

void XuatMaTran(double a[100][100], int dong, int cot, ofstream& outputFile)
{
    for (int i = 0; i < dong; i++)
    {
        for (int j = 0; j < cot; j++)
        {
            outputFile << a[i][j] << " ";
            cout << a[i][j] << " ";
        }
        outputFile << endl;
        cout << endl;
    }
}

void readfromFile(const string& filename, int* n, double A[100][100], double B[100][100])
{
    ifstream file(filename.c_str());
    if (file.is_open())
    {
        file >> *n;

        // Đọc ma trận nxn
        for (int i = 0; i < *n; i++)
        {
            for (int j = 0; j < *n; j++)
            {
                file >> A[i][j];
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
        // Đọc ma trận nx1
        for (int i = 0; i < *n; i++)
        {
            file >> B[i][0];
            cout << B[i][0] << endl;
        }

        file.close();
    }
    else
    {
        cout << "Khong the mo tep!" << endl;
    }
}

/////////////////////////////////////

bool cheoTroiHang(double a[100][100])
{
    int n = sizeof(a);
    double sum_diag = 0;
    double sum_row = 0;
    for (int i = 0; i < n; i++)
    {
        sum_diag += fabs(a[i][i]);
        sum_row = 0;
        for (int j = 0; j < n; j++)
        {
            if (j != i)
            {
                sum_row += fabs(a[i][j]);
            }
        }
        if (sum_row >= sum_diag)
        {
            return false; // ma trận không chéo trội hàng
        }
    }
    return true; // ma trận chéo trội hàng
}

bool cheoTroiCot(double a[100][100])
{
    int n = sizeof(a);
    double sum_diag = 0;
    double sum_col = 0;
    for (int j = 0; j < n; j++)
    {
        sum_diag += fabs(a[j][j]);
        sum_col = 0;
        for (int i = 0; i < n; i++)
        {
            if (i != j)
            {
                sum_col += fabs(a[i][j]);
            }
        }
        if (sum_col >= sum_diag)
        {
            return false; // ma trận không chéo trội cột
        }
    }
    return true; // ma trận chéo trội cột
}
//////////////////////////////////////////
// matrix[hang][cot]
double chuanHangVecto(double b[100][100], int size)
{
    double X_inf = 0.0;
    for (int i = 0; i < size; i++)
    {
        X_inf = max(X_inf, fabs(b[i][0]));
    }
    return X_inf;
}

double chuanCotVecto(double b[100][100], int size)
{
    double X_1 = 0.0;
    for (int i = 0; i < size; i++)
    {
        X_1 = X_1 + fabs(b[i][0]);
    }
    return X_1;
}

// sửa lại đoạn code chuanHang
double chuanHang(double A[100][100], int size)
{
    double maxSum = 0.0;

    for (int i = 0; i < size; i++)
    {
        double rowSum = 0.0;

        for (int j = 0; j < size; j++)
        {
            rowSum += fabs(A[i][j]);
        }

        if (rowSum > maxSum)
        {
            maxSum = rowSum;
        }
    }
    return maxSum;
}

double chuanCot(double A[100][100], int size)
{
    double maxSum = 0.0; // Giá trị tối đa của tổng giá trị tuyệt đối trong các hàng

    for (int i = 0; i < size; i++)
    {
        double colSum = 0.0; // Tổng giá trị tuyệt đối trong hàng i

        for (int j = 0; j < size; j++)
        {
            colSum += fabs(A[j][i]);
        }

        if (colSum > maxSum)
        {
            maxSum = colSum;
        }
    }
    return maxSum;
}

////////////////////////////////
double congMatrix(double A[100][100], double B[100][100], double C[100][100], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            C[i][j] = B[i][j] + A[i][j];
        }
    }
    return C[100][100];
}

double nhanMatrix(double A[100][100], double B[100][100], double C[100][100], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < sizeof(B); j++)
        {
            C[i][j] = 0;
            for (int k = 0; k < size; k++)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return C[100][100];
}

////////////////////////////////////////////////////////////////

double timLamda(double a[100][100], double c[100][100], int size) // thực chất là tìm ma trận alpha || Q || < 1
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (i == j)
            {
                c[i][j] = 0;
            }
            else
            {
                c[i][j] = -a[i][j] / a[i][i];
            }
        }
    }
}

double timvecto_d(double a[100][100], double b[100][100], double c[100][100])
{
    for (int i = 0; i < sizeof(b); i++)
    {
        for (int j = 0; j < sizeof(b); j++)
        {
            c[i][j] = b[i][j] / a[i][i];
        }
    }
    return c[100][100];
}
////

void copy(double a[100][100], double b[100][100], int size)
{
    /*
    copy ma tran a vao b
    */
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            b[i][j] = a[i][j];
        }
    }
}

void chucnang1(ofstream& outputFile, double A[100][100], double b[100][100], int size)
{
    int choice = 0;
    int maxChoice = 2;
    char key;

    while (true)
    {
        clearScreen();

        cout << "              =======================================================================================        " << endl;
        cout << "              | Menu Con                                                                             |          " << endl;
        cout << "              =======================================================================================        " << endl;

        for (int i = 0; i <= maxChoice; i++)
        {
            gotoxy(0, i + 3);
            if (i == choice)
            {
                printHighlightedOption(">>");
                switch (i)
                {
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
                    printHighlightedOption("   Quay lai Menu Ban dau");
                    cout << "                                                                             |";
                    break;
                }
            }
            else
            {
                printNormalOption("  ");
                switch (i)
                {
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
                    printNormalOption("   Quay lai Menu Ban dau");
                    cout << "                                                                             |";
                    break;
                }
            }
        }
        cout << endl;
        cout << "              =======================================================================================        " << endl;

        key = getch();

        switch (key)
        {
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
            if (choice == maxChoice)
            {
                return; // Thoát menu con và quay lại menu ban đầu
            }
            else
            {
                cout << "Ban da lua chon: ";
                cout << endl;
                outputFile << "Giai HPT tuyen tinh AX = b bang lap don, lap Seidel" << endl;
                switch (choice)
                {
                case 0:
                    setTextColor(10);
                    cout << "Nhap tu file" << endl;
                    readfromFile("input.txt", &size, A, b); // Thay đổi "choice" thành "choices"
                    break;
                case 1:
                    setTextColor(12);
                    cout << "Nhap kich thuoc ma tran: ";
                    outputFile << "Nhap kich thuoc ma tran: ";
                    cin >> size;
                    outputFile << size << endl;
                    cout << "Nhap ma tran A:" << endl;
                    outputFile << "Nhap ma tran A:" << endl;

                    NhapMaTran(A, size, size);

                    cout << "Ma tran A:" << endl;
                    XuatMaTran(A, size, size, outputFile);

                    cout << "---------------------" << endl;
                    outputFile << "---------------------" << endl;

                    cout << "Nhap vector b:" << endl;
                    outputFile << "Nhap vector b:" << endl;
                    NhapMaTran(b, size, 1);
                    cout << "Vector b:" << endl;
                    XuatMaTran(b, size, 1, outputFile);

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

void setupMenu(ofstream& outputFile)
{
    int choice = 0;
    int maxChoice = 6;
    char key;

    while (true)
    {
        clearScreen();

        cout << "              =======================================================================================        " << endl;
        cout << "              |  GIAI GAN DUNG HE PHUONG TRINH AX = b BANG PHUONG PHAP LAP DON, LAP SEIDELDAY CUNG  |          " << endl;
        cout << "              =======================================================================================        " << endl;

        for (int i = 0; i <= maxChoice; i++)
        {
            gotoxy(0, i + 3);
            if (i == choice)
            {
                printHighlightedOption(">>");
                switch (i)
                {
                case 0:
                    cout << "        |";
                    printHighlightedOption("   1. Nhap vao A, b theo khuon dang cua ma tran");
                    cout << "	                   	    |";
                    break;
                case 1:
                    cout << "        |";
                    printHighlightedOption("   2. Kiem tra tinh cheo troi cua ma tran A va su hoi tu cua phuong phap");
                    cout << "         |";
                    break;
                case 2:
                    cout << "        |";
                    printHighlightedOption("   3. Tinh chuan cua ma tran A doi voi he da cho.");
                    cout << "				    |";
                    break;
                case 3:
                    cout << "        |";
                    printHighlightedOption("   4. Tinh nghiem gan dung voi so lan lap k cho truoc, danh gia sai so.");
                    cout << "	    |";
                    break;
                case 4:
                    cout << "        |";
                    printHighlightedOption("   5. Tinh nghiem gan dung voi sai so e cho truoc.");
                    cout << "			            |";
                    break;
                case 5:
                    cout << "        |";
                    printHighlightedOption("   6. Tinh nghiem gan dung X(k) thoa man: ||X(k)-X(k-1)|| <= e cho truoc");
                    cout << "         |";
                    break;
                case 6:
                    cout << "        |";
                    printHighlightedOption("   Thoat");
                    cout << "                                                                         |";
                    break;
                }
            }
            else
            {
                printNormalOption("  ");
                switch (i)
                {
                case 0:
                    cout << "        |";
                    printNormalOption("   1. Nhap vao A, b theo khuon dang cua ma tran");
                    cout << "	                   	    |";
                    break;
                case 1:
                    cout << "        |";
                    printNormalOption("   2. Kiem tra tinh cheo troi cua ma tran A va su hoi tu cua phuong phap");
                    cout << "         |";
                    break;
                case 2:
                    cout << "        |";
                    printNormalOption("   3. Tinh chuan cua ma tran A doi voi he da cho.");
                    cout << "				    |";
                    break;
                case 3:
                    cout << "        |";
                    printNormalOption("   4. Tinh nghiem gan dung voi so lan lap k cho truoc, danh gia sai so.");
                    cout << "	    |";
                    break;
                case 4:
                    cout << "        |";
                    printNormalOption("   5. Tinh nghiem gan dung voi sai so e cho truoc.");
                    cout << "			            |";
                    break;
                case 5:
                    cout << "        |";
                    printNormalOption("   6. Tinh nghiem gan dung X(k) thoa man: ||X(k)-X(k-1)|| <= e cho truoc");
                    cout << "         |";
                    break;
                case 6:
                    cout << "        |";
                    printNormalOption("   Thoat");
                    cout << "                                                                         |";
                    break;
                }
            }
        }
        cout << endl;
        cout << "              =======================================================================================        " << endl;

        key = getch();

        switch (key)
        {
        case 'w':
        case 'W':
        case 72:
            if (choice > 0)
            {
                choice--;
            }
            break;
        case 's':
        case 'S':
        case 80:
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
                cout << "Ban da lua chon: ";
                cout << endl;
                switch (choice)
                {
                case 0:
                    setTextColor(10);
                    double A[100][100];
                    double b[100][100];
                    int size;
                    chucnang1(outputFile, A, b, size);
                    cout << "---------------------" << endl;
                    outputFile << "---------------------" << endl;

                    cout << "Ma tran B la:" << endl;
                    
                    outputFile << "Ma tran B la:" << endl;
                    double D[100][100];
                    timLamda(A, D, size);
                    XuatMaTran(D, size, size, outputFile);
                    double E[100][100];
                    cout << "vetor d la:" << endl;
                    outputFile << "vetor d la:" << endl;
                    timvecto_d(A, b, E);
                    XuatMaTran(E, size, 1, outputFile);
                    break;
                case 1:
                    setTextColor(12);
                    

                    break;
                case 2:
                    setTextColor(10);
                    break;
                case 3:
                    setTextColor(12);
                    

                    break;
                case 5:
                    setTextColor(12);
                    

                    break;
                case 6:
                    setTextColor(10);
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
    ofstream outputFile;
    outputFile.open("output.txt", ios::out | ios::trunc);

    if (outputFile.fail())
    {
        cout << "Khong the tao hoac mo file de ghi" << endl;
        return 0;
    }

    setupMenu(outputFile);

    outputFile.close();
    return 0;
}
