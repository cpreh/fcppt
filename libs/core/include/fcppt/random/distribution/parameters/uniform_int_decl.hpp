//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_RANDOM_DISTRIBUTION_PARAMETERS_UNIFORM_INT_DECL_HPP_INCLUDED
#define FCPPT_RANDOM_DISTRIBUTION_PARAMETERS_UNIFORM_INT_DECL_HPP_INCLUDED

#include <fcppt/declare_strong_typedef.hpp>
#include <fcppt/strong_typedef_impl.hpp> // IWYU pragma: keep
#include <fcppt/random/distribution/base_type.hpp>
#include <fcppt/random/distribution/parameters/uniform_int_fwd.hpp> // IWYU pragma: keep
#include <fcppt/random/distribution/parameters/uniform_int_wrapper.hpp> // IWYU pragma: keep

namespace fcppt::random::distribution::parameters
{
/**
\brief Parameters class for uniform int distributions

This class can be used as fcppt::random::distribution::basic's template
parameter and is also used to initialize an object of it. It uses strong
typedefs for the min and max parameters.

\ingroup fcpptrandom
*/
template <typename IntType, typename Distribution>
class uniform_int
{
public:
  using result_type = IntType;

  using base_type = fcppt::random::distribution::base_type<result_type>;

  using distribution = typename Distribution::template apply<base_type>::type;

  using wrapped_param_type = typename distribution::param_type;

  FCPPT_DECLARE_STRONG_TYPEDEF(IntType, min);

  FCPPT_DECLARE_STRONG_TYPEDEF(IntType, max);

  /**
  \brief Constructs parameters for a uniform int distribution

  Constructs parameters for a uniform int distribution that can produce
  values from \a _min to (including) \a _max

  \param _min The minimum value this distribution can produce

  \param _max The maximum values this distribution can produce
  */
  uniform_int(min _min, max _max);

  [[nodiscard]] wrapped_param_type convert_from() const;

  static uniform_int convert_to(distribution const &);

private:
  min min_;

  max max_;
};

}

#endif
