#include <iostream>
#include "Matrix.h"

using std::cin, std::cout, std::endl;

int main()
{
    // Textbook Example Section 3.4 #10
    // The vectors x1, x2, x3, x4, x5 span R3
    // Pare down the set {x1, x2, x3, x4, x5} to form a basis for R3
    Matrix<float> x1(3, 1, { {1}, {2}, {2} });
    Matrix<float> x2(3, 1, { {2}, {5}, {4} });
    Matrix<float> x3(3, 1, { {1}, {3}, {2} });
    Matrix<float> x4(3, 1, { {2}, {7}, {4} });
    Matrix<float> x5(3, 1, { {1}, {1}, {0} });
    cout << "x1:" << endl;
    cout << x1 << endl;
    cout << "x2:" << endl;
    cout << x2 << endl;
    cout << "x3:" << endl;
    cout << x3 << endl;
    cout << "x4:" << endl;
    cout << x4 << endl;
    cout << "x5:" << endl;
    cout << x5 << endl;

    Matrix<float> A = x1.addCol(x2).addCol(x3).addCol(x4).addCol(x5);
    cout << "A:" << endl;
    cout << A << endl;

    cout << "Reduced Row Echelon Form:" << endl;
    cout << A.rref() << endl;

    cout << "x1, x2, and x5 are 3 linearly independent vectors in R3, therefore span(x1, x2, x5) is a basis of R3." << endl;

    // Output
    // x1:
    // [[1]
     // [2]
     // [2]]
 
    // x2:
    // [[2]
     // [5]
     // [4]]
 
    // x3:
    // [[1]
     // [3]
     // [2]]
 
    // x4:
    // [[2]
     // [7]
     // [4]]
 
    // x5:
    // [[1]
     // [1]
     // [0]]
 
    // A:
    // [[1 2 1 2 1]
     // [2 5 3 7 1]
     // [2 4 2 4 0]]
 
    // Reduced Row Echelon Form:
    // [[1 0 -1 -4 0]
     // [0 1 1 3 0]
     // [0 0 0 0 1]]

    // x1, x2, and x5 are 3 linearly independent vectors in R3, 
    // therefore span(x1, x2, x5) is a basis of R3.

    return 0;
}
