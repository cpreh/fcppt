//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_GRID_DETAIL_ASSIGN_RECURSE_HPP_INCLUDED
#define FCPPT_CONTAINER_GRID_DETAIL_ASSIGN_RECURSE_HPP_INCLUDED

#include <fcppt/container/grid/size_type.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/utility/enable_if.hpp>
#include <algorithm>
#include <fcppt/config/external_end.hpp>

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
assign_recurse(
	Object &_result,
	Object const &_source,
	typename Object::dim const _pos
)
{
	_result[_pos] = _source[_pos];
}

template<
	fcppt::container::grid::size_type Level,
	typename Object
>
typename boost::enable_if_c<
	Level != 0,
	void
>::type
assign_recurse(
	Object &_result,
	Object const &_source,
	typename Object::dim _pos
)
{
	size_type const index(
		Level - 1u
	);

	typename Object::dim::value_type sz(
		std::min(
			_result.size()[index],
			_source.size()[index]
		)
	);

	for(
		typename Object::dim::size_type i = 0;
		i < sz;
		++i
	)
	{
		_pos[index] = i;

		detail::assign_recurse<
			Level - 1u
		>(
			_result,
			_source,
			_pos
		);
	}
}

}
}
}
}

#endif
