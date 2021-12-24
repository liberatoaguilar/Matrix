#ifndef _MATRIX
#define _MATRIX

#include <iostream>
#include <vector>

using std::vector;

template <class T>
class Matrix
{
private:
    int rows{};
    int cols{};    
    vector<vector<T> > entries;
    T at_z(int i, int j);
    T det_recur_helper(Matrix<T> M);

public:
    Matrix(int r, int c);
    Matrix(int r, int c, vector<vector<T> > e);
    T at(int i, int j);
    Matrix tpose();
    int getRows() const { return this->rows; }
    int getCols() const { return this->cols; }
    T det();
    Matrix<T> remove_row_col(int r, int c);
    Matrix<T> adj();
    Matrix<float> inv();

    Matrix<T> operator+(Matrix<T> B);
    Matrix<T> operator-(Matrix<T> B);
    Matrix<T> operator*(Matrix<T> B);

};

// Output:
// [[a b c]
//  [d e f]
//  [g h i]]
template <class T>
std::ostream& operator<<(std::ostream& os, Matrix<T> A)
{
    os << '[';
    for (int i = 0; i < A.getRows(); ++i)
    {
        if (i != 0) os << ' ';
        os << '[';
        for (int j = 0; j < A.getCols(); ++j)
        {
            // .at() indexing begins at 1, offset by adding 1
            os << A.at(i+1, j+1);
            if (j != A.getCols()-1) os << ' ';
        }
        os << ']';
        if (i != A.getRows()-1) os  << '\n';
    }
    os << ']' << '\n';
    return os;
}

// Constructors

template <class T>
Matrix<T>::Matrix(int r, int c, vector<vector<T> > e) : rows(r), cols(c), entries(e) {}

template <class T>
Matrix<T>::Matrix(int r, int c) : rows(r), cols(c) {}

// Public .at() uses indexing starting at 1
template <class T>
T Matrix<T>::at(int i, int j)
{
    return this->entries.at(i-1).at(j-1);
}

// Private .at_z() uses indexing starting at zero
template <class T>
T Matrix<T>::at_z(int i, int j)
{
    return this->entries.at(i).at(j);
}

// Transpose
template <class T>
Matrix<T> Matrix<T>::tpose()
{
    // Swtich rows and cols
    vector<vector<T> > new_entries(this->cols, vector<T>(this->rows));
    for (int i = 0; i < this->rows; ++i)
    {
        for (int j = 0; j < this->cols; ++j)
        {
            // (j, i) entries become (i, j) entries
            new_entries.at(j).at(i) = this->at_z(i, j);
        }
    }
    // Swtich rows and cols
    return Matrix(this->cols, this->rows, new_entries);
}

template <class T>
Matrix<T> Matrix<T>::operator+(Matrix<T> B)
{
    // Must be same size
    if (this->rows != B.rows || this->cols != B.cols)
        throw std::runtime_error("Incompatible Sizes");

    vector<vector<T> > new_entries(this->rows, vector<T>(this->cols));
    for (int i = 0; i < this->rows; ++i)
    {
        for (int j = 0; j < this->cols; ++j)
        {
            // Add entries a_ij+b_ij
            new_entries.at(i).at(j) = this->at_z(i, j)+B.at_z(i, j);
        }
    }
    return Matrix(this->rows, this->cols, new_entries);
}

template <class T>
Matrix<T> Matrix<T>::operator-(Matrix<T> B)
{
    // Must be same size
    if (this->rows != B.rows || this->cols != B.cols)
        throw std::runtime_error("Incompatible Sizes");

    vector<vector<T> > new_entries(this->rows, vector<T>(this->cols));
    for (int i = 0; i < this->rows; ++i)
    {
        for (int j = 0; j < this->cols; ++j)
        {
            // Subtract entries a_ij-b_ij
            new_entries.at(i).at(j) = this->at_z(i, j)-B.at_z(i, j);
        }
    }
    return Matrix(this->rows, this->cols, new_entries);
}

// Matrix Multiplication
template <class T>
Matrix<T> Matrix<T>::operator*(Matrix<T> B)
{
    // Check if matrix multiplication is possible
    if (this->cols != B.rows) throw std::runtime_error("Incompatible Sizes");

    // New matrix will be a new size
    vector<vector<T> > new_entries(this->rows, vector<T>(B.cols));
    T prodsum{};
    // Loops represent new size
    for (int i = 0; i < this->rows; ++i)
    {
        for (int j = 0; j < B.cols; ++j)
        {
            prodsum = 0;
            for (int k = 0; k < this->cols; ++k)
            {
                // Sum and multiply to get new entry
                // A is ixk and B is kxj while new matrix will be ixj
                prodsum += this->at_z(i, k)*B.at_z(k, j);
            }
            new_entries.at(i).at(j) = prodsum;
        }
    }
    // Return with new size and entries
    return Matrix(this->rows, B.cols, new_entries);
}

// Scalar Multiplication
// Must be of the form: α*M where α is a scalar and M is a matrix object
template <class T>
Matrix<T> operator*(T alpha, Matrix<T> A)
{
    vector<vector<T> > new_entries(A.getRows(), vector<T>(A.getCols()));
    for (int i = 0; i < A.getRows(); ++i)
    {
        for (int j = 0; j < A.getCols(); ++j)
        {
            // Multiply all entries by the scalar α
            // Add one to offset indexing starting at 1
            new_entries.at(i).at(j) = alpha*A.at(i+1, j+1);
        }
    }
    return Matrix(A.getRows(), A.getCols(), new_entries);
}

template <class T>
Matrix<T> Matrix<T>::remove_row_col(int r, int c)
{
    // New matrix will have one less row and column
    vector<vector<T> > new_entries(this->getRows()-1, vector<T>(this->getCols()-1));
    // Keep track of new entries' rows and columns
    int m{};
    int n{};
    // i and j loop through old entries' rows and columns
    for (int i = 0; i < this->rows; ++i)
    {
        // Don't add specified row
        if (i == r-1) continue;
        n = 0;
        for (int j = 0; j < this->cols; ++j)
        {
            // Don't add specified column
            if (j == c-1) continue;
            new_entries.at(m).at(n) = this->at_z(i, j);
            ++n;
        }
        ++m;
    }
    // New matrix will have one less row and column
    return Matrix(this->getRows()-1, this->getCols()-1, new_entries);
}

template <class T>
T Matrix<T>::det_recur_helper(Matrix<T> M)
{
    // Based on recursive definition (-1)^(i+j)*a_ij*det(Aij)
    // Always first column expansion

    // Base case 2x2
    if (M.getRows() == 2) return (M.at(1,1)*M.at(2,2)) - (M.at(1,2)*M.at(2,1));

    // Keep sum
    T determinant{};
    // Calculates (-1)^(i+j)
    int plus_minus{};
    for (int i = 1; i <= M.getRows(); ++i)
    {
        // 1 if i+j is even, -1 is i+1 is odd
        plus_minus = (((i + 1) % 2) == 0) ? 1 : -1;
        determinant += plus_minus*M.at(i,1)*det_recur_helper(remove_row_col(i, 1));
    }
    return determinant;
}

template <class T>
T Matrix<T>::det()
{
    // Must be square (same rows cols)
    if (this->rows != this->cols) throw std::runtime_error("Not Square");    
    // If 1x1
    if (this->rows == 1) return this->at(1, 1);
    // Recursive definition
    return det_recur_helper(*this);
}

template <class T>
Matrix<T> Matrix<T>::adj()
{
    // Adjoint of matrix
    vector<vector<T> > new_entries(this->rows, vector<T>(this->cols));

    int plus_minus{};
    for (int i = 1; i <= this->rows; ++i)
    {
        for (int j = 1; j <= this->cols; ++j)
        {
            // Represents (-1)^(i+j)
            plus_minus = (((i + j) % 2) == 0) ? 1 : -1;
            // Subtract 1 for 0 based indexing
            new_entries.at(i-1).at(j-1) = plus_minus*remove_row_col(i, j).det();
        }
    }
    // Return transpose for adjoint
    return Matrix(this->rows, this->cols, new_entries).tpose();
}

template <class T>
Matrix<float> Matrix<T>::inv()
{
    // Based on A^-1 = 1/det(A) * adj(A)
    // Returns as float matrix because 1/det(A)

    vector<vector<float> > new_entries(this->rows, vector<float>(this->cols));
    // Convert this entries into floats
    for (int i = 0; i < this->rows; ++i)
    {
        for (int j = 0; j < this->cols; ++j)
        {
            new_entries.at(i).at(j) = static_cast<float>(this->entries.at(i).at(j));
        }
    }
    // New float version of this
    Matrix<float> this_float(this->rows, this->cols, new_entries);
    float determinant = this_float.det();
    // Prevent dividing by 0
    if (determinant == 0.0) throw std::runtime_error("Not Invertible");
    return (1/determinant)*(this_float.adj());
}

#endif
