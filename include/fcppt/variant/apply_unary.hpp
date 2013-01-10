//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_VARIANT_APPLY_UNARY_HPP_INCLUDED
#define FCPPT_VARIANT_APPLY_UNARY_HPP_INCLUDED

#include <fcppt/variant/detail/apply_unary_internal.hpp>
#include <fcppt/variant/detail/operation_wrapper.hpp>


namespace fcppt
{
namespace variant
{

/**
\brief Does a unary visitation

\ingroup fcpptvariant

Visits \a _obj with the visitor \a _op. <code>_op.operator()(T)</code> will be
called where <code>T</code> is the type held \a _obj.

\tparam Operation The visitor type
\tparam Variant The variant type

\param _op The visitor to execute
\param _obj The variant to visit

\return The result of <code>_op.operator()(T)</code>
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
		fcppt::variant::detail::apply_unary_internal(
			fcppt::variant::detail::operation_wrapper<
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
