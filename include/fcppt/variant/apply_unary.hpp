//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_VARIANT_APPLY_UNARY_HPP_INCLUDED
#define FCPPT_VARIANT_APPLY_UNARY_HPP_INCLUDED

#include <fcppt/variant/detail/operation_wrapper.hpp>
#include <fcppt/variant/detail/apply_unary_internal.hpp>

namespace fcppt
{
namespace variant
{

/// Does a unary visitation with operation @a _op
/**
 * This will call @a _op::operator()(t)
 * where t is the object held by @a _obj 
 * @return The result of @a _op::operator().
*/
template<
	typename Operation,
	typename Variant
>
typename Operation::result_type
apply_unary(
	Operation const &_op,
	Variant const &_obj
)
{
	return
		detail::apply_unary_internal(
			detail::operation_wrapper<
				Operation
			>(
				_op
			),
			_obj
		);
}

}
}

#endif
