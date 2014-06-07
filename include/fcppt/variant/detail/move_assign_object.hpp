//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_VARIANT_DETAIL_MOVE_ASSIGN_OBJECT_HPP_INCLUDED
#define FCPPT_VARIANT_DETAIL_MOVE_ASSIGN_OBJECT_HPP_INCLUDED

#include <fcppt/nonassignable.hpp>
#include <fcppt/config/external_begin.hpp>
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
	typename Variant
>
class move_assign_object
{
	FCPPT_NONASSIGNABLE(
		move_assign_object
	);
public:
	explicit
	move_assign_object(
		Variant &_left
	)
	:
		left_(
			_left
		)
	{
	}

	typedef void result_type;

	template<
		typename T
	>
	result_type
	operator()(
		T &&_other
	) const
	{
		left_. template get_unchecked<
			typename std::remove_reference<
				T
			>::type
		>() =
			std::move(
				_other
			);
	}
private:
	Variant &left_;
};

}
}
}

#endif
