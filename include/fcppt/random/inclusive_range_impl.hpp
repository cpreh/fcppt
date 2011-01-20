//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RANDOM_INCLUSIVE_RANGE_IMPL_HPP_INCLUDED
#define FCPPT_RANDOM_INCLUSIVE_RANGE_IMPL_HPP_INCLUDED

#include <fcppt/random/inclusive_range_decl.hpp>
#include <fcppt/random/range_impl.hpp>

template<
	typename T
>
fcppt::random::inclusive_range<T>::inclusive_range(
	T const &_first,
	T const &_last
)
:
	range<
		T
	>(
		_first,
		_last
	)
{}

#endif
