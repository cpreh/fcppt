//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RANDOM_DISTRIBUTION_NORMAL_DECL_HPP_INCLUDED
#define FCPPT_RANDOM_DISTRIBUTION_NORMAL_DECL_HPP_INCLUDED

#include <fcppt/strong_typedef.hpp>
#include <fcppt/random/distribution/declare_call.hpp>
#include <fcppt/random/distribution/normal_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <random>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace random
{
namespace distribution
{

/**
\brief A wrapper around a normal distribution

\ingroup fcpptrandom

Wraps a normal distribution, removing the default parameters of the constructor
and also using strong typedefs.

\tparam FloatType Must be an floating point type
*/
template<
	typename FloatType
>
class normal
{
	typedef std::normal_distribution<
		FloatType
	> wrapped;
public:
	/**
	\brief The float type used
	*/
	typedef FloatType float_type;

	/**
	\brief The result returned by drawing random numbers
	*/
	typedef typename wrapped::result_type result_type;

	static_assert(
		std::is_floating_point<
			float_type
		>::value,
		"normal distributions only take floating point types"
	);

	FCPPT_MAKE_STRONG_TYPEDEF(
		float_type,
		mean
	);

	FCPPT_MAKE_STRONG_TYPEDEF(
		float_type,
		sigma
	);

	/**
	\brief Constructs a normal distribution

	Constructs the normal distribution from \a _mean and \a _sigma.

	\param _mean The mean value

	\param _sigma The sigma value
	*/
	normal(
		mean _mean,
		sigma _sigma
	);

	FCPPT_RANDOM_DISTRIBUTION_DECLARE_CALL;
private:
	wrapped wrapped_;
};

}
}
}

#endif
