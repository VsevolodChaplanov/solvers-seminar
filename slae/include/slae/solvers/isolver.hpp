#ifndef SLAE_SOLVERS_ISOLVER_INCLUDED_HPP
#define SLAE_SOLVERS_ISOLVER_INCLUDED_HPP

#include <Eigen/Dense>
#include <Eigen/Sparse>

namespace slae::solvers {

    namespace dynamic_i {
        struct [[nodiscard]] ISolver {
            virtual Eigen::VectorX<double> solve(const Eigen::VectorX<double>& rhs);
            virtual ~ISolver() = default;
        };
    } // namespace dynamic_i

    // TASK hardmode:
    // * provide realization of your solving method for
    //   CRTP inheritance
    // Note:
    //   This approach reduce classic inheritance overhead and makes your perfomance
    //   of code higher
    namespace static_i {

        template <typename Solver> struct [[nodiscard]] ISolver {
            // TASK
            // * impose constraints on the template parameter
            // * contraints must be general for all dirived solver types
            template <typename Rhs> auto solve(Rhs&& rhs) {
                return static_cast<Solver&>(*this).solve(std::forward<Rhs>(rhs));
            }
        };
    } // namespace static_i
} // namespace slae::solvers

#endif // SLAE_SOLVERS_ISOLVER_INCLUDED_HPP