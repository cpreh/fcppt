//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_VARIANT_DETAIL_TERNARY_UNWRAP_HPP_INCLUDED
#define FCPPT_VARIANT_DETAIL_TERNARY_UNWRAP_HPP_INCLUDED

#include <fcppt/variant/apply_unary.hpp>
#include <fcppt/variant/detail/ternary_applier.hpp>
#include <fcppt/nonassignable.hpp>

namespace fcppt
{
namespace variant
{
namespace detail
{

template<
	typename Operation,
	typename Variant
>
class ternary_unwrap
{
	FCPPT_NONASSIGNABLE(
		ternary_unwrap
	)
public:
	typedef typename Operation::result_type result_type;

	ternary_unwrap(
		Operation const &op,
		Variant const &obj
	)
	:
		op(op),
		obj(obj)
	{}

	template<
		typename T2,
		typename T3
	>
	result_type
	operator()(
		T2 const &t2,
		T3 const &t3
	) const
	{
		return apply_unary(
			ternary_applier<
				Operation,
				T2,
				T3
			>(
				op,
				t2,
				t3
			),
			obj
		);
	}
private:
	Operation const &op;
	Variant const &obj;
};

}
}
}

#endif
