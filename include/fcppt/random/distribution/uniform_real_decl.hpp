//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RANDOM_DISTRIBUTION_UNIFORM_REAL_DECL_HPP_INCLUDED
#define FCPPT_RANDOM_DISTRIBUTION_UNIFORM_REAL_DECL_HPP_INCLUDED

#include <fcppt/strong_typedef.hpp>
#include <fcppt/random/distribution/declare_call.hpp>
#include <fcppt/random/distribution/uniform_real_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/static_assert.hpp>
#include <boost/random/uniform_real_distribution.hpp>
#include <boost/type_traits/is_floating_point.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace random
{
namespace distribution
{

template<
	typename FloatType
>
class uniform_real
{
	typedef boost::random::uniform_real_distribution<
		FloatType
	> wrapped;
public:
	typedef FloatType float_type;

	typedef typename wrapped::result_type result_type;

	BOOST_STATIC_ASSERT(
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

	uniform_real(
		min,
		sup
	);

	FCPPT_RANDOM_DISTRIBUTION_DECLARE_CALL;
private:
	wrapped wrapped_;
};

}
}
}

#endif
