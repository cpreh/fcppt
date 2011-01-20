//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_VARIANT_DETAIL_TERNARY_APPLIER_HPP_INCLUDED
#define FCPPT_VARIANT_DETAIL_TERNARY_APPLIER_HPP_INCLUDED

#include <fcppt/nonassignable.hpp>

namespace fcppt
{
namespace variant
{
namespace detail
{

template<
	typename Operation,
	typename Type2,
	typename Type3
>
class ternary_applier
{
	FCPPT_NONASSIGNABLE(
		ternary_applier
	)
public:
	typedef typename Operation::result_type result_type;

	ternary_applier(
		Operation const &_op,
		Type2 const &_t2,
		Type3 const &_t3
	)
	:
		op_(_op),
		t2_(_t2),
		t3_(_t3)
	{}

	template<
		typename T1
	>
	result_type
	operator()(
		T1 const &_t1
	) const
	{
		return
			op(
				_t1,
				t2_,
				t3_
			);
	}
private:
	Operation const &op_;

	Type2 const &t2_;

	Type3 const &t3_;
};

}
}
}

#endif
