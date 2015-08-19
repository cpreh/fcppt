//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DETAIL_INIT_FUNCTION_HPP_INCLUDED
#define FCPPT_MATH_DETAIL_INIT_FUNCTION_HPP_INCLUDED

#include <fcppt/nonassignable.hpp>
#include <fcppt/cast/size.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstddef>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace math
{
namespace detail
{

template<
	typename SizeType,
	typename Function
>
class init_function
{
	FCPPT_NONASSIGNABLE(
		init_function
	);
public:
	explicit
	init_function(
		Function const &_function
	)
	:
		function_(
			_function
		)
	{
	}

	typename
	std::result_of<
		Function(
			SizeType
		)
	>::type
	operator()(
		std::size_t const _index
	) const
	{
		return
			function_(
				fcppt::cast::size<
					SizeType
				>(
					_index
				)
			);
	}
private:
	Function const function_;
};

}
}
}

#endif
