//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RANDOM_DISTRIBUTION_PARAMETERS_UNIFORM_REAL_DECL_HPP_INCLUDED
#define FCPPT_RANDOM_DISTRIBUTION_PARAMETERS_UNIFORM_REAL_DECL_HPP_INCLUDED

#include <fcppt/make_strong_typedef.hpp>
#include <fcppt/strong_typedef_impl.hpp>
#include <fcppt/random/distribution/base_type.hpp>
#include <fcppt/random/distribution/parameters/uniform_real_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <random>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace random
{
namespace distribution
{
namespace parameters
{

/**
\brief Parameters class for uniform real distributions

This class can be used as fcppt::random::distribution::basic's template
parameter and is also used to initialize an object of it. It uses strong
typedefs for the min and sup parameters.

\ingroup fcpptrandom
*/
template<
	typename FloatType
>
class uniform_real
{
public:
	typedef
	FloatType
	result_type;

	typedef
	fcppt::random::distribution::base_type<
		result_type
	>
	base_type;

	typedef
	std::uniform_real_distribution<
		base_type
	>
	distribution;

	typedef
	typename
	distribution::param_type
	wrapped_param_type;

	FCPPT_MAKE_STRONG_TYPEDEF(
		FloatType,
		min
	);

	FCPPT_MAKE_STRONG_TYPEDEF(
		FloatType,
		sup
	);

	/**
	\brief Constructs parameters for a uniform real distribution

	Constructs parameters for a uniform real distribution that can produce
	values from \a _min to (not including) \a _sup

	\param _min The minimum value this distribution can produce

	\param _sup The supremum of all values this distribution can produce
	*/
	uniform_real(
		min _min,
		sup _sup
	);

	wrapped_param_type const
	convert_from() const;

	static
	uniform_real const
	convert_to(
		distribution const &
	);
private:
	min min_;

	sup sup_;
};

}
}
}
}

#endif
