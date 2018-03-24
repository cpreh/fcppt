//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_VARIANT_APPLY_BINARY_HPP_INCLUDED
#define FCPPT_VARIANT_APPLY_BINARY_HPP_INCLUDED

#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/type_traits/remove_cv_ref_t.hpp>
#include <fcppt/variant/apply_unary.hpp>
#include <fcppt/variant/is_object.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace variant
{

/**
\brief Passes the contents of two variants to a polymorphic function.

\ingroup fcpptvariant

Calls <code>_op.operator()(T,U)</code> where <code>T</code> is the type held by
\a _obj1 and <code>U</code> is the type held by \a _obj2.

\tparam Operation A polymorphic binary function

\tparam Variant1 Must be an fcppt::variant::object
\tparam Variant2 Must be an fcppt::variant::object
*/
template<
	typename Operation,
	typename Variant1,
	typename Variant2
>
inline
decltype(
	auto
)
apply_binary(
	Operation &&_op,
	Variant1 &&_obj1,
	Variant2 &&_obj2
)
{
	static_assert(
		fcppt::variant::is_object<
			fcppt::type_traits::remove_cv_ref_t<
				Variant1
			>
		>::value,
		"Variant1 must be a variant::object"
	);

	static_assert(
		fcppt::variant::is_object<
			fcppt::type_traits::remove_cv_ref_t<
				Variant2
			>
		>::value,
		"Variant2 must be a variant::object"
	);

	return
		fcppt::variant::apply_unary(
			[
				&_obj1,
				&_op
			](
				auto &&_t2
			)
			->
			decltype(
				auto
			)
			{
FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Wattributes)
				return
					fcppt::variant::apply_unary(
						[
							&_op,
							&_t2
						](
							auto &&_t1
						)
						->
						decltype(
							auto
						)
						{
							return
								_op(
									std::forward<
										decltype(
											_t1
										)
									>(
										_t1
									),
									std::forward<
										decltype(
											_t2
										)
									>(
										_t2
									)
								);
						},
						std::forward<
							Variant1
						>(
							_obj1
						)
					);
FCPPT_PP_POP_WARNING
			},
			std::forward<
				Variant2
			>(
				_obj2
			)
		);
}

}
}

#endif
