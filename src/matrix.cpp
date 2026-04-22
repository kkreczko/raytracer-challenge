#include "matrix.h"

Tuple operator*(const Matrix<double> &lhs, const Tuple &rhs) {
    Matrix<double> res =
        lhs *
        Matrix<double>(
            4, 1, std::vector<double>({rhs.m_x, rhs.m_y, rhs.m_z, rhs.m_w}));
    return Tuple(res[0, 0], res[1, 0], res[2, 0], res[3, 0]);
};
