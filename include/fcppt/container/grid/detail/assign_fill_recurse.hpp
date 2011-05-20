//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_GRID_DETAIL_ASSIGN_FILL_RECURSE_HPP_INCLUDED
#define FCPPT_CONTAINER_GRID_DETAIL_ASSIGN_FILL_RECURSE_HPP_INCLUDED

#include <fcppt/container/grid/size_type.hpp>
#include <boost/utility/enable_if.hpp>

namespace fcppt
{
namespace container
{
namespace grid
{
namespace detail
{

template<
	fcppt::container::grid::size_type Level,
	typename Object
>
typename boost::enable_if_c<
	Level == 0,
	void
>::type
assign_fill_recurse(
	Object &_result,
	Object const &_source,
	typename Object::const_reference _value,
	typename Object::dim const _pos,
	bool const _is_contained
)
{
	_result[_pos] =
		_is_contained
		?
			_source[_pos]
		:
			_value;
}

template<
	fcppt::container::grid::size_type Level,
	typename Object
>
typename boost::enable_if_c<
	Level != 0,
	void
>::type
assign_fill_recurse(
	Object &_result,
	Object const &_source,
	typename Object::const_reference _value,
	typename Object::dim _pos,
	bool const _is_contained
)
{
	size_type const index(
		Level - 1u
	);

	for(
		typename Object::dim::value_type i = 0;
		i < _result.size()[index];
		++i
	)
	{
		_pos[index] = i;

		detail::assign_fill_recurse<
			Level - 1u
		>(
			_result,
			_source,
			_value,
			_pos,
			_is_contained
			&& i < _source.size()[index]
		);
	}
}

}
}
}
}

#endif
