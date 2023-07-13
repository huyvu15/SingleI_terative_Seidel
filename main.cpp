//#include <iostream>
//
//using namespace std;
//
//void NhapMaTran(float a[100][100], int dong, int cot)
//{
//    for (int i = 0; i < dong; i++)
//    {
//    	for(int j = 0; j <cot; j++){
//        cout << "a[" << i / cot << ", " << i % cot << "] = ";
//        cin >> a[i][j];
//        }
//    }
//}
//
//void XuatMaTran(float a[100][100], int dong, int cot)
//{
//    for (int i = 0; i < dong; i++)
//    {
//        for (int j = 0; j < cot; j++)
//        {
//            cout << a[i][j] << " ";
//        }
//        cout << endl;
//    }
//}
//
//int main()
//{
//    int dong, cot;
//    cout << "Nhap so dong: ";
//    cin >> dong;
//    cout << "Nhap so cot: ";
//    cin >> cot;
//
//    float matran[100][100];
//
//    NhapMaTran(matran, dong, cot);
//
//    cout << "Ma tran vua nhap:" << endl;
//    XuatMaTran(matran, dong, cot);
//
//    return 0;
//}
#include <iostream>

using namespace std;

const int N = 8;

int A[] = { 55,88,33,11,77,66,44,22 };
int swap(int a, int b){
	int c = a;
	a = b;
	b = c;
}

void test() {
	int i = 1, j = N-1;
	
	int e = A[0];
	while (j >=i){
		while(j>=i && A[i] <e) ++i;
		while(j>=i && A[i] >e) --j;
		if(j >i) swap(A[i++], A[j--]);
	}
	swap(A[0], A[j]);
//	return A;
}
	
	 


void test1(int step) {
		for (int i = 0; i < step; i++) {
			for (int j =N- 1; j > i; j--) {
				if (A[j] < A[j - 11]) swap(A[j],A[j-1]);
}
}
}
int main(){
	test1(1);
	for(int i = 0; i<8;i++){
		cout<<A[i]<<"   ";
	}
}
