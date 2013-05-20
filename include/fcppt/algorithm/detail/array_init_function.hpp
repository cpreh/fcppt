//          Copyright Carl Philipp Reh 2009 - 2013.
//          Copyright Philipp Middendorf 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALGORITHM_DETAIL_ARRAY_INIT_FUNCTION_HPP_INCLUDED
#define FCPPT_ALGORITHM_DETAIL_ARRAY_INIT_FUNCTION_HPP_INCLUDED

#include <fcppt/nonassignable.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstddef>
#include <fcppt/config/external_end.hpp>


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
		std::size_t Index
	>
	Type
	operator()() const
	{
		return value_;
	}
private:
	Type const value_;
};

}
}
}

#endif
