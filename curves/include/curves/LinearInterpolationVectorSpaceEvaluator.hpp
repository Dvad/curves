#ifndef CURVES_LINEAR_INTERPOLATION_VECTOR_SPACE_EVALUATOR_HPP
#define CURVES_LINEAR_INTERPOLATION_VECTOR_SPACE_EVALUATOR_HPP

#include "Evaluator.hpp"
#include "VectorSpaceConfig.hpp"
#include "LinearInterpolationVectorSpaceCurve.hpp"

namespace curves {

class Coefficients;

class LinearInterpolationVectorSpaceEvaluator : public Evaluator<VectorSpaceConfig> {

 public:

  typedef Evaluator<VectorSpaceConfig> Parent;
  typedef Parent::DerivativeType DerivativeType;
  typedef Parent::ValueType ValueType;

  LinearInterpolationVectorSpaceEvaluator(const LinearInterpolationVectorSpaceCurve& curve, const Time& time);
  virtual ~LinearInterpolationVectorSpaceEvaluator();

  virtual void getKeys(std::vector<Key> *outKeys) const;

  virtual void appendKeys(std::vector<Key> *outKeys) const;

  virtual std::vector<Key>::const_iterator keyBegin() const;

  virtual std::vector<Key>::const_iterator keyEnd() const;

  /// Evaluate the ambient space of the curve (functional form) by specifying new coefficients.
  virtual ValueType evaluate(const std::vector<Coefficient>& coefficients) const;

  /// Evaluate the curve derivatives (functional form).
  virtual Eigen::VectorXd evaluateDerivative(unsigned derivativeOrder,
                                             const std::vector<Coefficient>& coefficients) const;

  /// Evaluate the ambient space of the curve (functional form).
  virtual Eigen::VectorXd evaluateAndJacobian(const std::vector<Coefficient>& coefficients,
                                                    std::vector<Eigen::MatrixXd>* outJacobian) const;

  /// Evaluate the curve derivatives (functional form).
  virtual Eigen::VectorXd evaluateDerivativeAndJacobian(unsigned derivativeOrder,
                                                        const std::vector<Coefficient>& coefficients,
                                                        std::vector<Eigen::MatrixXd>* outJacobian) const;

  /// Evaluate the ambient space of the curve
  virtual ValueType evaluate(const Coefficients& coefficients) const;

  /// Get the curve Jacobians.
  /// This is the main interface for GTSAM
  virtual void getJacobians(unsigned derivativeOrder,
                            const Coefficients& coefficients,
                            const Eigen::MatrixXd& chainRule,
                            const std::vector<Eigen::MatrixXd*>& jacobians) const;

  /// Evaluate the ambient space of the curve
  virtual ValueType evaluateDerivative(unsigned derivativeOrder,
                                       const Coefficients& coefficients) const;
 private:

  std::vector<Key> keys_;
  double alpha_;
  size_t dimension_;

};

} // namespace curves


#endif /* CURVES_LINEAR_INTERPOLATION_VECTOR_SPACE_EVALUATOR_HPP */