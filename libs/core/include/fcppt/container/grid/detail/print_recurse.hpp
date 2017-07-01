//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_GRID_DETAIL_PRINT_RECURSE_HPP_INCLUDED
#define FCPPT_CONTAINER_GRID_DETAIL_PRINT_RECURSE_HPP_INCLUDED

#include <fcppt/make_int_range_count.hpp>
#include <fcppt/container/grid/object_impl.hpp>
#include <fcppt/container/grid/size_type.hpp>
#include <fcppt/math/dim/at_c.hpp>
#include <fcppt/math/vector/at_c.hpp>
#include <fcppt/config/external_begin.hpp>
#include <ostream>
#include <type_traits>
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
	typename Ch,
	typename Traits,
	typename Type,
	fcppt::container::grid::size_type Size,
	typename Alloc
>
typename
std::enable_if<
	Level == 0,
	void
>::type
print_recurse(
	std::basic_ostream<
		Ch,
		Traits
	> &_stream,
	fcppt::container::grid::object<
		Type,
		Size,
		Alloc
	> const &_object,
	typename
	fcppt::container::grid::object<
		Type,
		Size,
		Alloc
	>::pos const _pos
)
{
	_stream
		<<
		_object.get_unsafe(
			_pos
		);
}

template<
	fcppt::container::grid::size_type Level,
	typename Ch,
	typename Traits,
	typename Type,
	fcppt::container::grid::size_type Size,
	typename Alloc
>
typename
std::enable_if<
	Level != 0,
	void
>::type
print_recurse(
	std::basic_ostream<
		Ch,
		Traits
	> &_stream,
	fcppt::container::grid::object<
		Type,
		Size,
		Alloc
	> const &_object,
	typename
	fcppt::container::grid::object<
		Type,
		Size,
		Alloc
	>::pos _pos
)
{
	constexpr size_type const index(
		Level - 1u
	);

	_stream
		<< _stream.widen('(');

	typedef
	typename
	fcppt::container::grid::object<
		Type,
		Size,
		Alloc
	>::dim::value_type
	dim_value_type;

	dim_value_type const sz{
		fcppt::math::dim::at_c<
			index
		>(
			_object.size()
		)
	};

	for(
		dim_value_type const i
		:
		fcppt::make_int_range_count(
			sz
		)
	)
	{
		fcppt::math::vector::at_c<
			index
		>(
			_pos
		) =
			i;

		fcppt::container::grid::detail::print_recurse<
			index
		>(
			_stream,
			_object,
			_pos
		);

		if(
			i < sz - 1u
		)
			_stream
				<< _stream.widen(',');
	}

	_stream
		<< _stream.widen(')');
}

}
}
}
}

#endif
