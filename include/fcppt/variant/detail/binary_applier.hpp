//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_VARIANT_DETAIL_BINARY_APPLIER_HPP_INCLUDED
#define FCPPT_VARIANT_DETAIL_BINARY_APPLIER_HPP_INCLUDED

#include <fcppt/nonassignable.hpp>

namespace fcppt
{
namespace variant
{
namespace detail
{

template<
	typename Operation,
	typename Type
>
class binary_applier
{
	FCPPT_NONASSIGNABLE(
		binary_applier
	);
public:
	typedef typename Operation::result_type result_type;

	binary_applier(
		Operation const &_op,
		Type &_t2
	)
	:
		op_(_op),
		t2_(_t2)
	{}

	template<
		typename T
	>
	result_type
	operator()(
		T &_t1
	) const
	{
		return
			op_(
				_t1,
				t2_
			);
	}
private:
	Operation const &op_;

	Type &t2_;
};

}
}
}

#endif
