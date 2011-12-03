//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_VARIANT_APPLY_HPP_INCLUDED
#define FCPPT_VARIANT_APPLY_HPP_INCLUDED

#include <fcppt/variant/apply_binary.hpp>
#include <fcppt/variant/apply_ternary.hpp>
#include <fcppt/variant/apply_unary.hpp>


namespace fcppt
{
namespace variant
{

/**
\brief Forwards to fcppt::variant::apply_unary
*/
template<
	typename Operation,
	typename Variant
>
typename Operation::result_type
apply(
	Operation const &_op,
	Variant const &_obj
)
{
	return
		variant::apply_unary(
			_op,
			_obj
		);
}

/**
\brief Forwards to fcppt::variant::apply_binary
*/
template<
	typename Operation,
	typename Variant1,
	typename Variant2
>
typename Operation::result_type
apply(
	Operation const &_op,
	Variant1 const &_obj1,
	Variant2 const &_obj2
)
{
	return
		variant::apply_binary(
			_op,
			_obj1,
			_obj2
		);
}

/**
\brief Forwards to fcppt::variant::apply_ternary
*/
template<
	typename Operation,
	typename Variant1,
	typename Variant2,
	typename Variant3
>
typename Operation::result_type
apply(
	Operation const &_op,
	Variant1 const &_obj1,
	Variant2 const &_obj2,
	Variant3 const &_obj3
)
{
	return
		variant::apply_binary(
			_op,
			_obj1,
			_obj2,
			_obj3
		);
}

}
}

#endif
