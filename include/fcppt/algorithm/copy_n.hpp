//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALGORITHM_COPY_N_HPP_INCLUDED
#define FCPPT_ALGORITHM_COPY_N_HPP_INCLUDED

#include <algorithm>

namespace fcppt
{
namespace algorithm
{

/// Copies sz elements from beg to out
/** Equivalent to copy(beg, beg + sz, out)
*/
template<
	typename In,
	typename Out,
	typename Size
>
Out
copy_n(
	In const beg,
	Size const sz,
	Out const out
)
{
	return
		std::copy(
			beg,
			beg + sz,
			out
		);
}

}
}

#endif
