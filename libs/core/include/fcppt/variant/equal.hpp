//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_VARIANT_EQUAL_HPP_INCLUDED
#define FCPPT_VARIANT_EQUAL_HPP_INCLUDED

#include <fcppt/const.hpp>
#include <fcppt/optional/maybe.hpp>
#include <fcppt/type_traits/remove_cv_ref_t.hpp>
#include <fcppt/variant/apply_unary.hpp>
#include <fcppt/variant/object_impl.hpp>
#include <fcppt/variant/to_optional.hpp>


namespace fcppt
{
namespace variant
{

/**
\brief Compares two variants for equality

\ingroup fcpptvariant

Compares \a _left and \a _right for equality. The two variants are equal if they hold
the same type and the values compare equal. This function requires all possible
types of the variant to be equality comparable.

\param _left The first variant
\param _right The second variant
*/
template<
	typename Types
>
bool
operator==(
	fcppt::variant::object<
		Types
	> const &_left,
	fcppt::variant::object<
		Types
	> const &_right
)
{
	return
		fcppt::variant::apply_unary(
			[
				&_left
			](
				auto const &_right_inner
			)
			-> bool
			{
				return
					fcppt::optional::maybe(
						fcppt::variant::to_optional<
							fcppt::type_traits::remove_cv_ref_t<
								decltype(
									_right_inner
								)
							>
						>(
							_left
						),
						fcppt::const_(
							false
						),
						[
							&_right_inner
						](
							auto const &_left_inner
						)
						{
							return
								_left_inner
								==
								_right_inner;
						}
					);
			},
			_right
		);
}

}
}

#endif
