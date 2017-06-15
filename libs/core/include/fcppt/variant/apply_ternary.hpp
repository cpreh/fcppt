//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_VARIANT_APPLY_TERNARY_HPP_INCLUDED
#define FCPPT_VARIANT_APPLY_TERNARY_HPP_INCLUDED

#include <fcppt/variant/apply_binary.hpp>
#include <fcppt/variant/apply_unary.hpp>
#include <fcppt/variant/is_object.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace variant
{

/**
\brief Passes the contents of three variants to a polymorphic function.

\ingroup fcpptvariant

Calls <code>_op.operator()(T, U, V)</code> where <code>T</code> is the type
held by \a _obj1, <code>U</code> is the type held by \a _obj2 and
<code>V</code> is the type held by \a _obj3.

\tparam Operation A polymorphic ternary function

\tparam Variant1 Must be an fcppt::variant::object
\tparam Variant2 Must be an fcppt::variant::object
\tparam Variant3 Must be an fcppt::variant::object
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
	static_assert(
		fcppt::variant::is_object<
			typename
			std::decay<
				Variant1
			>::type
		>::value,
		"Variant1 must be a variant::object"
	);

	static_assert(
		fcppt::variant::is_object<
			typename
			std::decay<
				Variant2
			>::type
		>::value,
		"Variant2 must be a variant::object"
	);

	static_assert(
		fcppt::variant::is_object<
			typename
			std::decay<
				Variant3
			>::type
		>::value,
		"Variant3 must be a variant::object"
	);

	return
		fcppt::variant::apply_binary(
			[
				&_obj1,
				&_op
			](
				auto &&_t2_t,
				auto &&_t3
			)
			->
			decltype(
				auto
			)
			{
				return
					fcppt::variant::apply_unary(
						[
							&_t2_t,
							&_t3,
							&_op
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
											_t2_t
										)
									>(
										_t2_t
									),
									std::forward<
										decltype(
											_t3
										)
									>(
										_t3
									)
								);
						},
						std::forward<
							Variant1
						>(
							_obj1
						)
					);
			},
			std::forward<
				Variant2
			>(
				_obj2
			),
			std::forward<
				Variant3
			>(
				_obj3
			)
		);
}

}
}

#endif
