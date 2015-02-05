//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALGORITHM_DETAIL_ARRAY_INIT_FUNCTION_HPP_INCLUDED
#define FCPPT_ALGORITHM_DETAIL_ARRAY_INIT_FUNCTION_HPP_INCLUDED

#include <fcppt/nonassignable.hpp>


namespace fcppt
{
namespace algorithm
{
namespace detail
{

template<
	typename Type
>
class array_init_function
{
	FCPPT_NONASSIGNABLE(
		array_init_function
	);
public:
	explicit
	array_init_function(
		Type const &_value
	)
	:
		value_(
			_value
		)
	{
	}

	template<
		typename Index
	>
	Type
	operator()(
		Index
	) const
	{
		return
			value_;
	}
private:
	Type const value_;
};

}
}
}

#endif
