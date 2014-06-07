//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALGORITHM_REPEAT_HPP_INCLUDED
#define FCPPT_ALGORITHM_REPEAT_HPP_INCLUDED

#include <fcppt/literal.hpp>


namespace fcppt
{
namespace algorithm
{

template<
	typename Count,
	typename Function
>
void
repeat(
	Count const _count,
	Function const &_function
)
{
	for(
		Count index(
			fcppt::literal<
				Count
			>(
				0
			)
		);
		index < _count;
		++index
	)
		_function();
}

}
}

#endif
