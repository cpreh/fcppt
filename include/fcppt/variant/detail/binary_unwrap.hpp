//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_VARIANT_DETAIL_BINARY_UNWRAP_HPP_INCLUDED
#define FCPPT_VARIANT_DETAIL_BINARY_UNWRAP_HPP_INCLUDED

#include <fcppt/variant/apply_unary.hpp>
#include <fcppt/variant/detail/binary_applier.hpp>
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
class binary_unwrap
{
	FCPPT_NONASSIGNABLE(binary_unwrap)
public:
	typedef typename Operation::result_type result_type;

	binary_unwrap(
		Operation const &op,
		Variant const &obj
	)
	:
		op(op),
		obj(obj)
	{}

	template<
		typename T2
	>
	result_type
	operator()(
		T2 const &t2
	) const
	{
		return apply_unary(
			binary_applier<
				Operation,
				T2
			>(
				op,
				t2
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
