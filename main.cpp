#include <iostream>
#include "Matrix.h"

using std::cin, std::cout, std::endl;

int main()
{
    //Matrix<int> A(2, 1, { {1}, {2} });    
    //Matrix<int> B(1, 2, { {2, 1} });
    Matrix<float> C(3, 3, { {2, 1, 2}, {3, 2, 2}, {1, 2, 3} });
    //Matrix<int> D(1, 1, { {2} });
    //Matrix<int> I(3, 3, { {1, 0, 0}, {0, 1, 0}, {0, 0, 1} });
    //cout << A << endl;
    //cout << B << endl;
    //cout << C << endl;
    //cout << C.tpose() << endl;
    //cout << A*B << endl;
    //cout << A+A << endl;
    //cout << A-A << endl;
    //cout << C*C*C << endl;
    //cout << (2*C)*C+I << endl;
    cout << C << endl;
    cout << C.det() << endl;
    cout << C.adj() << endl;
    cout << C.inv() << endl;
    cout << (C*C.adj()) << endl;
    cout << (C*C.inv()) << endl;
    return 0;
}

