//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DETAIL_ONE_DIMENSIONAL_INPUT_HPP_INCLUDED
#define FCPPT_MATH_DETAIL_ONE_DIMENSIONAL_INPUT_HPP_INCLUDED

#include <fcppt/make_int_range_count.hpp>
#include <fcppt/config/external_begin.hpp>
#include <ios>
#include <istream>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace math
{
namespace detail
{

template<
	typename Ch,
	typename Traits,
	typename Type
>
std::basic_istream<
	Ch,
	Traits
> &
one_dimensional_input(
	std::basic_istream<
		Ch,
		Traits
	> &_stream,
	Type &_value
)
{
	Ch temp;

	_stream >>
		temp;

	if(
		temp
		!=
		_stream.widen('(')
	)
	{
		_stream.setstate(
			std::ios_base::failbit
		);

		return
			_stream;
	}

	for(
		auto const index
		:
		fcppt::make_int_range_count(
			Type::static_size::value
		)
	)
	{
		if(
			!(
				_stream >>
					_value[
						index
					]
			)
		)
			return
				_stream;

		if(
			index
			!=
			Type::static_size::value
			-
			1u
		)
		{
			_stream >>
				temp;

			if(
				temp
				!=
				_stream.widen(',')
			)
			{
				_stream.setstate(
					std::ios_base::failbit
				);

				return
					_stream;
			}
		}
	}

	_stream >>
		temp;

	if(
		temp
		!=
		_stream.widen(')')
	)
		_stream.setstate(
			std::ios_base::failbit
		);

	return
		_stream;
}

}
}
}

#endif
