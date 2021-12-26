# Matrix Library
* This is a simple matrix library. All algorithms are based on the descriptions of the textbook: `Linear Algebra with Applictions - Pearson - Steven J. Leon`.
* These are not the best known algorithms for matrix operations.
* This library was created as a learning exercise and to be used later in my Neural Network project.

## Features
* Any nxm matrix can be created (as shown in `main.cpp`)
* `tpose()` returns the transpose of a matrix
* `det()` returns the determinant of a matrix
    * Always first column expansion
* `remove_row_col()` returns an n-1xm-1 matrix without the specified row and column
* `adj()` returns the adjoint of a matrix
* `inv()` returns the inverse of a matrix
* `at()` returns element at (i,j) starting at 1 (not 0)
* `getRows()` and `getCols()` return dimension of a matrix
* `splitRows()` and `splitCols()` return vectors of rows or columns split up
* Matrix addition uses `operator+`
* Matrix subtraction uses `operator-`
* Matrix multiplication uses `operator*`
* Scalar multiplication also uses `operator*` but the form must be `α*M`
* A Matrix can be output to a stream with `operator<<`

### Planned
* Gauss-Jordan Elimination
* Row Operations
* LU Factorization?
* Outer/Inner Product?
* Eigenvalues/Eigenvectors?

## Sample Output from main.cpp
```
[[2 1 2]
 [3 2 2]
 [1 2 3]]

5
[[2 1 -2]
 [-7 4 2]
 [4 -3 1]]

[[0.4 0.2 -0.4]
 [-1.4 0.8 0.4]
 [0.8 -0.6 0.2]]

[[1 2 3]
 [4 5 6]
 [7 8 9]
 [1 1 1]]

[[1]
 [4]
 [7]
 [1]]

[[2]
 [5]
 [8]
 [1]]

[[3]
 [6]
 [9]
 [1]]

[[1 2 3]]

[[4 5 6]]

[[7 8 9]]

[[1 1 1]]
```
