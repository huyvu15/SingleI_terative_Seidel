#include <iostream>

using namespace std;

void NhapMaTran(float a[100][100], int dong, int cot)
{
    for (int i = 0; i < dong; i++)
    {
    	for(int j = 0; j <cot; j++){
        cout << "a[" << i / cot << ", " << i % cot << "] = ";
        cin >> a[i][j];
        }
    }
}

void XuatMaTran(float a[100][100], int dong, int cot)
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

int main()
{
    int dong, cot;
    cout << "Nhap so dong: ";
    cin >> dong;
    cout << "Nhap so cot: ";
    cin >> cot;

    float matran[100][100];

    NhapMaTran(matran, dong, cot);

    cout << "Ma tran vua nhap:" << endl;
    XuatMaTran(matran, dong, cot);

    return 0;
}

