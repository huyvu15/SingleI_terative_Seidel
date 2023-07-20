

void chucnang1(ofstream &outputFile, double A[100][100], double b[100][100], int size)
{
    int choice = 0;
    int maxChoice = 2;
    char key;

    while (true) {
        clearScreen();

        cout << "              =======================================================================================        " << endl;
        cout << "              |                       Nhap input cho chuong trinh                                   |          " << endl;
        cout << "              =======================================================================================        " << endl;

        for (int i = 0; i <= maxChoice; i++) {
            gotoxy(0, i + 3);
            if (i == choice) {
                printHighlightedOption(">>");
                switch (i) {
                case 0:
                    cout << "        |";
                    printHighlightedOption("   1.  Nhap tu file");
                    cout << "                                                              |";
                    break;
                case 1:
                    cout << "        |";
                    printHighlightedOption("   2.  Nhap tay    ");
                    cout << "                                                              |";
                    break;
                case 2:
                    cout << "        |";
                    printHighlightedOption("   Thoat");
                    cout << "                                                                         |";
                    break;
                }
            }
            else {
                printNormalOption("  ");
                switch (i) {
                case 0:
                    cout << "        |";
                    printNormalOption("   1.  Nhap tu file");
                    cout << "                                                              |";
                    break;
                case 1:
                    cout << "        |";
                    printNormalOption("   2.  Nhap tay    ");
                    cout << "                                                              |";
                    break;
                case 2:
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

void chucnang4(ofstream &outputFile, double D[100][100], double E[100][100], int size)
{
    int choice = 0;
    int maxChoice = 2;
    char key;

    while (true) {
        clearScreen();

        cout << "              =======================================================================================        " << endl;
        cout << "              |                           Giai gan dung voi so lan lap k                            |          " << endl;
        cout << "              =======================================================================================        " << endl;

        for (int i = 0; i <= maxChoice; i++) {
            gotoxy(0, i + 3);
            if (i == choice) {
                printHighlightedOption(">>");
                switch (i) {
                case 0:
                    cout << "        |";
                    printHighlightedOption("   1. Lap don");
                    cout << "                                                                    |";
                    break;
                case 1:
                    cout << "        |";
                    printHighlightedOption("   2. Lap Seidel");
                    cout << "                                                                 |";
                    break;
                case 2:
                    cout << "        |";
                    printHighlightedOption("   Thoat");
                    cout << "                                                                         |";
                    break;
                }
            }
            else {
                printNormalOption("  ");
                switch (i) {
                case 0:
                    cout << "        |";
                    printNormalOption("   1. Lap don");
                    cout << "                                                                    |";
                    break;
                case 1:
                    cout << "        |";
                    printNormalOption("   2. Lap Seidel");
                    cout << "                                                                 |";
                    break;
                case 2:
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
                
                switch (choice) {
                case 0:
                    setTextColor(10);
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
                case 1:
                    setTextColor(12);
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

            setTextColor(15);
            cout << endl;
            cout << "Nhan phim bat ki de tiep tuc...";
            getch();
            break;
        }
    }
}

void chucnang5(ofstream &outputFile, double D[100][100], double E[100][100], int size)
{
    int choice = 0;
    int maxChoice = 2;
    char key;

    while (true) {
        clearScreen();

        cout << "              =======================================================================================        " << endl;
        cout << "              |                     Giai gan dung voi sai so e cho truoc(tien nghiem)               |          " << endl;
        cout << "              =======================================================================================        " << endl;

        for (int i = 0; i <= maxChoice; i++) {
            gotoxy(0, i + 3);
            if (i == choice) {
                printHighlightedOption(">>");
                switch (i) {
                case 0:
                    cout << "        |";
                    printHighlightedOption("   1. Lap don");
                    cout << "                                                                    |";
                    break;
                case 1:
                    cout << "        |";
                    printHighlightedOption("   2. Lap Seidel");
                    cout << "                                                                 |";
                    break;
                case 2:
                    cout << "        |";
                    printHighlightedOption("   Thoat");
                    cout << "                                                                         |";
                    break;
                }
            }
            else {
                printNormalOption("  ");
                switch (i) {
                case 0:
                    cout << "        |";
                    printNormalOption("   1. Lap don");
                    cout << "                                                                    |";
                    break;
                case 1:
                    cout << "        |";
                    printNormalOption("   2. Lap Seidel");
                    cout << "                                                                 |";
                    break;
                case 2:
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
                
                switch (choice) {
                case 0:
                    outputFile<<"Lap don voi sai so e cho truoc:"<<endl;
                    double D2[100][100], E2[100][100];
                    copy(D,D2,size);
                    copy(E,E2,size);
                    cout<<"Lap don voi sai so e cho truoc: " << endl;
                    double e;
                    cout<<"Nhap vao sai so e: ";cin>>e;

                    loop_eDon(D2, E2, size, e,outputFile);
                    
                    break;
                case 1:
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

            setTextColor(15);
            cout << endl;
            cout << "Nhan phim bat ki de tiep tuc...";
            getch();
            break;
        }
    }
}

void chucnang6(ofstream &outputFile, double D[100][100], double E[100][100], int size)
{
    int choice = 0;
    int maxChoice = 2;
    char key;

    while (true) {
        clearScreen();

        cout << "              =======================================================================================        " << endl;
        cout << "              |                      Giai gan dung voi dieu kien cho truoc(hau nghiem)              |          " << endl;
        cout << "              =======================================================================================        " << endl;

        for (int i = 0; i <= maxChoice; i++) {
            gotoxy(0, i + 3);
            if (i == choice) {
                printHighlightedOption(">>");
                switch (i) {
                case 0:
                    cout << "        |";
                    printHighlightedOption("   1. Lap don");
                    cout << "                                                                    |";
                    break;
                case 1:
                    cout << "        |";
                    printHighlightedOption("   2. Lap Seidel");
                    cout << "                                                                 |";
                    break;
                case 2:
                    cout << "        |";
                    printHighlightedOption("   Thoat");
                    cout << "                                                                         |";
                    break;
                }
            }
            else {
                printNormalOption("  ");
                switch (i) {
                case 0:
                    cout << "        |";
                    printNormalOption("   1. Lap don");
                    cout << "                                                                    |";
                    break;
                case 1:
                    cout << "        |";
                    printNormalOption("   2. Lap Seidel");
                    cout << "                                                                 |";
                    break;
                case 2:
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
                
                switch (choice) {
                case 0:
                    outputFile<<"Lap don co dieu kien voi sai so e cho truoc:"<<endl;
                    cout<<"Lap don co dieu kien voi sai so e cho truoc: " << endl;
                    double exp;
                    double D3[100][100], E3[100][100];
                    copy(D,D3,size);
                    copy(E,E3,size);
                    cout<<"Nhap vao sai so e: ";cin>>exp;

                    loop_Don_with_condition(D3, E3, size, exp,outputFile);
                    
                    break;
                case 1:
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

            setTextColor(15);
            cout << endl;
            cout << "Nhan phim bat ki de tiep tuc...";
            getch();
            break;
        }
    }
}