//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_EITHER_ERROR_FROM_OPTIONAL_HPP_INCLUDED
#define FCPPT_EITHER_ERROR_FROM_OPTIONAL_HPP_INCLUDED

#include <fcppt/move_if_rvalue.hpp>
#include <fcppt/either/error.hpp>
#include <fcppt/either/no_error.hpp>
#include <fcppt/optional/maybe.hpp>
#include <fcppt/optional/value_type.hpp>
#include <fcppt/optional/detail/check.hpp>
#include <fcppt/type_traits/remove_cv_ref_t.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace either
{

/**
\brief Converts an optional error to an either.

\ingroup fcppteither

If \a _optional is set to <code>x</code>, then <code>x</code> is returned as
the failure value.
*/
template<
	typename Optional
>
auto
error_from_optional(
	Optional &&_optional
)
->
fcppt::either::error<
	fcppt::optional::value_type<
		fcppt::type_traits::remove_cv_ref_t<
			Optional
		>
	>
>
{
	static_assert(
		fcppt::optional::detail::check<
			Optional
		>::value,
		"Optional must be an optional"
	);

	typedef
	fcppt::either::error<
		fcppt::optional::value_type<
			fcppt::type_traits::remove_cv_ref_t<
				Optional
			>
		>
	>
	result_type;

	return
		fcppt::optional::maybe(
			std::forward<
				Optional
			>(
				_optional
			),
			[]{
				return
					result_type{
						fcppt::either::no_error{}
					};
			},
			[](
				auto &&_value
			)
			{
				return
					result_type(
						fcppt::move_if_rvalue<
							Optional
						>(
							_value
						)
					);
			}
		);
}

}
}

#endif
