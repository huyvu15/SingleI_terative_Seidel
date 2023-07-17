#include <iostream>
#include <conio.h>
#include <windows.h>
#include<math.h>
// #include <function.h>

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

int whereX()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if(GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
		return csbi.dwCursorPosition.X;
	return -1;
}


//screen: get [y]
int whereY()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if(GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
		return csbi.dwCursorPosition.Y;
	return -1;
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
            cout << "a[" << i << ", " << j << "] = ";
            cin >> a[i][j];
        }
    }
}

void XuatMaTran(double a[100][100], int dong,int cot)
{
    for (int i = 0; i < dong; i++)
    {
        for (int j = 0; j < cot; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
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
            return false;  // ma trận không chéo trội hàng
        }
    }
    return true;  // ma trận chéo trội hàng
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
            return false;  // ma trận không chéo trội cột
        }
    }
    return true;  // ma trận chéo trội cột
}
//////////////////////////////////////////
// matrix[hang][cot]
double chuanHangVecto(double b[100][100])
{
    double X_inf = 0.0;
    for(int i = 0; i < sizeof(b); i++){
        X_inf = max(X_inf, fabs(b[i][0])); 
    }
    return X_inf;
}

double chuanCotVecto(double b[100][100])
{
    double X_1 = 0.0;
    for(int i = 0; i < sizeof(b); i++)
    {
        X_1 = X_1 + fabs(b[i][0]);
    }
    return X_1;
}

// double chuanHang(double A[100][100], int size)
// {
//     double A_inf = 0.0;
//     for(int i = 0; i < size; i++)
//     {
//         for(int j = 0; j < size; j++)
//         {
//             A_inf = A_inf + fabs(A[i][j]);
//         }
//     }
//     return A_inf;
// }

// sửa lại đoạn code chuanHang
double chuanHang(double A[100][100], int size)
{
    double maxSum = 0.0; // Giá tr? t?i da c?a t?ng giá tr? tuy?t d?i trong các hàng

    for(int i = 0; i < size; i++)
    {
        double rowSum = 0.0; // T?ng giá tr? tuy?t d?i trong hàng i

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
    double A_1 = 0.0;
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            A_1 = A_1 + fabs(A[j][i]);
        }
    }
    return A_1;
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

// đánh giá hội tụ
double timLamda(double a[100][100],double c[100][100], int size)// thực chất là tìm ma trận alpha || Q || < 1
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

double loop_KDon(double D[100][100], double E[100][100], int size, int k)
{   double eva[100][100];
    cout<<"Nhap xap xi dau: x_0: "<<endl;
    cout<<"Chon luon xap xi dau la ma tran d."<<endl;
    double K[100][100];// copy 
    copy(E, K, size);


    double F[100][100];// F là ma trận để lưu kết quả 
    int dem = 0;

    while(dem <k) // công thự lặp X = DX_0 + E
    {
    	cout<<"Lan "<<dem+1<<endl;
    	
	    nhanMatrix(D, E, F, size); // DxE -> BxX_0 
	    congMatrix(F, K, F, size);
	    XuatMaTran(F, size, 1);

        // khi chạy xong lệnh này, thì F là ma trận được dùng để lưu kết quả cuối cùng và được xuất ra
        // như vậy F là  ma trận X cần tìm
        // bh phải gắn lại X_0(E) là ma trận F, nhưng bh gắn như nào mới là câu chuyện  
        
        eva[0][0] = E[0][0]-F[0][0];
        eva[1][0] = E[1][0]-F[1][0];
        eva[2][0] = E[2][0]-F[2][0];
        
        copy(F, E, size);
	    dem++;
	}

    cout<<endl;
    cout<<"Danh gia sai so: ";
    cout<<endl;
    cout<<"sai so: (q/(1-q))"<<"(X_"<<k<<" - "<<"X_"<<k-1<<") = "<<chuanHang(D, size)/(1-chuanHang(D, size))*chuanHang(eva, size);
}

double loop_eDon(double D[100][100], double E[100][100], int size, double e)
{   double eva[100][100];
    cout<<"Nhap xap xi dau: x_0: "<<endl;
    cout<<"Chon luon xap xi dau la ma tran d."<<endl;
    double K[100][100];// copy 
    copy(E, K, size);
    double F[100][100];// F là ma trận để lưu kết quả 

    int dem = 0;
    while(1) // công thự lặp X = DX_0 + E
    {
    	cout<<"Lan "<<dem+1<<endl;
    	
	    nhanMatrix(D, E, F, size); // DxE -> BxX_0 
	    congMatrix(F, K, F, size);
	    XuatMaTran(F, size, 1);

        eva[0][0] = E[0][0]-F[0][0];
        eva[1][0] = E[1][0]-F[1][0];
        eva[2][0] = E[2][0]-F[2][0];
        
        copy(F, E, size);

        // nếu sai số nhỏ hơn sai số nhập vào thì dừng
        // if((chuanHang(D, size)/(1-chuanHang(D, size))*chuanHang(eva, size)) < e) break;
	    dem++;
        if(dem == 5) break;
	}
}

double loop_Don_with_condition(double D[100][100], double E[100][100], int size, double e)
{   double eva[100][100];
    cout<<"Nhap xap xi dau: x_0: "<<endl;
    cout<<"Chon luon xap xi dau la ma tran d."<<endl;

    double K[100][100];// copy 
    copy(D, E, size);
    double F[100][100];// F là ma trận để lưu kết quả 

    int dem = 0;
    while(1) // công thự lặp X = DX_0 + E
    {
    	cout<<"Lan "<<dem+1<<endl;
    	
	    nhanMatrix(D, E, F, size); // DxE -> BxX_0 
	    congMatrix(F, K, F, size);
	    XuatMaTran(F, size, 1);

        eva[0][0] = E[0][0]-F[0][0];
        eva[1][0] = E[1][0]-F[1][0];
        eva[2][0] = E[2][0]-F[2][0];

        copy(F, E, size);
        // nếu sai số nhỏ hơn sai số nhập vào thì dừng
        if((chuanHang(eva, size)) < e) break;
	    dem++;
	}
    
}


void loop_kSeidel(double A[100][100], double b[100][100], int size, int k)
{
    double X[100][100];

    // Kh?i t?o giá tr? ban d?u cho X
    for (int i = 0; i < size; i++) {
        X[i][0] = 0.0;
    }

    int dem = 0;
    while (dem < k) {
        for (int i = 0; i < size; i++) {
            double sum1 = 0.0;
            double sum2 = 0.0;

            for (int j = 0; j < i; j++) {
                sum1 += A[i][j] * X[j][0];
            }

            for (int j = i + 1; j < size; j++) {
                sum2 += A[i][j] * X[j][0];
            }

            X[i][0] = (b[i][0] - sum1 - sum2) / A[i][i];
        }
        dem++;
    }

    cout << "Nghiem gan dung:\n";
    XuatMaTran(X, size, 1);
}



void setupMenu()
{
    int choice = 0;
    int maxChoice = 6;
    char key;

    while (true) {
        clearScreen();

        cout << "              =====================================================================================        "<< endl;
        cout << "              |                                        MENU                                       |          " << endl;
        cout << "              =====================================================================================        " << endl;

        for (int i = 0; i <= maxChoice; i++) {
            gotoxy(0, i + 3);
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
                        printHighlightedOption("4. Tinh nghiem gan dung voi so lan lap k cho truoc, danh gia sai so theo ca 2 cong thuc");
                        break;
                    case 4:
                        printHighlightedOption("5. Tinh nghiem gan dung voi sai so e cho truoc, theo ca 2 cach ap dung cong thuc sai so.");
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
                        printNormalOption("  4. Tinh nghiem gan dung voi so lan lap k cho truoc va danh gia sai so theo ca 2 cong thuc");
                        break;
                    case 4:
                        printNormalOption("  5. Tinh nghiem gan dung voi sai so e cho truoc, theo ca 2 cach ap dung cong thuc sai so.");
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
                            setTextColor(10);// xanh la cay 
//                          cout << "Mau do" << endl;
							cout<<"Nhap ma tran A:"<<endl;
                            int size;
						    cout << "Nhap kich thuoc ma tran: ";
						    cin >> size;

						
						    double A[100][100];
							double b[100][100];
							
						    NhapMaTran(A, size, size);
						
						    cout << "Ma tran vua nhap:" << endl;
						    XuatMaTran(A, size, size);
						    
						    cout<<"---------------------"<<endl;
						    
						    cout<<"Nhap vector b:"<<endl;
							NhapMaTran(b, size, 1);						
						    cout << "Vector b:" << endl;
						    XuatMaTran(b, size, 1);

						    cout<<"---------------------"<<endl;

                            cout<<"Ma tran alpha la:"<<endl;
                            double D[100][100];
                            timLamda(A, D, size);
                            XuatMaTran(D, size, size);
                            double E[100][100];
                            cout<<"vetor d la:"<<endl;
                            timvecto_d(A, b, E);
                            XuatMaTran(E, size,1);
                            
                            break;
                        case 1:
                            setTextColor(12); 
                            cout << "Kiem tra tinh cheo troi cua A: " << endl;
                            if (cheoTroiCot(A) and cheoTroiHang(A)){
                                cout<< " A cheo troi"<<endl;
                            }else{
                                cout<< " A khong cheo troi"<<endl;
                            }

                            cout<<"--------------"<<endl;
                            if(chuanHang(D, size) < 1.0)
                            {   
                                cout<<"|| Q || = "<<chuanHang(D, size)<<endl;
                                cout<<"Phuong phap hoi tu";
                            }else{
                                cout<<chuanHang(D, size)<<endl;
                                cout<<"Phuong phap khong hoi tu";
                            }

                            break;
                        case 2:
                            setTextColor(14); 
                            cout << "Mau vang" << endl;
                            cout<<"Chuan cot cua A: " <<chuanCot(A, size)<< endl;
                            cout<<"Chuan hang cua A: " <<chuanHang(A, size)<< endl;
                            cout<<"Chuan cot cua vector b: " << chuanCotVecto(b)<< endl;
                            cout<<"Chuan hang cua vector b: " << chuanHangVecto(b)<< endl;
                            break;
                        case 3:
                            setTextColor(9); 
                            cout << "Mau xanh duong" << endl;
                            int a;
                            
                            cout<<"1. Lap don"<< endl;
                            cout<<"2. Lap Seidel"<< endl;
                            
                            cin>>a;
                            switch(a){
                                case 1:
                                    double D1[100][100], E1[100][100];
                                    copy(D,D1,size);
                                    copy(E,E1,size);
                                    cout<<"Lap don" << endl;
                                    int n_loop;
                                    cout<<"Nhap vao so lan lap: ";cin>>n_loop;

                                    loop_KDon(D1, E1, size, n_loop);
                                    break;
                                case 2:
                                    cout<<"Lap Seidel: " << endl;
                                    int k;
                                    cout<<"Nhap vao so lan lap: ";cin>>k;

                                    loop_kSeidel(A, b, size, k);     
                                    break;
                            }

                            break;
                        case 4:
                            setTextColor(13); 
                            cout << "Mau xanh duong" << endl;
                            double D2[100][100], E2[100][100];
                            copy(D,D2,size);
                            copy(E,E2,size);
                            cout<<"Lap don voi sai so e cho truoc: " << endl;
                            double e;
                            cout<<"Nhap vao sai so e: ";cin>>e;

                            loop_eDon(D2, E2, size, e);
                            break;
                        case 5:
                            setTextColor(11); 
                            cout << "Mau tim:" << endl;
                            cout<<"Lap don co dieu kien voi sai so e cho truoc: " << endl;
                            double exp;
                            double D3[100][100], E3[100][100];
                            copy(D,D3,size);
                            copy(E,E3,size);
                            cout<<"Nhap vao sai so e: ";cin>>exp;

                            loop_Don_with_condition(D3, E3, size, exp);
                            break;
                    }

                    setTextColor(15); 
                    cout<<endl;
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

