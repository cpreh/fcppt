//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_SIZE_HPP_INCLUDED
#define FCPPT_CONTAINER_SIZE_HPP_INCLUDED

#include <fcppt/container/size_result_type.hpp>
#include <fcppt/container/detail/size.hpp>


namespace fcppt
{
namespace container
{

/**
\brief The size of a range.

\ingroup fcpptcontainer

Uses <code>size()</code> if possible, otherwise calculates
the distance from begin to end.

\tparam Range Must be a range that either has begin/end or size and size_type.
*/
template<
	typename Range
>
inline
fcppt::container::size_result_type<
	Range
>
size(
	Range const &_range
)
{
	return
		static_cast<
			fcppt::container::size_result_type<
				Range
			>
		>(
			fcppt::container::detail::size(
				_range
			)
		);
}

}
}

#endif
