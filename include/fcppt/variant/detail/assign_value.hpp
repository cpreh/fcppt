//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_VARIANT_DETAIL_ASSIGN_VALUE_HPP_INCLUDED
#define FCPPT_VARIANT_DETAIL_ASSIGN_VALUE_HPP_INCLUDED

#include <fcppt/nonassignable.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace variant
{
namespace detail
{

template<
	typename Value
>
class assign_value
{
	FCPPT_NONASSIGNABLE(
		assign_value
	);
public:
	explicit
	assign_value(
		Value const &_value
	)
	:
		value_(
			_value
		)
	{
	}

	typedef void result_type;

	template<
		typename T
	>
	typename std::enable_if<
		std::is_same<
			T,
			Value
		>::value,
		result_type
	>::type
	operator()(
		T &_left
	) const
	{
		static_assert(
			!std::is_const<
				T
			>::value,
			"T must be not const"
		);

		_left = value_;
	}

	template<
		typename T
	>
	typename std::enable_if<
		!std::is_same<
			T,
			Value
		>::value,
		result_type
	>::type
	operator()(
		T &
	) const
	{
		static_assert(
			!std::is_const<
				T
			>::value,
			"T must be not const"
		);
	}
private:
	Value const &value_;
};

}
}
}

#endif
