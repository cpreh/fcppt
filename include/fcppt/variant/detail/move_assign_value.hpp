//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_VARIANT_DETAIL_MOVE_ASSIGN_VALUE_HPP_INCLUDED
#define FCPPT_VARIANT_DETAIL_MOVE_ASSIGN_VALUE_HPP_INCLUDED

#include <fcppt/nonassignable.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/utility/enable_if.hpp>
#include <type_traits>
#include <utility>
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
class move_assign_value
{
	FCPPT_NONASSIGNABLE(
		move_assign_value
	);
public:
	explicit
	move_assign_value(
		Value &&_value
	)
	:
		value_(
			std::move(
				_value
			)
		)
	{
	}

	typedef void result_type;

	template<
		typename T
	>
	typename boost::enable_if<
		std::is_same<
			T,
			Value
		>,
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

		_left =
			std::move(
				value_
			);
	}

	template<
		typename T
	>
	typename boost::disable_if<
		std::is_same<
			T,
			Value
		>,
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
	Value &&value_;
};

}
}
}

#endif
