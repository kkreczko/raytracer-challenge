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

    const T &operator[](int row, int col) const {
        return m_items[row * m_columns + col];
    };

    T &operator[](int row, int col) { return m_items[row * m_columns + col]; }

    bool operator==(const Matrix &rhs) const {
        if (m_items.size() != rhs.m_items.size())
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

        for(int i = 0; i < m_rows; ++i){
            for(int j = 0; j < rhs.m_columns; ++j){
                for(int k = 0; k < m_columns; ++k) {
                    result[i, j] += (*this)[i, k] * rhs[k, j];
                }
            }
        }

        return result;
    };

    Matrix &operator*=(const Matrix &rhs);
};

#endif
