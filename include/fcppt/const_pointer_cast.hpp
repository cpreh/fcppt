//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONST_POINTER_CAST_HPP_INCLUDED
#define FCPPT_CONST_POINTER_CAST_HPP_INCLUDED

#include <fcppt/shared_ptr_impl.hpp>

namespace fcppt
{

template<
	typename T,
	typename U,
	template<
		typename
	> class Deleter
>
shared_ptr<T, Deleter> const
const_pointer_cast(
	shared_ptr<U, Deleter> const &r
)
{
	return
		fcppt::shared_ptr<T, Deleter>(
			r,
			boost::detail::const_cast_tag()
		);
}

}

#endif
