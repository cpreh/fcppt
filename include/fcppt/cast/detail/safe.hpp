//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CAST_DETAIL_SAFE_HPP_INCLUDED
#define FCPPT_CAST_DETAIL_SAFE_HPP_INCLUDED

#include <fcppt/cast/safe_numeric.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/and.hpp>
#include <boost/utility/enable_if.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace cast
{
namespace detail
{

template<
	typename T,
	typename U
>
typename boost::disable_if<
	boost::mpl::and_<
		std::is_arithmetic<
			T
		>,
		std::is_arithmetic<
			U
		>
	>,
	T
>::type
safe(
	U const &_other
)
{
	return
		_other;
}

template<
	typename T,
	typename U
>
typename boost::enable_if<
	boost::mpl::and_<
		std::is_arithmetic<
			T
		>,
		std::is_arithmetic<
			U
		>
	>,
	T
>::type
safe(
	U const &_other
)
{
	return
		fcppt::cast::safe_numeric<
			T
		>(
			_other
		);
}

}
}
}

#endif
