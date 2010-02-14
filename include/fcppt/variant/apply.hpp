//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_VARIANT_APPLY_HPP_INCLUDED
#define FCPPT_VARIANT_APPLY_HPP_INCLUDED

#include <fcppt/variant/apply_unary.hpp>
#include <fcppt/variant/apply_binary.hpp>
#include <fcppt/variant/apply_ternary.hpp>

namespace fcppt
{
namespace variant
{

template<
	typename Operation,
	typename Variant
>
typename Operation::result_type
apply(
	Operation const &op,
	Variant const &obj
)
{
	return apply_unary(
		op,
		obj
	);
}

template<
	typename Operation,
	typename Variant1,
	typename Variant2
>
typename Operation::result_type
apply(
	Operation const &op,
	Variant1 const &obj1,
	Variant2 const &obj2
)
{
	return apply_binary(
		op,
		obj1,
		obj2
	);
}

template<
	typename Operation,
	typename Variant1,
	typename Variant2,
	typename Variant3
>
typename Operation::result_type
apply(
	Operation const &op,
	Variant1 const &obj1,
	Variant2 const &obj2,
	Variant3 const &obj3
)
{
	return apply_binary(
		op,
		obj1,
		obj2,
		obj3
	);
}

}
}

#endif
