//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_VARIANT_APPLY_TERNARY_HPP_INCLUDED
#define FCPPT_VARIANT_APPLY_TERNARY_HPP_INCLUDED

#include <fcppt/variant/apply_binary.hpp>
#include <fcppt/variant/detail/ternary_unwrap.hpp>

namespace fcppt
{
namespace variant
{

template<
	typename Operation,
	typename Variant1,
	typename Variant2,
	typename Variant3
>
typename Operation::result_type
apply_ternary(
	Operation const &op,
	Variant1 const &obj1,
	Variant2 const &obj2,
	Variant3 const &obj3
)
{
	return apply_binary(
		detail::ternary_unwrap<
			Operation,
			Variant1
		>(
			op,
			obj1
		),
		obj2,
		obj3
	);
}

}
}

#endif
