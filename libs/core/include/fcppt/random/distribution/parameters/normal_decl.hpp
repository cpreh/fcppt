//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RANDOM_DISTRIBUTION_PARAMETERS_NORMAL_DECL_HPP_INCLUDED
#define FCPPT_RANDOM_DISTRIBUTION_PARAMETERS_NORMAL_DECL_HPP_INCLUDED

#include <fcppt/make_strong_typedef.hpp>
#include <fcppt/strong_typedef_impl.hpp>
#include <fcppt/random/distribution/base_type.hpp>
#include <fcppt/random/distribution/parameters/normal_fwd.hpp>
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
\brief Parameters class for normal distributions

This class can be used as fcppt::random::distribution::basic's template
parameter and is also used to initialize an object of it. It uses strong
typedefs for the mean and stddev parameters.

\ingroup fcpptrandom
*/
template<
	typename FloatType
>
class normal
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
	std::normal_distribution<
		base_type
	>
	distribution;

	typedef
	typename
	distribution::param_type
	wrapped_param_type;

	FCPPT_MAKE_STRONG_TYPEDEF(
		FloatType,
		mean
	);

	FCPPT_MAKE_STRONG_TYPEDEF(
		FloatType,
		stddev
	);

	/**
	\brief Constructs parameters for a normal distribution

	Constructs parameters for a normal distribution that uses \a _mean and
	\a _stddev as its parameters.

	\param _mean The mean value

	\param _stddev The standard deviation value
	*/
	normal(
		mean _mean,
		stddev _stddev
	);

	wrapped_param_type
	convert_from() const;

	static
	normal
	convert_to(
		distribution const &
	);
private:
	mean mean_;

	stddev stddev_;
};

}
}
}
}

#endif
