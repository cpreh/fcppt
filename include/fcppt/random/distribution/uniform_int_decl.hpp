//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RANDOM_DISTRIBUTION_UNIFORM_INT_DECL_HPP_INCLUDED
#define FCPPT_RANDOM_DISTRIBUTION_UNIFORM_INT_DECL_HPP_INCLUDED

#include <fcppt/strong_typedef.hpp>
#include <fcppt/random/distribution/declare_call.hpp>
#include <fcppt/random/distribution/uniform_int_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/static_assert.hpp>
#include <boost/random/uniform_int_distribution.hpp>
#include <boost/type_traits/is_integral.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace random
{
namespace distribution
{

template<
	typename IntType
>
class uniform_int
{
	typedef boost::random::uniform_int_distribution<
		IntType
	> wrapped;
public:
	typedef IntType int_type;

	typedef typename wrapped::result_type result_type;

	BOOST_STATIC_ASSERT(
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

	uniform_int(
		min,
		max
	);

	FCPPT_RANDOM_DISTRIBUTION_DECLARE_CALL;
private:
	wrapped wrapped_;
};

}
}
}

#endif
