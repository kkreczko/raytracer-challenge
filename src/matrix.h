#ifndef MATRIX_H
#define MATRIX_H

#include <stdexcept>
#include <vector>

#include "tuple.h"

template <typename T> struct Matrix {
    int m_rows;
    int m_columns;
    std::vector<T> m_items;

    Matrix(int rows, int columns, std::vector<T> items)
        : m_rows(rows), m_columns(columns), m_items(std::move(items)) {
        if (rows * columns != static_cast<int>(m_items.size()))
            throw std::invalid_argument(
                "Items size do not match rows * columns");
    };

    // Identity factory
    static Matrix ident(int dim) {
        Matrix res = Matrix<T>(dim, dim, std::vector<T>(dim * dim, 0));
        for (int i = 0; i < dim; i++) {
            res[i, i] = static_cast<T>(1);
        }
        return res;
    }

    const T &operator[](int row, int col) const {
        return m_items[row * m_columns + col];
    };

    T &operator[](int row, int col) { return m_items[row * m_columns + col]; }

    bool operator==(const Matrix &rhs) const {
        if (m_items.size() != rhs.m_items.size())
            return false;

        if (m_rows != rhs.m_rows || m_columns != rhs.m_columns)
            return false;

        for (int i = 0; i < m_items.size(); i++) {
            if (!float_equal(m_items[i], rhs.m_items[i]))
                return false;
        }

        return true;
    }

    Matrix operator*(const Matrix &rhs) const {
        if (m_columns != rhs.m_rows)
            throw std::invalid_argument(
                "Invalid matrices sizes in multiplication");
        Matrix result = Matrix(m_rows, rhs.m_columns,
                               std::vector<T>(m_rows * rhs.m_columns, T{}));

        for (int i = 0; i < m_rows; ++i) {
            for (int j = 0; j < rhs.m_columns; ++j) {
                for (int k = 0; k < m_columns; ++k) {
                    result[i, j] += (*this)[i, k] * rhs[k, j];
                }
            }
        }

        return result;
    };

    Matrix &operator*=(const Matrix &rhs) {
        *this = *this * rhs;
        return *this;
    };

    Matrix submatrix(int row, int column) const {
        if (m_columns != m_rows)
            throw std::invalid_argument(
                "Submatrix allowed only for square matrices");

        std::vector<T> resVec;
        for (int i = 0; i < m_rows; i++)
            for (int j = 0; j < m_columns; j++)
                if (i != row && j != column)
                    resVec.push_back((*this)[i, j]);

        int new_dim = m_rows - 1;
        return Matrix(new_dim, new_dim, resVec);
    };

    T det() const {
        if (m_columns != m_rows)
            throw std::invalid_argument(
                "Determinant allowed only for square matrices");

        T det = 0;

        if (this->m_columns == 2)
            return (*this)[0, 0] * (*this)[1, 1] -
                   (*this)[0, 1] * (*this)[1, 0];

        for (int i = 0; i < m_columns; i++)
            det += (*this)[0, i] * cofactor(0, i);

        return det;
    };

    T minor(int row, int column) const {
        return this->submatrix(row, column).det();
    }

    T cofactor(int row, int column) const {
        if (row + column % 2 != 0)
            return -this->minor(row, column);
        return this->minor(row, column);
    }

    Matrix inverse() const {
        if (!canInvert())
            throw std::invalid_argument("Matrix not possible to inverse");

        Matrix res =
            Matrix(m_rows, m_columns, std::vector<T>(m_columns * m_rows, 0));

        for (int row = 0; row < m_rows; row++)
            for (int col = 0; col < m_columns; col++)
                res[col, row] = cofactor(row, col) / det();

        return res;
    };

    bool canInvert() const { return !(det() == 0); };
};

Tuple operator*(const Matrix<double> &, const Tuple &);

#endif
