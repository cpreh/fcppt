//          Copyright Carl Philipp Reh 2009 - 2011.
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
/** Equivalent to std::copy(_beg, _beg + _sz, _out)
*/
template<
	typename In,
	typename Out,
	typename Size
>
Out
copy_n(
	In const _beg,
	Size const _sz,
	Out const _out
)
{
	return
		::std::copy(
			_beg,
			_beg + _sz,
			_out
		);
}

}
}

#endif
