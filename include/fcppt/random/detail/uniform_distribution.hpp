//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RANDOM_DETAIL_UNIFORM_DISTRIBUTION_HPP_INCLUDED
#define FCPPT_RANDOM_DETAIL_UNIFORM_DISTRIBUTION_HPP_INCLUDED

#include <boost/random/uniform_real.hpp>
#include <boost/random/uniform_int.hpp>
#include <boost/utility/enable_if.hpp>
#include <boost/type_traits/is_floating_point.hpp>
#include <boost/type_traits/is_integral.hpp>

namespace fcppt
{
namespace random
{
namespace detail
{

template<
	typename T,
	typename Enable = void
>
struct uniform_distribution;

template<
	typename T
>
struct uniform_distribution<
	T,
	typename boost::enable_if<
		boost::is_floating_point<
			T
		>
	>::type
>
{
	typedef boost::uniform_real<T> type;
};

template<
	typename T
>
struct uniform_distribution<
	T,
	typename boost::enable_if<
		boost::is_integral<
			T
		>
	>::type
>
{
	typedef boost::uniform_int<T> type;
};

}
}
}

#endif
