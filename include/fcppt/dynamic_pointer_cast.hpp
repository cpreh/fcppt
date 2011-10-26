//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_DYNAMIC_POINTER_CAST_HPP_INCLUDED
#define FCPPT_DYNAMIC_POINTER_CAST_HPP_INCLUDED

#include <fcppt/shared_ptr_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/smart_ptr/shared_ptr.hpp>
#include <fcppt/config/external_end.hpp>

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
dynamic_pointer_cast(
	shared_ptr<U, Deleter> const &_ptr
)
{
	return
		fcppt::shared_ptr<T, Deleter>(
			_ptr,
			boost::detail::dynamic_cast_tag()
		);
}

}

#endif
