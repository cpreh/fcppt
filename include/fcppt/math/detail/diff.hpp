//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DETAIL_DIFF_HPP_INCLUDED
#define FCPPT_MATH_DETAIL_DIFF_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <boost/type_traits/is_unsigned.hpp>
#include <boost/utility/enable_if.hpp>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace math
{
namespace detail
{

template<
	typename T
>
inline
typename boost::disable_if<
	boost::is_unsigned<
		T
	>,
	T
>::type
diff(
	T const &a,
	T const &b
)
{
	return
		std::abs(
			a - b
		);
}

template<
	typename T
>
inline
typename boost::enable_if<
	boost::is_unsigned<
		T
	>,
	T
>::type
diff(
	T const &a,
	T const &b
)
{
	return
		std::min(
			a - b,
			b - a
		);
}

}
}
}

#endif
