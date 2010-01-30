//          Copyright Carl Philipp Reh 2009 - 2010.
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

template<
	typename Operation,
	typename Variant
>
typename Operation::result_type
apply_unary(
	Operation const &op,
	Variant const &obj
)
{
	return
		detail::apply_unary_internal(
			detail::operation_wrapper<
				Operation
			>(
				op
			),
			obj
		);
}

}
}

#endif
