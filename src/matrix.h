#ifndef MATRIX_H
#define MATRIX_H

#include <stdexcept>
#include <vector>

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

    T &operator[](int row, int col) { return m_items[row * m_columns + col]; }
};

#endif
