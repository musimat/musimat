/* $Revision: 1.6 $ $Date: 2006/09/08 18:56:52 $ $Author: dgl $ $Name:  $ $Id: Matrix.h,v 1.6 2006/09/08 18:56:52 dgl Exp $ */
#ifndef MATRIX_H
#define MATRIX_H

// The Musimat Tutorial � 2006 Gareth Loy
// Derived from Chapter 9 and Appendix B of "Musimathics Vol. 1" � 2006 Gareth Loy 
// and published exclusively by The MIT Press.
// This program is released WITHOUT ANY WARRANTY; without even the implied 
// warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 
// For information on usage and redistribution, and for a DISCLAIMER OF ALL
// WARRANTIES, see the file, "LICENSE.txt," in this distribution.
// "Musimathics" is available here:	http://mitpress.mit.edu/catalog/item/default.asp?ttype=2&tid=10916
// Gareth Loy's Musimathics website:	http://www.musimathics.com/
// The Musimat website:			http://www.musimat.com/
// This program is released under the terms of the GNU General Public License
// available here:			http://www.gnu.org/licenses/gpl.txt

///	@file Matrix.h
///	The Matrix class template
///

#include <iostream>
#include "List.h"

/// Matrix class implements a template for operations on matrices.
template <class Type>
class Matrix {

	/// Print a matrix to stdout
	friend ostream& operator<<(ostream& os,Const Matrix& m) {
		// os << m.m_lenRow << " " << m.m_lenCol << " " <<endl;
		for (Integer r = 0; r < m.m_lenRow; r++)
			cout << m.m_matrix[r];
		Return os;
	}
	
	/// Scan a matrix from stdin
	friend istream& operator>>(istream& is, Matrix& m) {
		Integer rows,cols;
		is >> rows >> cols;
		m.SetSize(rows, cols);
		for (Integer r = 0; r < rows; r++)
			for (Integer c = 0; c < cols; c++)
				is >> m[r][c];
		Return is;
		}
public:

	/// Default constructor
    Matrix(Integer rows=0, Integer cols=0): m_matrix(NULL) {
        SetSize(rows,cols);
    }

	/// Copy constructor
    Matrix(Const Matrix& m): m_matrix(NULL) {
        SetSize(m.m_lenRow, m.m_lenCol);
        for (Integer r=0; r < m_lenRow; r++)
            m_matrix[r]=List<Type>(m.m_matrix[r]);
    }

	/// Set the size of a matrix
	/// @param rows Number of rows
	/// @param cols Number of columns
    Void SetSize(Integer rows, Integer cols) {
		If (m_matrix != 0) { 
			delete[] m_matrix;
			m_matrix = 0;
		}
        If (cols > 0  And rows > 0) {
            m_matrix = new List<Type>[rows];
            for (Integer i = 0; i < rows; i++)
                m_matrix[i].SetListSize(cols);
        }
        Else
            rows = 0;
        m_lenCol = cols;
		m_lenRow = rows;
    }

	/// Indexing operator for matrix
	List<Type>& operator[](Integer index) {
        assert(index < m_lenRow);
        Return m_matrix[index];
    }

	/// Assignment/copy operator for matrix
    Matrix& operator=(Const Matrix& m) {
		If (this == &m)
			Return *this;
        SetSize(m.m_lenRow, m.m_lenCol);
		for (Integer r=0; r < m_lenRow; r++) {
            m_matrix[r] = List<Type>(m.m_matrix[r]);
		}
        Return *this;
    }

	/// Equality of two matrices
	Bool operator==(Const Matrix& m) {
		// Must have same dimensions
		If (m_lenRow != m.m_lenRow || m_lenCol != m.m_lenCol)
			Return False;

		// All rows must match
		For (Integer r=0; r < m_lenRow; r++) {
			If (m_matrix[r] != m.m_matrix[r])
				Return False;
		}
		Return( True );
	}

	/// Inequality of two matrices
	Bool operator!=(Const Matrix& m) {
		Return( ! (*this == m) );
	}

	/// Add two identical matrices.  
	/// Performs element-by-element addition
	Const Matrix operator+(Const Matrix& m) {
        assert(m_lenCol == m.m_lenCol  And m_lenRow == m.m_lenRow);
        Matrix newMatrix(m_lenRow, m_lenCol);
		For (Integer r=0; r < m_lenRow; r++)
            for (Integer c=0; c < m_lenCol;c++)
                newMatrix[r][c] = m_matrix[r][c] + m.m_matrix[r][c];
        Return newMatrix;
    }

	/// Subtract two identical matrices.  
	/// Performs element-by-element subtraction
	Const Matrix operator-(Const Matrix& m) {
        assert(m_lenCol == m.m_lenCol  And m_lenRow == m.m_lenRow);
        Matrix newMatrix(m_lenRow, m_lenCol);
		For (Integer r = 0; r < m_lenRow; r++)
            for (Integer c = 0; c < m_lenCol; c++)
                newMatrix[r][c] = m_matrix[r][c] - m.m_matrix[r][c];
        Return newMatrix;
    }

	/// Multiply matrix by a constant Integer
	Const Matrix operator*(Const Integer R) {
        Matrix newMatrix(m_lenRow, m_lenCol);
		For (Integer r = 0; r < m_lenRow; r++)
            for (Integer c = 0; c < m_lenCol; c++)
                newMatrix[r][c] = m_matrix[r][c] * R;
        Return newMatrix;
    }

	/// Multiply matrix by a constant Real
	Const Matrix operator*(Const Real R) {
        Matrix newMatrix(m_lenRow, m_lenCol);
		For (Integer r = 0; r < m_lenRow; r++)
            for (Integer c = 0; c < m_lenCol; c++)
                newMatrix[r][c] = m_matrix[r][c] * R;
        Return newMatrix;
    }

	/// Add constant Integer to matrix
	Const Matrix operator+(Const Integer R) {
        Matrix newMatrix(m_lenRow, m_lenCol);
		For (Integer r = 0; r < m_lenRow; r++)
            for (Integer c = 0; c < m_lenCol; c++)
                newMatrix[r][c] = m_matrix[r][c] + R;
        Return newMatrix;
    }

	/// Add constant Real to matrix
	Const Matrix operator+(Const Real R) {
        Matrix newMatrix(m_lenRow, m_lenCol);
		For (Integer r = 0; r < m_lenRow; r++)
            for (Integer c = 0; c < m_lenCol; c++)
                newMatrix[r][c] = m_matrix[r][c] + R;
        Return newMatrix;
    }

	/// Subtract constant Integer from matrix
	Const Matrix operator-(Const Integer R) {
        Matrix newMatrix(m_lenRow, m_lenCol);
		For (Integer r = 0; r < m_lenRow; r++)
            for (Integer c = 0; c < m_lenCol; c++)
                newMatrix[r][c] = m_matrix[r][c] - R;
        Return newMatrix;
    }

	/// Subtract constant Real from matrix
	Const Matrix operator-(Const Real R) {
        Matrix newMatrix(m_lenRow, m_lenCol);
		For (Integer r = 0; r < m_lenRow; r++)
            for (Integer c = 0; c < m_lenCol; c++)
                newMatrix[r][c] = m_matrix[r][c] - R;
        Return newMatrix;
    }

	/// Matrix multiplication.  Columns of first matrix must be same size as rows of second
	Const Matrix operator*(Matrix& m) {
        assert(m_lenCol==m.m_lenRow);
        Matrix newMatrix(m_lenRow,m.m_lenCol);
        for (Integer r = 0; r < m_lenRow; r++) {
            for (Integer c = 0; c < m.m_lenCol; c++) {
                for (Integer i = 0; i < m_lenCol; i++) {
                    newMatrix[r][c]+= m_matrix[r][i] * m[i][c];
                }
            }
        }
        Return newMatrix;
    }

	/// Print a row of a matrix
	/// @param s String to prefix to matrix
	Void print(String s = 0) {
		If (s)
			cout<<s;
		cout << "{\n";
		For (Integer i = 0; i < m_lenRow; i++)
			cout << m_matrix[i];
		cout << "}\n";
	}

	/// Return the number of rows in the Matrix
	Type rows() { Return m_lenRow; }

	/// Return the number of columns in the Matrix
	Type cols() { Return m_lenCol; }

	/// Return the number of rows and columns in the Matrix by reference
	/// @param r Number of rows, returned by reference
	/// @param c Number of columns, returned by reference
	Void length(Integer& r, Integer& c) { r = rows(); c = cols(); }

private:
    Integer m_lenCol, m_lenRow;
    List<Type>* m_matrix;

};

#endif // MATRIX_H
