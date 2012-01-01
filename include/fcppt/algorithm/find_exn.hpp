//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALGORITHM_FIND_EXN_HPP_INCLUDED
#define FCPPT_ALGORITHM_FIND_EXN_HPP_INCLUDED

#include <fcppt/algorithm/element_not_found.hpp>
#include <fcppt/config/external_begin.hpp>
#include <algorithm>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace algorithm
{

/**
 * \brief Like std::find but throws fcppt::algorithm::element_not_found
 * \throws fcppt::algorithm::element_not_found If the element was not found
 * \ingroup fcpptalgorithm
 */
template<
	typename In,
	typename T
>
In
find_exn(
	In const begin,
	In const end,
	T const &t
)
{
	In const ret(
		::std::find(
			begin,
			end,
			t
		)
	);

	if(ret == end)
		throw algorithm::element_not_found();

	return ret;
}

}
}

#endif
