//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALGORITHM_DETAIL_PTR_CONTAINER_ERASE_PRED_HPP_INCLUDED
#define FCPPT_ALGORITHM_DETAIL_PTR_CONTAINER_ERASE_PRED_HPP_INCLUDED

#include <fcppt/nonassignable.hpp>


namespace fcppt
{
namespace algorithm
{
namespace detail
{

template<
	typename Pointer
>
class ptr_container_erase_pred
{
	FCPPT_NONASSIGNABLE(
		ptr_container_erase_pred
	);
public:
	explicit ptr_container_erase_pred(
		Pointer const _pointer
	)
	:
		pointer_(
			_pointer
		)
	{
	}

	template<
		typename Ref
	>
	bool
	operator()(
		Ref _other
	) const
	{
		return pointer_ == &_other;
	}
private:
	Pointer const pointer_;
};

}
}
}

#endif
