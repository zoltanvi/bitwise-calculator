/*
 * 2016.10.05.
 */
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

string nagybetu(string a) {
    string b2 = a;
    int i = 0;
    while (a[i]) {
        if ((a[i] >= 'a' && a[i] <= 'z') || (a[i] >= 'A' && a[i] <= 'Z')) {
            b2[i] = toupper(a[i]);
            i++;
        } else {
            i++;
        }
    }
    return b2;
}
int abcdef(char c) {
    if (c >= 'A' && c <= 'Z') {
        return c - 'A' + 10;
    }
    if (c >= '0' && c <= '9') {
        return c - '0';
    }
    return -1;
}

char fedcba(int value) {
    if (value >= 10 && value <= 'Z' - 'A' + 10) {
        return value + 'A' - 10;
    } else if (value >= 0 && value <= 9) {
        return value + '0';
    }
    return -1;
}



int main() {


    int mibol;
    string elsoinput;
    string masodikinput;
    string muvelet;

    cout << "******** Bitwise operation *********\nInput format:  number1  number2  base  operation\nOperations: (AND, OR, XOR, NAND, NOR XNOR)" << endl;
    cout << "*******************************************************" << endl;
    cin >> elsoinput >> masodikinput >> mibol >> muvelet;
    cout << "*******************************************************" << endl;

    string elso = nagybetu(elsoinput);
    string masodik = nagybetu(masodikinput);

    int elsohossz = elsoinput.length();
    int masodikhossz = masodikinput.length();
    string nagymuvelet = nagybetu(muvelet);



    /******************************** INPUT CHECKING ****************************/

    for (int i = 0; i<elsohossz; i++) {
        if (abcdef(elso[i]) >= mibol || abcdef(elso[i]) == -1) {
            cout << "Wrong input!" << endl;
            return 0;
        }
    }
    for (int i = 0; i<masodikhossz; i++) {
        if (abcdef(masodik[i]) >= mibol || abcdef(masodik[i]) == -1) {
            cout << "Wrong input!" << endl;
            return 0;
        }
    }
    /****************************************************************************/
	
	
    /****************************** BASE CONVERTING *****************************/
    char elsokettes[256];
    char masodikkettes[256];
    int osszertek = 0;
    int hatvany = 1;

    for (int k = 0; k < elsohossz; k++) {
        osszertek += abcdef(elso[elsohossz - k - 1]) * hatvany;
        hatvany *= mibol;
    }

    int aaa = 0;
    if (osszertek) {
        for (int i = 0; osszertek > 0; i++) {
            char asd = fedcba(osszertek % 2);
            elsokettes[i+1] = asd;
            aaa++;
            osszertek /= 2;
        }

    }
    int ehossz = aaa;

  
    osszertek = 0;
    hatvany = 1;
    for (int k = 0; k < masodikhossz; k++) {
        osszertek += abcdef(masodik[masodikhossz - k - 1]) * hatvany;
        hatvany *= mibol;
    }

    int bbb = 0;
    if (osszertek) {
        for (int i = 0; osszertek > 0; i++) {
            char asd = fedcba(osszertek % 2);
            masodikkettes[i + 1] = asd;
            bbb++;
            osszertek /= 2;
        }
    }
    int khossz = bbb;

    /***********************************************************************/

    if(ehossz > khossz) {
        while(khossz < ehossz) {
            masodikkettes[khossz+1] = '0';
            khossz++;
        }
    }
    if(khossz > ehossz) {
        while(khossz > ehossz) {
            elsokettes[ehossz+1] = '0';
            ehossz++;
        }
    }
    cout << "The numbers in base 2" << endl;
    cout << "First number:\t";
    int sadface = ehossz;
    while (ehossz) {
        cout << elsokettes[ehossz];
        ehossz--;
    }
    cout << endl;
    cout << "Second number:\t";

    while (khossz) {
        cout << masodikkettes[khossz];
        khossz--;
    }
    cout << endl ;



    if(nagymuvelet == "AND") {
        cout << "AND:\t\t";
        for(int hossz = sadface; hossz >= 0; hossz--) {
            if(elsokettes[hossz]=='0' && masodikkettes[hossz]=='0') {
                cout << "0";
            }
            if(elsokettes[hossz]=='0' && masodikkettes[hossz]=='1') {
                cout << "0";
            }
            if(elsokettes[hossz]=='1' && masodikkettes[hossz]=='0') {
                cout << "0";
            }
            if(elsokettes[hossz]=='1' && masodikkettes[hossz]=='1') {
                cout << "1";
            }
        }

    } else if(nagymuvelet == "OR") {
        cout << "OR:\t\t";
        for(int hossz = sadface; hossz >= 0; hossz--) {
            if(elsokettes[hossz]=='0' && masodikkettes[hossz]=='0') {
                cout << "0";
            }
            if(elsokettes[hossz]=='0' && masodikkettes[hossz]=='1') {
                cout << "1";
            }
            if(elsokettes[hossz]=='1' && masodikkettes[hossz]=='0') {
                cout << "1";
            }
            if(elsokettes[hossz]=='1' && masodikkettes[hossz]=='1') {
                cout << "1";
            }
        }
    } else if(nagymuvelet == "XOR") {
        cout << "XOR:\t\t";
        for(int hossz = sadface; hossz >= 0; hossz--) {
            if(elsokettes[hossz]=='0' && masodikkettes[hossz]=='0') {
                cout << "0";
            }
            if(elsokettes[hossz]=='0' && masodikkettes[hossz]=='1') {
                cout << "1";
            }
            if(elsokettes[hossz]=='1' && masodikkettes[hossz]=='0') {
                cout << "1";
            }
            if(elsokettes[hossz]=='1' && masodikkettes[hossz]=='1') {
                cout << "0";
            }
        }
    } else if(nagymuvelet == "NAND") {
        cout << "NAND:\t\t";
        for(int hossz = sadface; hossz >= 0; hossz--) {
            if(elsokettes[hossz]=='0' && masodikkettes[hossz]=='0') {
                cout << "1";
            }
            if(elsokettes[hossz]=='0' && masodikkettes[hossz]=='1') {
                cout << "1";
            }
            if(elsokettes[hossz]=='1' && masodikkettes[hossz]=='0') {
                cout << "1";
            }
            if(elsokettes[hossz]=='1' && masodikkettes[hossz]=='1') {
                cout << "0";
            }
        }
    } else if(nagymuvelet == "NOR") {
        cout << "NOR:\t\t";
        for(int hossz = sadface; hossz >= 0; hossz--) {
            if(elsokettes[hossz]=='0' && masodikkettes[hossz]=='0') {
                cout << "1";
            }
            if(elsokettes[hossz]=='0' && masodikkettes[hossz]=='1') {
                cout << "0";
            }
            if(elsokettes[hossz]=='1' && masodikkettes[hossz]=='0') {
                cout << "0";
            }
            if(elsokettes[hossz]=='1' && masodikkettes[hossz]=='1') {
                cout << "0";
            }
        }
    } else if(nagymuvelet == "XNOR") {
        cout << "XNOR:\t\t";
        for(int hossz = sadface; hossz >= 0; hossz--) {
            if(elsokettes[hossz]=='0' && masodikkettes[hossz]=='0') {
                cout << "1";
            }
            if(elsokettes[hossz]=='0' && masodikkettes[hossz]=='1') {
                cout << "0";
            }
            if(elsokettes[hossz]=='1' && masodikkettes[hossz]=='0') {
                cout << "0";
            }
            if(elsokettes[hossz]=='1' && masodikkettes[hossz]=='1') {
                cout << "1";
            }
        }
    } else {
        printf("No such operation!");
    }

    cout << "\n" << endl;
    system("PAUSE");
    return 0;
}
