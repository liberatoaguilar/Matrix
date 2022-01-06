#include <iostream>
#include <string>
#include <vector>
#include "Matrix.h"

using std::cin, std::cout, std::endl;
using std::string, std::vector;

// Program to take derivatives of polynomials using matrix linear transformations
// This works because deriving is linear

Matrix<float> get_polynomial()
{
    // Get coefficients and put into rows of 1xn matrix
    cout << "Enter coefficients (stop to end)" << endl;
    int rows{};
    int power{};
    vector<vector<float> > entries{};
    string coef{};

    cout << "x^" << power << ": ";
    while (cin >> coef)
    {
        if (coef == "stop") break;
        entries.push_back({std::stof(coef)}); 
        ++power;
        ++rows;
        cout << "x^" << power << ": ";
    }
    return Matrix<float>(rows, 1, {entries});
}

Matrix<float> derive_polynomial(Matrix<float> poly)
{
    // Constructs Matrix of the form:
    // [[0 1 0 0]
    //  [0 0 2 0]
    //  [0 0 0 3]
    //  [0 0 0 0]]
    // To take derivative of polynomial in matrix form

    vector<vector<float> > new_entries(poly.getRows(), vector<float>(poly.getRows()));
    for (int i = 0; i < poly.getRows()-1; ++i)
    {
        new_entries.at(i).at(i+1) = i+1;
    }
    Matrix<float> deriv(poly.getRows(), poly.getRows(), new_entries);

    // Multiplication is the linear transformation that represents taking the derivative
    return deriv*poly;
}

void output_polynomial(Matrix<float> poly)
{
    // Nicely output polynomial 

    // Loop backwards (highest exponent first)
    for (int i = poly.getRows(); i > 0; --i)
    {
        // Simple conditional formatting
        if (poly.at(i, 1) == 0) continue;
        else if (i == 1) cout << '(' << poly.at(i, 1) << ')';
        else if (i == 2 && poly.at(i, 1) != 1) cout << '(' << poly.at(i, 1) << "x" << ") + ";
        else if (i == 2 && poly.at(i, 1) == 1) cout << '(' << "x" << ") + ";
        else if (poly.at(i, 1) != 1) cout << '(' << poly.at(i, 1) << "x^" << i-1 << ") + ";
        else cout << '(' << "x^" << i-1 << ") + ";
    }
}

int main()
{
    Matrix<float> poly = get_polynomial();
    cout << "d/dx (";
    output_polynomial(poly);
    cout << ") =" << endl;
    output_polynomial(derive_polynomial(poly));
    cout << endl;
    return 0;
}

// Sample Output
//
// Enter coefficients (stop to end)
// x^0: 1
// x^1: 2
// x^2: 1
// x^3: 4
// x^4: -5
// x^5: stop
// d/dx ((-5x^4) + (4x^3) + (x^2) + (2x) + (1)) =
// (-20x^3) + (12x^2) + (2x) + (2)


