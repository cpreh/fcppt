//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_ARRAY_PUSH_BACK_HPP_INCLUDED
#define FCPPT_CONTAINER_ARRAY_PUSH_BACK_HPP_INCLUDED

#include <fcppt/container/array_init.hpp>
#include <fcppt/container/detail/array_push_back_function.hpp>
#include <fcppt/config/external_begin.hpp>
#include <array>
#include <cstddef>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace container
{

/**
\brief Pushes a new element to the back of an array.

\ingroup fcpptcontainer

Pushes \a _element to the back of \a _source.
*/
template<
	typename SourceType,
	std::size_t SourceCount
>
std::array<
	SourceType,
	SourceCount + 1u
>
array_push_back(
	std::array<
		SourceType,
		SourceCount
	> const &_source,
	SourceType const &_element
)
{
	typedef
	std::array<
		SourceType,
		SourceCount
	>
	source_array;

	typedef
	std::array<
		SourceType,
		SourceCount + 1u
	>
	dest_array;

	return
		fcppt::container::array_init<
			dest_array
		>(
			fcppt::container::detail::array_push_back_function<
				source_array
			>(
				_source,
				_element
			)
		);
}

}
}

#endif
