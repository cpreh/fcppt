//          Copyright Carl Philipp Reh 2009 - 2015.
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

/**
\brief Does a ternary visitation

\ingroup fcpptvariant

Visits \a _obj1, \a _obj2 and \a _obj3 with the visitor \a _op.
<code>_op.operator()(T, U, V)</code> will be called where <code>T</code> is the
type held by \a _obj1, <code>U</code> is the type held by \a _obj2 and
<code>V</code> is the type held by \a _obj3.

\tparam Operation The visitor type
\tparam Variant1 The first variant
\tparam Variant2 The the second variant
\tparam Variant3 The third variant

\param _op The visitor to execute
\param _obj1 The first variant to visit
\param _obj2 The second variant to visit
\param _obj3 The third variant to visit

\return The result of <code>_op.operator()(T, U, V)</code>
*/
template<
	typename Operation,
	typename Variant1,
	typename Variant2,
	typename Variant3
>
inline
decltype(
	auto
)
apply_ternary(
	Operation &&_op,
	Variant1 &&_obj1,
	Variant2 &&_obj2,
	Variant3 &&_obj3
)
{
	return
		fcppt::variant::apply_binary(
			fcppt::variant::detail::ternary_unwrap<
				Operation,
				Variant1
			>(
				_op,
				_obj1
			),
			_obj2,
			_obj3
		);
}

}
}

#endif
