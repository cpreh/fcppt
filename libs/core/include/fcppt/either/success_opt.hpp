//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_EITHER_SUCCESS_OPT_HPP_INCLUDED
#define FCPPT_EITHER_SUCCESS_OPT_HPP_INCLUDED

#include <fcppt/move_if_rvalue.hpp>
#include <fcppt/either/is_object.hpp>
#include <fcppt/either/object_impl.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/type_traits/remove_cv_ref_t.hpp>


namespace fcppt
{
namespace either
{

/**
\brief Returns the success type as an optional

\ingroup fcppteither
*/
template<
	typename Either
>
fcppt::optional::object<
	typename
	fcppt::type_traits::remove_cv_ref_t<
		Either
	>::success
>
success_opt(
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

	typedef
	fcppt::optional::object<
		typename
		either::success
	>
	result_type;

	return
		_either.has_success()
		?
			result_type(
				fcppt::move_if_rvalue<
					Either
				>(
					_either.get_success_unsafe()
				)
			)
		:
			result_type()
		;
}

}
}

#endif
