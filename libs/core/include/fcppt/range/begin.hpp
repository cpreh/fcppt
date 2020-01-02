//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RANGE_BEGIN_HPP_INCLUDED
#define FCPPT_RANGE_BEGIN_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <iterator>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace range
{

/**
\brief Calls begin via ADL.

\ingroup fcpptrange
*/
template<
	typename Range
>
auto
begin(
	Range &_range
)
{
	using std::begin;

	return
		begin(
			_range
		);
}

}
}

#endif
