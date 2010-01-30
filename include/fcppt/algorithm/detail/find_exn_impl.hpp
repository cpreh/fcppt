//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALGORITHM_DETAIL_FIND_EXN_IMPL_HPP_INCLUDED
#define FCPPT_ALGORITHM_DETAIL_FIND_EXN_IMPL_HPP_INCLUDED

#include <fcppt/algorithm/element_not_found.hpp>
#include <algorithm>

template<
	typename In,
	typename T
>
In
fcppt::algorithm::find_exn(
	In const begin,
	In const end,
	T const &t)
{
	In const ret(
		std::find(
			begin,
			end,
			t
		)
	);

	if(ret == end)
		throw element_not_found();

	return ret;
}

#endif
