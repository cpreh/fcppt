//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_EITHER_JOIN_HPP_INCLUDED
#define FCPPT_EITHER_JOIN_HPP_INCLUDED

#include <fcppt/move_if_rvalue.hpp>
#include <fcppt/either/bind.hpp>
#include <fcppt/either/failure_type.hpp>
#include <fcppt/either/is_object.hpp>
#include <fcppt/either/object_impl.hpp>
#include <fcppt/either/success_type.hpp>
#include <fcppt/type_traits/remove_cv_ref_t.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace either
{

/**
\brief Joins an either.

\ingroup fcppteither

If the outer either has failure <code>f_1</code>, then <code>f_1</code> is returned.
Otherwise, if the inner either has failure <code>f_2</code>, then <code>f_2</code> is returned.
Otherwise, the success value of the inner either is returned.

\tparam Either Must be an <code>fcppt::either::object<F,fcppt::either::object<F,S>></code>.
*/
template<
	typename Either
>
fcppt::either::object<
	fcppt::either::failure_type<
		fcppt::type_traits::remove_cv_ref_t<
			Either
		>
	>,
	fcppt::either::success_type<
		fcppt::either::success_type<
			fcppt::type_traits::remove_cv_ref_t<
				Either
			>
		>
	>
>
join(
	Either &&_either
)
{
	typedef
	fcppt::type_traits::remove_cv_ref_t<
		Either
	>
	either;

	static_assert(
		fcppt::either::is_object<
			either
		>::value,
		"Either must be an either"
	);

	static_assert(
		std::is_same<
			fcppt::either::failure_type<
				either
			>,
			fcppt::either::failure_type<
				fcppt::either::success_type<
					either
				>
			>
		>::value,
		"Both eithers must have the same failure type"
	);

	return
		fcppt::either::bind(
			std::forward<
				Either
			>(
				_either
			),
			[](
				auto &&_value
			)
			{
				return
					fcppt::move_if_rvalue<
						Either
					>(
						_value
					);
			}
		);
}

}
}

#endif
