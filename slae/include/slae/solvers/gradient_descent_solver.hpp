// NOTE:
//    Don't forget to change include guard
#ifndef SLAE_SOLVERS_GRADIENT_DESCENT_SOLVER_INCLUDED_HPP
#define SLAE_SOLVERS_GRADIENT_DESCENT_SOLVER_INCLUDED_HPP

#include "isolver.hpp"

namespace slae::solvers {

    namespace dynamic_i {

        // TASK
        // * Write type constraints concept on Matrix
        //      The constraints should be no more than the method requires
        template <typename Matrix> struct [[nodiscard]] GradientDescentSolver : public ISolver {

            // TASK
            // * specify parameters in constuctor
            //      no more parameters than method required
            template <typename... SolverParameters> GradientDescentSolver(Matrix &&lhs, SolverParameters &&...params) {
                // TASK Whrite your realization here
                // ...
            }

            Eigen::VectorX<double> solve(const Eigen::VectorX<double> &rhs) override {
                // TASK Whrite your realization here
                // ...
            }

            ~GradientDescentSolver() override = default;

        private:
            Matrix lhs_;
        };
    } // namespace dynamic_i

    // TASK hardmode:
    // * provide realization of your solving method for
    //   CRTP inheritance
    // Note:
    //   This approach reduce classic inheritance overhead and makes your perfomance
    //   of code higher
    namespace static_i {

        // TASK
        // * Write type constraints concept on Matrix
        //      The constraints should be no more than the method requires
        template <typename Matrix>
        struct [[nodiscard]] GradientDescentSolver : public ISolver<GradientDescentSolver<Matrix>> {

            template <typename... SolverParameters> GradientDescentSolver(Matrix &&lhs, SolverParameters &&...params) {
                // TASK Whrite your realization here
                // ...
            }

            // TASK
            // * write type constraints concept on Rhs
            template <typename Rhs> auto solve(const Rhs &rhs) {
                // TASK Whrite your realization here
                // ...
            }

            ~GradientDescentSolver() override = default;

        private:
            Matrix lhs_;
        };
    } // namespace static_i
} // namespace slae::solvers

#endif // SLAE_SOLVERS_GRADIENT_DESCENT_SOLVER_INCLUDED_HPP