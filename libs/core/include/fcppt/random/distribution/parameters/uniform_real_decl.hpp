//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_RANDOM_DISTRIBUTION_PARAMETERS_UNIFORM_REAL_DECL_HPP_INCLUDED
#define FCPPT_RANDOM_DISTRIBUTION_PARAMETERS_UNIFORM_REAL_DECL_HPP_INCLUDED

#include <fcppt/declare_strong_typedef.hpp>
#include <fcppt/strong_typedef_impl.hpp> // IWYU pragma: keep
#include <fcppt/random/distribution/base_type.hpp>
#include <fcppt/random/distribution/parameters/uniform_real_fwd.hpp> // IWYU pragma: keep
#include <fcppt/config/external_begin.hpp>
#include <random>
#include <fcppt/config/external_end.hpp>

namespace fcppt::random::distribution::parameters
{
/**
\brief Parameters class for uniform real distributions

This class can be used as fcppt::random::distribution::basic's template
parameter and is also used to initialize an object of it. It uses strong
typedefs for the min and sup parameters.

\ingroup fcpptrandom
*/
template <typename FloatType>
class uniform_real
{
public:
  using result_type = FloatType;

  using base_type = fcppt::random::distribution::base_type<result_type>;

  using distribution = std::uniform_real_distribution<base_type>;

  using wrapped_param_type = typename distribution::param_type;

  FCPPT_DECLARE_STRONG_TYPEDEF(FloatType, min);

  FCPPT_DECLARE_STRONG_TYPEDEF(FloatType, sup);

  /**
  \brief Constructs parameters for a uniform real distribution

  Constructs parameters for a uniform real distribution that can produce
  values from \a _min to (not including) \a _sup

  \param _min The minimum value this distribution can produce

  \param _sup The supremum of all values this distribution can produce
  */
  uniform_real(min _min, sup _sup);

  [[nodiscard]] wrapped_param_type convert_from() const;

  [[nodiscard]] static uniform_real convert_to(distribution const &);

private:
  min min_;

  sup sup_;
};

}

#endif
