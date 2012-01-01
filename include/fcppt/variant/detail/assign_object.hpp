//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_VARIANT_DETAIL_ASSIGN_OBJECT_HPP_INCLUDED
#define FCPPT_VARIANT_DETAIL_ASSIGN_OBJECT_HPP_INCLUDED

#include <fcppt/nonassignable.hpp>


namespace fcppt
{
namespace variant
{
namespace detail
{

template<
	typename Variant
>
class assign_object
{
	FCPPT_NONASSIGNABLE(
		assign_object
	);
public:
	explicit assign_object(
		Variant &_left
	)
	:
		left_(_left)
	{
	}

	typedef void result_type;

	template<
		typename T
	>
	result_type
	operator()(
		T const &_other
	) const
	{
		left_. template get_raw<
			T
		>() =
			_other;
	}
private:
	Variant &left_;
};

}
}
}

#endif
