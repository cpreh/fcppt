//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RANDOM_DISTRIBUTION_UNIFORM_REAL_DECL_HPP_INCLUDED
#define FCPPT_RANDOM_DISTRIBUTION_UNIFORM_REAL_DECL_HPP_INCLUDED

#include <fcppt/static_assert_statement.hpp>
#include <fcppt/strong_typedef.hpp>
#include <fcppt/random/distribution/declare_call.hpp>
#include <fcppt/random/distribution/uniform_real_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/random/uniform_real_distribution.hpp>
#include <boost/type_traits/is_floating_point.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace random
{
namespace distribution
{

/**
\brief A wrapper around a uniform real distribution

\ingroup fcpptrandom

Wraps a uniform real distribution, removing the default parameters of the
constructor and also using strong typedefs.

\tparam FloatType Must be an floating point type
*/
template<
	typename FloatType
>
class uniform_real
{
	typedef boost::random::uniform_real_distribution<
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

	FCPPT_STATIC_ASSERT_STATEMENT(
		boost::is_floating_point<
			float_type
		>::value
	);

	FCPPT_MAKE_STRONG_TYPEDEF(
		float_type,
		min
	);

	FCPPT_MAKE_STRONG_TYPEDEF(
		float_type,
		sup
	);

	/**
	\brief Constructs a uniform real distribution

	Constructs the uniform real distribution from \a _min and \a _sup.

	\param _min The minimum value this distribution can produce

	\param _sup The supremum of all values this distribution can produce
	*/
	uniform_real(
		min _min,
		sup _sup
	);

	FCPPT_RANDOM_DISTRIBUTION_DECLARE_CALL;
private:
	wrapped wrapped_;
};

}
}
}

#endif
