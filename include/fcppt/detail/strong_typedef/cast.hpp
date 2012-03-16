//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_DETAIL_STRONG_TYPEDEF_CAST_HPP_INCLUDED
#define FCPPT_DETAIL_STRONG_TYPEDEF_CAST_HPP_INCLUDED

#include <fcppt/safe_cast.hpp>


namespace fcppt
{
namespace detail
{

template<
	typename T,
	typename U
>
T
strong_typedef_cast(
	U const &_other
)
{
	return
		fcppt::safe_cast<
			T
		>(
			_other
		);
}

}
}

#endif
