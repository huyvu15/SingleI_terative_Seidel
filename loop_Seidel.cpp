#include <iostream>
#include <cmath>
using namespace std;

void NhapMaTran(double a[100][100], int dong, int cot)
{
    for (int i = 0; i < dong; i++)
    {
        for (int j = 0; j < cot; j++)
        {
            cout << "a[" << i << ", " << j << "] = ";
            cin >> a[i][j];
        }
    }
}

void XuatMaTran(double a[100][100], int dong, int cot)
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

int main()
{
    int size;
    cout << "Nhap kich thuoc ma tran: ";
    cin >> size;

    double A[100][100];
    double b[100][100];

    NhapMaTran(A, size, size);

    cout << "Ma tran vua nhap:" << endl;
    XuatMaTran(A, size, size);

    cout << "---------------------" << endl;

    cout << "Nhap vector b:" << endl;
    NhapMaTran(b, size, 1);
    cout << "Vector b:" << endl;
    XuatMaTran(b, size, 1);

    cout << "---------------------" << endl;

    int k = 0;
    loop_kSeidel(A, b, size, 5);
    return 0;
}

