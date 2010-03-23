//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_VARIANT_APPLY_BINARY_HPP_INCLUDED
#define FCPPT_VARIANT_APPLY_BINARY_HPP_INCLUDED

#include <fcppt/variant/apply_unary.hpp>
#include <fcppt/variant/detail/binary_unwrap.hpp>

namespace fcppt
{
namespace variant
{

/// Does a binary visitation with operation @a op
/**
 * This will call @a op::operator()(t1, t2)
 * where t1 and t2 are the objects held by @a obj1 and @a obj2 respectively
 * @return The result of @a op::operator().
*/
template<
	typename Operation,
	typename Variant1,
	typename Variant2
>
typename Operation::result_type
apply_binary(
	Operation const &op,
	Variant1 const &obj1,
	Variant2 const &obj2
)
{
	return apply_unary(
		detail::binary_unwrap<
			Operation,
			Variant1
		>(
			op,
			obj1
		),
		obj2
	);
}

}
}

#endif
