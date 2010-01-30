//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_VARIANT_DETAIL_TERNARY_APPLIER_HPP_INCLUDED
#define FCPPT_VARIANT_DETAIL_TERNARY_APPLIER_HPP_INCLUDED

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
struct ternary_applier
{
	typedef typename Operation::result_type result_type;

	ternary_applier(
		Operation const &op,
		Type2 const &t2,
		Type3 const &t3
	)
	:
		op(op),
		t2(t2),
		t3(t3)
	{}

	template<
		typename T1
	>
	result_type
	operator()(
		T1 const &t1
	) const
	{
		return op(
			t1,
			t2,
			t3
		);
	}
private:
	Operation const &op;
	Type2 const &t2;
	Type3 const &t3;
};

}
}
}

#endif
