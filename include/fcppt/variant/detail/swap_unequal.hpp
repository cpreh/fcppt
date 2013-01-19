//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_VARIANT_DETAIL_SWAP_UNEQUAL_HPP_INCLUDED
#define FCPPT_VARIANT_DETAIL_SWAP_UNEQUAL_HPP_INCLUDED

#include <fcppt/nonassignable.hpp>
#include <fcppt/config/external_begin.hpp>
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
class swap_unequal
{
	FCPPT_NONASSIGNABLE(
		swap_unequal
	);
public:
	swap_unequal(
		Variant &_left,
		Variant &_right
	)
	:
		left_(
			_left
		),
		right_(
			_right
		)
	{
	}

	typedef void result_type;

	template<
		typename Type1,
		typename Type2
	>
	result_type
	operator()(
		Type1 &_left,
		Type2 &_right
	) const
	{
		Type1 temp(
			std::move(
				_left
			)
		);

		left_ =
			std::move(
				_right
			);

		right_ =
			std::move(
				temp
			);
	}
private:
	Variant &left_;

	Variant &right_;
};

}
}
}

#endif
