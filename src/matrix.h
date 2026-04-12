#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <vector>

template <typename T> struct Matrix {
    int m_rows;
    int m_columns;
    std::vector<T> m_items;

    Matrix(int rows, int columns, std::vector<T> items) {
        if (m_rows * m_columns == items.size()) {
            m_rows = rows;
            m_columns = columns;
            m_items = std::move(items);
        } else
            std::cerr << "Matrix items do not match matrix size";
    };

    T operator[](int row, int col) const {
        return m_items[row * m_columns + col];
    };
};

#endif
