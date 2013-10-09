//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALGORITHM_ARRAY_PUSH_BACK_HPP_INCLUDED
#define FCPPT_ALGORITHM_ARRAY_PUSH_BACK_HPP_INCLUDED

#include <fcppt/algorithm/array_fold_static.hpp>
#include <fcppt/algorithm/detail/array_push_back_function.hpp>
#include <fcppt/config/external_begin.hpp>
#include <array>
#include <cstddef>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace algorithm
{

/**
\brief Pushes a new element to the back of an array

\ingroup fcpptalgorithm

Pushes \a _element to the back of \a _source.
*/
template
<
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
		fcppt::algorithm::array_fold_static<
			dest_array
		>(
			fcppt::algorithm::detail::array_push_back_function<
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
