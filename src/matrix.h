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

    const T operator[](int row, int col) const {
        return m_items[row * m_columns + col];
    };

    const T &operator[](int row, int col) { return m_items[row * m_columns + col]; }

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
      return Matrix(1, 1, std::vector<T>({1})); 
    };
    Matrix &operator*=(const Matrix &rhs);
};

#endif
