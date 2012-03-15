//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_DETAIL_SAFE_CAST_HPP_INCLUDED
#define FCPPT_DETAIL_SAFE_CAST_HPP_INCLUDED

#include <fcppt/safe_numeric_cast.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/and.hpp>
#include <boost/type_traits/is_arithmetic.hpp>
#include <boost/utility/enable_if.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace detail
{

template<
	typename T,
	typename U
>
typename boost::disable_if<
	boost::mpl::and_<
		boost::is_arithmetic<
			T
		>,
		boost::is_arithmetic<
			U
		>
	>,
	T
>::type
safe_cast(
	U const &_other
)
{
	return _other;
}

template<
	typename T,
	typename U
>
typename boost::enable_if<
	boost::mpl::and_<
		boost::is_arithmetic<
			T
		>,
		boost::is_arithmetic<
			U
		>
	>,
	T
>::type
safe_cast(
	U const &_other
)
{
	return
		fcppt::safe_numeric_cast<
			T
		>(
			_other
		);
}

}
}

#endif
