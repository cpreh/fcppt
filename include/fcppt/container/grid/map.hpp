//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_GRID_MAP_HPP_INCLUDED
#define FCPPT_CONTAINER_GRID_MAP_HPP_INCLUDED

#include <fcppt/move_if_rvalue.hpp>
#include <fcppt/container/grid/is_object.hpp>
#include <fcppt/container/grid/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace container
{
namespace grid
{

/**
\brief Maps over grids

\ingroup fcpptcontainergrid

For every element <code>x</code> at position <code>p</code> in \a _source, the
result of <code>_function(x)</code> is inserted at <code>p</code> into the
result.

\tparam Function A function callable as <code>Result::value_type (Source::value_type)</code>
*/
template<
	// TODO: We don't need Result here
	typename Result,
	typename Source,
	typename Function
>
Result
map(
	Source &&_source,
	Function const &_function
)
{
	static_assert(
		fcppt::container::grid::is_object<
			Result
		>::value,
		"Result must be a grid"
	);

	typedef
	typename
	std::decay<
		Source
	>::type
	source_type;

	static_assert(
		fcppt::container::grid::is_object<
			source_type
		>::value,
		"Source must be a grid"
	);

	return
		Result(
			_source.size(),
			[
				&_source,
				&_function
			](
				typename
				source_type::pos const _pos
			)
			{
				return
					_function(
						fcppt::move_if_rvalue<
							Source
						>(
							_source[
								_pos
							]
						)
					);
			}
		);
}

}
}
}

#endif
