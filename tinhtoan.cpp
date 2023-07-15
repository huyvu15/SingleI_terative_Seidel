#include<iostream>
#include<string.h>
#include <math.h>
#include <conio.h>
#include "function.h"

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

double chuanHang(double A[100][100], int size)
{
    double A_inf = 0.0;
    for(int i = 0; i < sizeof(A); i++)
    {
        for(int j = 0; j < sizeof(A); j++)
        {
            A_inf = A_inf + fabs(A[i][j]);
        }
    }
    return A_inf;
}

double chuanCot(double A[100][100], int size)
{
    double A_1 = 0.0;
    for(int i = 0; i < sizeof(A); i++)
    {
        for(int j = 0; j < sizeof(A); j++)
        {
            A_1 = A_1 + fabs(A[j][i]);
        }
    }
    return A_1;
}

