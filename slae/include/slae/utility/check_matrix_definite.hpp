#ifndef SLAE_UTILITY_CHECK_MATRIX_DEFINITE_INCLUDED_HPP
#define SLAE_UTILITY_CHECK_MATRIX_DEFINITE_INCLUDED_HPP

#include <Eigen/Sparse>
#include <Eigen/src/Core/Matrix.h>
#include <type_traits>

namespace slae {
    namespace algo {

        // Extend this interface for other matrix types
        struct DefiniteMatrix final {
            template <typename Scalar, std::size_t Rows, std::size_t Columns>
                requires(std::is_arithmetic_v<Scalar>)
            bool check_on_semidefinite(const Eigen::Matrix<Scalar, Rows, Columns>& matrix) {
                // TASK:
                // ... put your realization here
                return false;
            }

            // HARDMODE:
            // * write constraints for generic definite matrix check
            template <typename Matrix> bool check_on_semidefinite(Matrix&& matrix) { return false; }
        };
    } // namespace algo
} // namespace slae

#endif // SLAE_UTILITY_CHECK_MATRIX_DEFINITE_INCLUDED_HPP