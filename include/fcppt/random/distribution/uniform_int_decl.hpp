//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RANDOM_DISTRIBUTION_UNIFORM_INT_DECL_HPP_INCLUDED
#define FCPPT_RANDOM_DISTRIBUTION_UNIFORM_INT_DECL_HPP_INCLUDED

#include <fcppt/static_assert_statement.hpp>
#include <fcppt/strong_typedef.hpp>
#include <fcppt/random/distribution/declare_call.hpp>
#include <fcppt/random/distribution/uniform_int_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/random/uniform_int_distribution.hpp>
#include <boost/type_traits/is_integral.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace random
{
namespace distribution
{

/**
\brief A wrapper around a uniform int distribution

\ingroup fcpptrandom

Wraps a uniform int distribution, removing the default parameters of the
constructor and also using strong typedefs.

\tparam IntType Must be an integer type
*/
template<
	typename IntType
>
class uniform_int
{
	typedef boost::random::uniform_int_distribution<
		IntType
	> wrapped;
public:
	/**
	\brief The int type used
	*/
	typedef IntType int_type;

	/**
	\brief The result returned by drawing random numbers
	*/
	typedef typename wrapped::result_type result_type;

	FCPPT_STATIC_ASSERT_STATEMENT(
		boost::is_integral<
			int_type
		>::value
	);

	FCPPT_MAKE_STRONG_TYPEDEF(
		int_type,
		min
	);

	FCPPT_MAKE_STRONG_TYPEDEF(
		int_type,
		max
	);

	/**
	\brief Constructs a uniform int distribution

	Constructs the uniform int distribution from \a _min and \a _max.

	\param _min The minimum value this distribution can produce

	\param _max The maximum value this distribution can produce
	*/
	uniform_int(
		min _min,
		max _max
	);

	FCPPT_RANDOM_DISTRIBUTION_DECLARE_CALL;
private:
	wrapped wrapped_;
};

}
}
}

#endif
