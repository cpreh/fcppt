//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_VARIANT_COMPARE_HPP_INCLUDED
#define FCPPT_VARIANT_COMPARE_HPP_INCLUDED

#include <fcppt/const.hpp>
#include <fcppt/optional/maybe.hpp>
#include <fcppt/type_traits/remove_cv_ref_t.hpp>
#include <fcppt/variant/apply.hpp>
#include <fcppt/variant/object_fwd.hpp>
#include <fcppt/variant/to_optional.hpp>


namespace fcppt
{
namespace variant
{

/**
\brief Compares two variants using a Compare function

\ingroup fcpptvariant

Compares \a _left and \a _right using \a _compare. The two variants are equal
if they hold the same type <code>T</code> and <code>_compare(_left.get<T>(),
_right.get<T>())</code> holds.

\param _left The first variant
\param _right The second variant
\param _compare The function to use for comparison
*/
template<
	typename Types,
	typename Compare
>
inline
bool
compare(
	fcppt::variant::object<
		Types
	> const &_left,
	fcppt::variant::object<
		Types
	> const &_right,
	Compare const &_compare
)
{
	return
		fcppt::variant::apply(
			[
				&_compare,
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
							&_right_inner,
							&_compare
						](
							auto const &_left_inner
						)
						{
							return
								_compare(
									_left_inner,
									_right_inner
								);
						}
					);
			},
			_right
		);
}

}
}

#endif
