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

///////////////////////////////////////////

void NhapMaTran(double a[100][100], int dong, int cot)
{
    for (int i = 0; i < dong; i++)
    {
        for(int j = 0; j < cot; j++){
            // cout << "a[" << i << ", " << j << "] = ";
            cin >> a[i][j];
        }
    }
}

void XuatMaTran(double a[100][100], int dong, int cot, ofstream &outputFile)
{
    for (int i = 0; i < dong; i++)
    {
        for (int j = 0; j < cot; j++)
        {
            outputFile << a[i][j] << " ";
            cout<<a[i][j] << " ";
        }
        outputFile << endl;
        cout << endl;
    }
}


void readfromFile(const string& filename, int* n, double A[100][100],double B[100][100]) {
    ifstream file(filename.c_str()); 
    if (file.is_open()) {
        file >> *n;

        // Ð?c ma tr?n nxn
        for (int i = 0; i < *n; i++) {
            for (int j = 0; j < *n; j++) {
                file >> A[i][j];
                cout<<A[i][j] << " ";
            }
            cout<<endl;
        }
        // Ð?c ma tr?n nx1
        for (int i = 0; i < *n; i++) {
            file >> B[i][0];
            cout<<B[i][0]<<endl;
        }

        file.close();
    } else {
        cout << "Khong the mo tep!" << std::endl;
    }
}

/////////////////////////////////////

bool cheoTroiHang(double a[100][100]) 
{
    int n = sizeof(a);
    double sum_diag = 0;
    double sum_row = 0;
    for (int i = 0; i < n; i++) {
        sum_diag += fabs(a[i][i]);
        sum_row = 0;
        for (int j = 0; j < n; j++) {
            if (j != i) {
                sum_row += fabs(a[i][j]);
            }
        }
        if (sum_row >= sum_diag) {
            return false;  // ma tr?n kh�ng ch�o tr?i h�ng
        }
    }
    return true;  // ma tr?n ch�o tr?i h�ng
}

bool cheoTroiCot(double a[100][100]) 
{
    int n = sizeof(a);
    double sum_diag = 0;
    double sum_col = 0;
    for (int j = 0; j < n; j++) {
        sum_diag += fabs(a[j][j]);
        sum_col = 0;
        for (int i = 0; i < n; i++) {
            if (i != j) {
                sum_col += fabs(a[i][j]);
            }
        }
        if (sum_col >= sum_diag) {
            return false;  // ma tr?n kh�ng ch�o tr?i c?t
        }
    }
    return true;  // ma tr?n ch�o tr?i c?t
}
//////////////////////////////////////////
// matrix[hang][cot]
double chuanHangVecto(double b[100][100], int size)
{
    double X_inf = 0.0;
    for(int i = 0; i < size; i++){
        X_inf = max(X_inf, fabs(b[i][0])); 
    }
    return X_inf;
}

double chuanCotVecto(double b[100][100], int size)
{
    double X_1 = 0.0;
    for(int i = 0; i < size; i++)
    {
        X_1 = X_1 + fabs(b[i][0]);
    }
    return X_1;
}

// s?a l?i do?n code chuanHang
double chuanHang(double A[100][100], int size)
{
    double maxSum = 0.0; 

    for(int i = 0; i < size; i++)
    {
        double rowSum = 0.0; 

        for(int j = 0; j < size; j++)
        {
            rowSum += fabs(A[i][j]);
        }

        if(rowSum > maxSum)
        {
            maxSum = rowSum;
        }
    }
    return maxSum;
}

double chuanCot(double A[100][100], int size)
{
    double maxSum = 0.0; // Gi� tr? t?i da c?a t?ng gi� tr? tuy?t d?i trong c�c h�ng

    for(int i = 0; i < size; i++)
    {
        double colSum = 0.0; // T?ng gi� tr? tuy?t d?i trong h�ng i

        for(int j = 0; j < size; j++)
        {
            colSum += fabs(A[j][i]);
        }

        if(colSum > maxSum)
        {
            maxSum = colSum;
        }
    }
    return maxSum;
}

////////////////////////////////
double congMatrix(double A[100][100], double B[100][100], double C[100][100], int size)
{
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            C[i][j] = B[i][j] + A[i][j];
        }
    }
    return C[100][100];
}


double nhanMatrix(double A[100][100], double B[100][100], double C[100][100], int size)
{   
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < sizeof(B); j++) 
        {
            C[i][j] = 0;
            for(int k = 0; k < size; k++)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return C[100][100];
}

////////////////////////////////////////////////////////////////

double timLamda(double a[100][100],double c[100][100], int size)// th?c ch?t l� t�m ma tr?n alpha || Q || < 1
{
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            if(i == j)
            {
                c[i][j] = 0;
            }
            else
            {
                c[i][j] = - a[i][j]/a[i][i];
            }
        }
    }
}

double timvecto_d(double a[100][100],double b[100][100], double c[100][100])
{
    for(int i = 0; i < sizeof(b); i++)
    {
        for(int j = 0; j < sizeof(b); j++)
        {
            
                c[i][j] = b[i][j]/a[i][i];
        }
    }
    return c[100][100];
}
////

void copy(double a[100][100],double b[100][100],int size)
{
    /*
    copy ma tran a vao b
    */
    for(int i = 0; i <size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            b[i][j] = a[i][j];
        }
    }

}

void loop_KDon(double D[100][100], double E[100][100], int size, int k,ofstream &outputFile)
{   double eva[100][100];
    cout<<"Nhap xap xi dau: x_0: "<<endl;
    outputFile<<"Nhap xap xi dau: x_0: "<<endl;
    cout<<"Chon luon xap xi dau la ma tran d."<<endl;
    outputFile<<"Chon luon xap xi dau la ma tran d."<<endl;
    double K[100][100];// copy 
    copy(E, K, size);


    double F[100][100];// F l� ma tr?n d? luu k?t qu? 
    int dem = 1;

    while(dem <=k) // c�ng th? l?p X = DX_0 + E
    {
    	cout<<"Lan "<<dem<<endl;
        outputFile<<"Lan "<<dem<<endl;

    	
	    nhanMatrix(D, E, F, size); // DxE -> BxX_0 
	    congMatrix(F, K, F, size);
	    XuatMaTran(F, size, 1, outputFile);

        eva[0][0] = E[0][0]-F[0][0];
        eva[1][0] = E[1][0]-F[1][0];
        eva[2][0] = E[2][0]-F[2][0];
        
        copy(F, E, size);
	    dem++;
	}

    cout<<endl<<"Danh gia sai so: "<<endl;
    outputFile<<endl<<"Danh gia sai so: "<<endl;
    cout<<"sai so: (q/(1-q))"<<"(X_"<<k<<" - "<<"X_"<<k-1<<") = "<<chuanHang(D, size)/(1-chuanHang(D, size))*chuanHang(eva, size);
    outputFile<<"sai so: (q/(1-q))"<<"(X_"<<k<<" - "<<"X_"<<k-1<<") = "<<chuanHang(D, size)/(1-chuanHang(D, size))*chuanHang(eva, size)<<endl;
}

void loop_eDon(double D[100][100], double E[100][100], int size, double e, ofstream &outputFile)
{   double eva[100][100];
    double K[100][100];// copy 
    copy(E, K, size);
    double F[100][100];// F l� ma tr?n d? luu k?t qu? 

    int dem = 1;
    while(1) // c�ng th? l?p X = DX_0 + E
    {
    	cout<<"Lan "<<dem<<endl;
        outputFile<<"Lan "<<dem<<endl;
    	
	    nhanMatrix(D, E, F, size); // DxE -> BxX_0 
	    congMatrix(F, K, F, size);
	    XuatMaTran(F, size, 1, outputFile);

        eva[0][0] = E[0][0]-F[0][0];
        eva[1][0] = E[1][0]-F[1][0];
        eva[2][0] = E[2][0]-F[2][0];
        
        copy(F, E, size);

        // n?u sai s? nh? hon sai s? nh?p v�o th� d?ng
        if((chuanHang(D, size)/(1-chuanHang(D, size))*chuanHang(eva, size)) < e) break;
	    dem++;
        // if(dem == 5) break;
	}
}

void loop_Don_with_condition(double D[100][100], double E[100][100], int size, double e, ofstream &outputFile)
{   double eva[100][100];
    // cout<<"Nhap xap xi dau: x_0: "<<endl;
    // cout<<"Chon luon xap xi dau la ma tran d."<<endl;
    
    double K[100][100];// copy 
    copy(E, K, size);
    double F[100][100];// F l� ma tr?n d? luu k?t qu? 

    int dem = 1;
    while(1) // c�ng th? l?p X = DX_0 + E
    {
    	cout<<"Lan "<<dem<<endl;
    	outputFile<<"Lan "<<dem<<endl;
    	
	    nhanMatrix(D, E, F, size); // DxE -> BxX_0 
	    congMatrix(F, K, F, size);
	    XuatMaTran(F, size, 1, outputFile);

        eva[0][0] = E[0][0]-F[0][0];
        eva[1][0] = E[1][0]-F[1][0];
        eva[2][0] = E[2][0]-F[2][0];
        
        copy(F, E, size);

        // n?u sai s? nh? hon sai s? nh?p v�o th� d?ng
        if(chuanHang(eva, size) < e) break;
	    dem++;
        // if(dem == 5) break;
	}
}


void loop_kSeidel(double D[100][100], double E[100][100], int size, int k, ofstream &outputFile)
{
    int dem = 1;
    double eva[100][100];
    double y[100][100];// ma tr?n ph? d? luu k?t qu?
    copy(E, y, size);
    while (dem < k) {
        for (int i = 0; i < size; i++)
        {
            double sum = 0.0;
            for (int j = 0; j < size; j++) 
            {
                if (j != i) 
                {
                    sum += D[i][j] * y[j][0];
                }
            }
            y[i][0] = E[i][0] + sum;
        }
        if(dem == k -1 )
        {
            copy(y, eva, size);
        }
        dem++;
    }

    eva[0][0] = y[0][0] - eva[0][0];//cout<<eva[0][0]<<endl;
    eva[1][0] = y[1][0] - eva[1][0];//cout<<eva[1][0]<<endl;
    eva[2][0] = y[2][0] - eva[2][0];//cout<<eva[2][0]<<endl;

    cout << endl<<"Da giai xong he phuong trinh trong " << dem << " buoc lap." << endl;
    outputFile << "Da giai xong he phuong trinh trong " << dem << " buoc lap." << endl;
    cout << "Nghiem cua he phuong trinh la: " << endl;
    outputFile << "Nghiem cua he phuong trinh la: " << endl;
    for (int i = 0; i < size; i++) 
    {
        cout << "x[" << i << "] = " << y[i][0] << endl;
        outputFile << "x[" << i << "] = " << y[i][0] << endl;
    }
    cout<<endl<<"Danh gia sai so: "<<endl;
    outputFile<<endl<<"Danh gia sai so: "<<endl;
    cout<<"Sai so: (q/(1-q))"<<"(X_"<<dem<<" - "<<"X_"<<dem-1<<") = "<<chuanHang(D, size)/(1-chuanHang(D, size))*chuanHang(eva, size)<<endl;
    outputFile<<"Sai so: (q/(1-q))"<<"(X_"<<dem<<" - "<<"X_"<<dem-1<<") = "<<chuanHang(D, size)/(1-chuanHang(D, size))*chuanHang(eva, size)<<endl;
}


void loop_eSeidel(double D[100][100], double E[100][100], int size, double e, ofstream &outputFile)
{
    int dem = 1;
    double eva[100][100];
    double y[100][100];// ma tr?n ph? d? luu k?t qu?
    copy(E, y, size);
    while (1) {
        copy(y, eva, size);
        for (int i = 0; i < size; i++)
        {
            double sum = 0.0;
            for (int j = 0; j < size; j++) 
            {
                if (j != i) 
                {
                    sum += D[i][j] * y[j][0];
                }
            }
            y[i][0] = E[i][0] + sum;
        }
        eva[0][0] = y[0][0] - eva[0][0];
        eva[1][0] = y[1][0] - eva[1][0];
        eva[2][0] = y[2][0] - eva[2][0];

        if(chuanHang(D, size)/(1-chuanHang(D, size))*chuanHang(eva, size) < e) break;
        dem++;

    }


    cout << "Da giai xong he phuong trinh trong " << dem << " buoc lap." << endl;
    outputFile << "Da giai xong he phuong trinh trong " << dem << " buoc lap." << endl;
    cout << "Nghiem cua he phuong trinh la: " << endl;
    outputFile << "Nghiem cua he phuong trinh la: " << endl;
    for (int i = 0; i < size; i++) 
    {
        cout << "x[" << i << "] = " << y[i][0] << endl;
        outputFile << "x[" << i << "] = " << y[i][0] << endl;
    }
}

void loop_Seidel_with_condition(double D[100][100], double E[100][100], int size, double e, ofstream &outputFile)
{
    int dem = 1;
    double eva[100][100];
    double y[100][100];// ma tr?n ph? d? luu k?t qu?
    copy(E, y, size);
    while (1) {
        copy(y, eva, size);
        for (int i = 0; i < size; i++)
        {
            double sum = 0.0;
            for (int j = 0; j < size; j++) 
            {
                if (j != i) 
                {
                    sum += D[i][j] * y[j][0];
                }
            }
            y[i][0] = E[i][0] + sum;
        }
        eva[0][0] = y[0][0] - eva[0][0];
        eva[1][0] = y[1][0] - eva[1][0];
        eva[2][0] = y[2][0] - eva[2][0];

        if(chuanHang(eva, size) < e) break;
        dem++;

    }


    cout << "Da giai xong he phuong trinh trong " << dem << " buoc lap." << endl;
    outputFile << "Da giai xong he phuong trinh trong " << dem << " buoc lap." << endl;
    cout << "Nghiem cua he phuong trinh la: " << endl;
    outputFile << "Nghiem cua he phuong trinh la: " << endl;
    for (int i = 0; i < size; i++) 
    {
        cout << "x[" << i << "] = " << y[i][0] << endl;
        outputFile << "x[" << i << "] = " << y[i][0] << endl;
    }
}

void chucnang1(ofstream &outputFile, double A[100][100], double b[100][100], int size)
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
                outputFile << "Giai HPT tuyen tinh AX = b bang lap don, lap Seidel" << endl;
                switch (choice) {
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

void setupMenu(ofstream &outputFile)
{
    int choice = 0;
    int maxChoice = 6;
    char key;

    while (true) {
        clearScreen();

        cout << "              =======================================================================================        "<< endl;
        cout << "              |  GIAI GAN DUNG HE PHUONG TRINH AX = b BANG PHUONG PHAP LAP DON, LAP SEIDELDAY CUNG  |          " << endl;
        cout << "              =======================================================================================        " << endl;

        for (int i = 0; i <= maxChoice; i++) {
            gotoxy(0, i + 3);
            if (i == choice) {
                printHighlightedOption(">>");
                switch (i) {
                    case 0:
                    	cout<<"        |";
                        printHighlightedOption("   1. Nhap vao A, b theo khuon dang cua ma tran");
                        cout<<"	                   	    |";
                        break;
                    case 1:
                    	cout<<"        |";
                        printHighlightedOption("   2. Kiem tra tinh cheo troi cua ma tran A va su hoi tu cua phuong phap");
                        cout<<"         |";
                        break;
                    case 2:
                    	cout<<"        |";
                        printHighlightedOption("   3. Tinh chuan cua ma tran A doi voi he da cho.");
                        cout<<"				    |";
                        break;
                    case 3:
                    	cout<<"        |";
                        printHighlightedOption("   4. Tinh nghiem gan dung voi so lan lap k cho truoc, danh gia sai so.");
                        cout<<"	    |";
                        break;
                    case 4:
                    	cout<<"        |";
                        printHighlightedOption("   5. Tinh nghiem gan dung voi sai so e cho truoc.");
                        cout<<"			            |";
                        break;
                    case 5:
                    	cout<<"        |";
                        printHighlightedOption("   6. Tinh nghiem gan dung X(k) thoa man: ||X(k)-X(k-1)|| <= e cho truoc");
                        cout<<"         |";
                        break;
                    case 6:
                    	cout<<"        |";
                        printHighlightedOption("   Thoat");
                        cout<<"                                                                         |";
                        break;
                }
            }
            else {
                printNormalOption("  ");
                switch (i) {
                    case 0:
                    	cout<<"        |";
                        printNormalOption("   1. Nhap vao A, b theo khuon dang cua ma tran");
                        cout<<"	                   	    |";
                        break;
                    case 1:
                    	cout<<"        |";
                        printNormalOption("   2. Kiem tra tinh cheo troi cua ma tran A va su hoi tu cua phuong phap");
                        cout<<"         |";
                        break;
                    case 2:
                    	cout<<"        |";
                        printNormalOption("   3. Tinh chuan cua ma tran A doi voi he da cho.");
                        cout<<"				    |";
                        break;
                    case 3:
                    	cout<<"        |";
                        printNormalOption("   4. Tinh nghiem gan dung voi so lan lap k cho truoc, danh gia sai so.");
                        cout<<"	    |";
                        break;
                    case 4:
                    	cout<<"        |";
                        printNormalOption("   5. Tinh nghiem gan dung voi sai so e cho truoc.");
                        cout<<"			            |";
                        break;
                    case 5:
                    	cout<<"        |";
                        printNormalOption("   6. Tinh nghiem gan dung X(k) thoa man: ||X(k)-X(k-1)|| <= e cho truoc");
                        cout<<"         |";
                        break;
                    case 6:
                    	cout<<"        |";
                        printNormalOption("   Thoat");
                        cout<<"                                                                         |";
                        break;
                }
            }
        }               cout<<endl;
                        cout << "              =======================================================================================        " << endl;


        key = getch(); 

        switch (key) {
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
                if (choice == maxChoice) {
                    cout << "Thoat chuong trinh." << endl;
                    exit(0);
                }
                else {
                    cout << "Ban da lua chon: ";
                    cout<<endl;
                    switch (choice) {
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
                            cout << "Kiem tra tinh cheo troi cua A: " << endl;
                            outputFile << "Kiem tra tinh cheo troi cua A: " << endl;
                            if (cheoTroiCot(A) and cheoTroiHang(A)){
                                cout<< " A cheo troi"<<endl;
                                outputFile<< " A cheo troi"<<endl;
                            }else{
                                cout<< " A khong cheo troi"<<endl;
                                outputFile<< " A khong cheo troi"<<endl;
                            }

                            cout<<"--------------"<<endl;
                            outputFile<<"--------------"<<endl;
                            if(chuanHang(D, size) < 1.0)
                            {   
                                cout<<"Do || Q || = "<<chuanHang(D, size)<<endl;
                                outputFile<<"Do || Q || = "<<chuanHang(D, size)<<endl;
                                cout<<"Phuong phap hoi tu";
                                outputFile<<"Phuong phap hoi tu";
                            }else{
                                cout<<"Do ||Q|| = "<<chuanHang(D, size)<<endl;
                                cout<<"Phuong phap khong hoi tu";
                                outputFile<<"Phuong phap khong hoi tu";
                            }
                            break;
                        case 2:
                            setTextColor(14); 
                            cout<<"Chuan cot cua B: " <<chuanCot(D, size)<< endl;
                            cout<<"Chuan hang cua B: " <<chuanHang(D, size)<< endl;
                            cout<<"Chuan cot cua vector d: " << chuanCotVecto(E, size)<< endl;
                            cout<<"Chuan hang cua vector d: " << chuanHangVecto(E, size)<< endl;
                            outputFile<<"Chuan cot cua B: " <<chuanCot(D, size)<< endl;
                            outputFile<<"Chuan hang cua B: " <<chuanHang(D, size)<< endl;
                            outputFile<<"Chuan cot cua vector d: " << chuanCotVecto(E, size)<< endl;
                            outputFile<<"Chuan hang cua vector d: " << chuanHangVecto(E, size)<< endl;
                            break;
                        case 3:
                            setTextColor(9); 
                            if(chuanHang(D, size)>=1)
                            {
                                cout<<"He phuong trinh ko giai duoc bang lap don, lap seidel"<< endl;
                                outputFile<<"He phuong trinh ko giai duoc bang lap don, lap seidel"<< endl;
                            }else
                            {
                            int choice;
                            
                            cout<<"1. Lap don"<< endl;
                            cout<<"2. Lap Seidel"<< endl;
                            
                            cin>>choice;
                            switch(choice){
                                case 1:
                                    outputFile<<"Lap don k lan:"<<endl;
                                    double D1[100][100], E1[100][100];
                                    copy(D,D1,size);
                                    copy(E,E1,size);
                                    cout<<"Lap don" << endl;
                                    int n_loop;
                                    cout<<"Nhap vao so lan lap: ";cin>>n_loop;
                                    outputFile<<"Nhap vao so lan lap: ";outputFile<<n_loop;

                                    loop_KDon(D1, E1, size, n_loop,outputFile);
                                    break;
                                case 2:
                                    outputFile<<"Lap Seidel k lan:"<<endl;
                                    cout<<"Lap Seidel: " << endl;
                                    int n_loop1;
                                    cout<<"Nhap vao so lan lap: ";cin>>n_loop1;
                                    outputFile<<"Nhap vao so lan lap: "<<n_loop;
                                    double D6[100][100], E6[100][100];
                                    copy(D,D6,size);
                                    copy(E,E6,size);

                                    loop_kSeidel(D6, E6, size, n_loop1,outputFile);     
                                    break;
                            }
                            }
                            break;
                        case 4:
                            setTextColor(13); 
                            if(chuanHang(D, size)>= 1){
                                cout<<"He da cho khong giai duoc bang pp lap don, seidel do he khong hoi tu: "<<endl;
                                outputFile<<"He da cho khong giai duoc bang pp lap don, seidel do he khong hoi tu: "<<endl;
                            }else
                            {
                            int choice2;
                            
                            cout<<"1. Lap don"<< endl;
                            cout<<"2. Lap Seidel"<< endl;
                            
                            cin>>choice2;
                            switch(choice2){
                                case 1:
                                    outputFile<<"Lap don voi sai so e cho truoc:"<<endl;
                                    double D2[100][100], E2[100][100];
                                    copy(D,D2,size);
                                    copy(E,E2,size);
                                    cout<<"Lap don voi sai so e cho truoc: " << endl;
                                    double e;
                                    cout<<"Nhap vao sai so e: ";cin>>e;

                                    loop_eDon(D2, E2, size, e,outputFile);
                                    break;
                                case 2:
                                    outputFile<<"Lap Seidel voi sai so e cho truoc:"<<endl;
                                    cout<<"Lap Seidel voi sai so e cho truoc " << endl;
                                    double eps;
                                    cout<<"Nhap vao sai so e: ";cin>>eps;
                                    outputFile<<"Nhap vao sai so e: ";outputFile<<eps<<endl;
                                    double D5[100][100], E5[100][100];
                                    copy(D,D5,size);
                                    copy(E,E5,size);
                                    loop_eSeidel(D5, E5, size, eps,outputFile);     
                                    break;
                                }
                            }
                            break;
                        case 5:
                            setTextColor(11); 
                            if(chuanHang(D, size)>=1)
                            {
                                cout<<"He da cho khong giai duoc bang lap don, lap seidel"<<endl;
                                outputFile<<"He da cho khong giai duoc bang lap don, lap seidel"<<endl;
                            }else
                            {
                            int choice3;
                            
                            cout<<"1. Lap don"<< endl;
                            cout<<"2. Lap Seidel"<< endl;
                            
                            cin>>choice3;
                            switch(choice3){
                                case 1:
                                    outputFile<<"Lap don co dieu kien voi sai so e cho truoc:"<<endl;
                                    cout<<"Lap don co dieu kien voi sai so e cho truoc: " << endl;
                                    double exp;
                                    double D3[100][100], E3[100][100];
                                    copy(D,D3,size);
                                    copy(E,E3,size);
                                    cout<<"Nhap vao sai so e: ";cin>>exp;

                                    loop_Don_with_condition(D3, E3, size, exp,outputFile);
                                    break;
                                case 2:
                                    outputFile<<"Lap Seidel co dieu kien voi sai so e cho truoc:"<<endl;
                                    cout<<"Lap Seidel co dieu kien voi sai so e cho truoc: " << endl;
                                    double eps;
                                    cout<<"Nhap vao sai so e: ";cin>>eps;
                                    double D4[100][100], E4[100][100];
                                    copy(D,D4,size);
                                    copy(E,E4,size);
                                    loop_Seidel_with_condition(D4, E4, size, eps,outputFile);     
                                    break;
                            }
                        }
                    }
                    setTextColor(15); 
                    cout<<endl;
                    cout << "Nhan phim bat ki de tiep tuc...";
                    outputFile <<endl<< "                 Exit..."<<endl;
                    getch(); 
                }
                break;
        }
    }
}

int main() 
{
    ofstream outputFile("output.txt");
    setupMenu(outputFile);
    outputFile.close();
    return 0;
}
