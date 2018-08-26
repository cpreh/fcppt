//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_VARIANT_APPLY_UNARY_HPP_INCLUDED
#define FCPPT_VARIANT_APPLY_UNARY_HPP_INCLUDED

#include <fcppt/absurd.hpp>
#include <fcppt/move_if_rvalue.hpp>
#include <fcppt/use.hpp>
#include <fcppt/brigand/runtime_index.hpp>
#include <fcppt/type_traits/remove_cv_ref_t.hpp>
#include <fcppt/variant/is_object.hpp>
#include <fcppt/variant/types_of.hpp>
#include <fcppt/variant/detail/get_unsafe.hpp>
#include <fcppt/config/external_begin.hpp>
#include <brigand/sequences/at.hpp>
#include <brigand/sequences/front.hpp>
#include <brigand/sequences/size.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace variant
{

/**
\brief Passes the contents of a variant to a polymorphic function.

\ingroup fcpptvariant

Calls <code>_op.operator()(T)</code> where <code>T</code> is the type held \a _obj.

\tparam Operation A polymorphic function that can accept any type of \a Variant

\tparam Variant Must be an fcppt::variant::object
*/
template<
	typename Operation,
	typename Variant
>
decltype(
	auto
)
apply_unary(
	Operation &&_op,
	Variant &&_obj
)
{
	typedef
	fcppt::type_traits::remove_cv_ref_t<
		Variant
	>
	variant_type;

	static_assert(
		fcppt::variant::is_object<
			variant_type
		>::value,
		"Variant must be a variant::object"
	);

	typedef
	fcppt::variant::types_of<
		variant_type
	>
	types;

	return
		fcppt::brigand::runtime_index<
			::brigand::size<
				types
			>
		>(
			_obj.type_index(),
			[
				&_op,
				&_obj
			](
				auto const _index_value
			)
			->
			decltype(
				auto
			)
			{
				FCPPT_USE(
					_index_value
				);

				return
					_op(
						fcppt::move_if_rvalue<
							Variant
						>(
							fcppt::variant::detail::get_unsafe<
								::brigand::at<
									types,
									decltype(
										_index_value
									)
								>
							>(
								_obj
							)
						)
					);
			},
			&fcppt::absurd<
				decltype(
					_op(
						fcppt::move_if_rvalue<
							Variant
						>(
							fcppt::variant::detail::get_unsafe<
								::brigand::front<
									types
								>
							>(
								_obj
							)
						)
					)
				)
			>
		);
}

}
}

#endif
