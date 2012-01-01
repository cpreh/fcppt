//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RANDOM_LAST_EXCLUSIVE_RANGE_IMPL_HPP_INCLUDED
#define FCPPT_RANDOM_LAST_EXCLUSIVE_RANGE_IMPL_HPP_INCLUDED

#include <fcppt/text.hpp>
#include <fcppt/random/exclusive_range_error.hpp>
#include <fcppt/random/last_exclusive_range_decl.hpp>
#include <fcppt/random/range_impl.hpp>


template<
	typename T
>
fcppt::random::last_exclusive_range<T>::last_exclusive_range(
	T const &_first,
	T const &_last
)
:
	range<
		T
	>(
		_first,
		_last - static_cast<T>(1)
	)
{
	if(_first == _last)
		throw random::exclusive_range_error(
			FCPPT_TEXT("last_exclusive_range empty!")
		);
}

#endif
