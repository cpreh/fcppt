//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALGORITHM_DETAIL_COPY_N_IMPL_HPP_INCLUDED
#define FCPPT_ALGORITHM_DETAIL_COPY_N_IMPL_HPP_INCLUDED

#include <algorithm>

template<
	typename In,
	typename Out,
	typename Size
>
Out
fcppt::algorithm::copy_n(
	In const beg,
	Size const sz,
	Out const out)
{
	return std::copy(
		beg,
		beg + sz,
		out
	);
}

#endif
