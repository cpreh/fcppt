//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_SN_CAST_HPP_INCLUDED
#define FCPPT_SN_CAST_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/and.hpp>
#include <boost/mpl/greater_equal.hpp>
#include <boost/mpl/or.hpp>
#include <boost/mpl/sizeof.hpp>
#include <boost/type_traits/is_floating_point.hpp>
#include <boost/type_traits/is_integral.hpp>
#include <boost/utility/enable_if.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{

/// safe_numeric_cast is a safer static_cast that forbids some lossy conversions
/**
 * The size of the destination type must be at least as big as the source type's size.
 * Conversions from integral types to floating point types are allowed.
 * Conversions from floating point types to floating point types and
 * conversions from integral types to integral types are also allowed.
*/
template<
	typename T,
	typename U
>
typename boost::enable_if<
	boost::mpl::and_<
		boost::mpl::greater_equal<
			boost::mpl::sizeof_<
				T
			>,
			boost::mpl::sizeof_<
				U
			>
		>,
		boost::mpl::or_<
			boost::mpl::and_<
				boost::is_floating_point<
					T
				>,
				boost::is_floating_point<
					U
				>
			>,
			boost::mpl::and_<
				boost::is_floating_point<
					T
				>,
				boost::is_integral<
					U
				>
			>,
			boost::mpl::and_<
				boost::is_integral<
					T
				>,
				boost::is_integral<
					U
				>
			>
		>
	>,
	T
>::type
sn_cast(
	U const &u
)
{
	return static_cast<
		T
	>(
		u
	);
}

}

#endif
