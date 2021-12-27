#include <iostream>
#include "Matrix.h"

using std::cin, std::cout, std::endl;

int main()
{
    // Manual Row Reduction Example

    Matrix<float> C(3, 3, { {2, 1, 2}, {3, 2, 2}, {1, 2, 3} });
    cout << C << endl;
    C.mult_row(1, (1/C.at(1,1)));
    cout << C << endl;
    C.mult_add_row(2, 1, -3);
    cout << C << endl;
    C.sub_row(3, 1);
    cout << C << endl;
    C.mult_row(2, 1/C.at(2,2));
    cout << C << endl;
    C.mult_add_row(1,2,-0.5);
    cout << C << endl;
    C.mult_add_row(3,2,-1.5);
    cout << C << endl;
    C.mult_row(3, 1/C.at(3,3));
    cout << C << endl;
    C.mult_add_row(2, 3, 2);
    cout << C << endl;
    C.mult_add_row(1, 3, -2);
    cout << C << endl;

    // Output

    //[[2 1 2]
     //[3 2 2]
     //[1 2 3]]

    //[[1 0.5 1]
     //[3 2 2]
     //[1 2 3]]

    //[[1 0.5 1]
     //[0 0.5 -1]
     //[1 2 3]]

    //[[1 0.5 1]
     //[0 0.5 -1]
     //[0 1.5 2]]

    //[[1 0.5 1]
     //[0 1 -2]
     //[0 1.5 2]]

    //[[1 0 2]
     //[0 1 -2]
     //[0 1.5 2]]

    //[[1 0 2]
     //[0 1 -2]
     //[0 0 5]]

    //[[1 0 2]
     //[0 1 -2]
     //[0 0 1]]

    //[[1 0 2]
     //[0 1 0]
     //[0 0 1]]

    //[[1 0 0]
     //[0 1 0]
     //[0 0 1]]

    return 0;
}

