//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_EITHER_MATCH_HPP_INCLUDED
#define FCPPT_EITHER_MATCH_HPP_INCLUDED

#include <fcppt/move_if_rvalue.hpp>
#include <fcppt/either/is_object.hpp>
#include <fcppt/either/object_impl.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/type_traits/remove_cv_ref_t.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace either
{

/**
\brief Matches on the two cases of an either

\ingroup fcppteither

If \a _either is set to success <code>s</code>, then
<code>_success_function(s)</code> is returned. Otherwise, \a _either is set to
failure <code>f</code> and <code>_failure_function(f)</code> is returned.

\tparam FailureFunction A function callable as <code>R (Either::failure)</code>
where <code>R</code> is the result type

\tparam SuccessFunction A function callable as <code>R (Either::success)</code>
where <code>R</code> is the result type
*/
template<
	typename Either,
	typename FailureFunction,
	typename SuccessFunction
>
auto
match(
	Either &&_either,
	FailureFunction const &_failure_function,
	SuccessFunction const &_success_function
)
->
decltype(
	_success_function(
		fcppt::move_if_rvalue<
			Either
		>(
			_either.get_success_unsafe()
		)
	)
)
{
	static_assert(
		fcppt::either::is_object<
			fcppt::type_traits::remove_cv_ref_t<
				Either
			>
		>::value,
		"Either must be an either"
	);

	static_assert(
		std::is_same<
			decltype(
				_success_function(
					fcppt::move_if_rvalue<
						Either
					>(
						_either.get_success_unsafe()
					)
				)
			),
			decltype(
				_failure_function(
					fcppt::move_if_rvalue<
						Either
					>(
						_either.get_failure_unsafe()
					)
				)
			)
		>::value,
		"FailureFunction and SuccessFunction must return the same type"
	);

	FCPPT_PP_PUSH_WARNING
	FCPPT_PP_DISABLE_GCC_WARNING(-Wnull-dereference)

	return
		_either.has_success()
		?
			_success_function(
				fcppt::move_if_rvalue<
					Either
				>(
					_either.get_success_unsafe()
				)
			)
		:
			_failure_function(
				fcppt::move_if_rvalue<
					Either
				>(
					_either.get_failure_unsafe()
				)
			)
		;

	FCPPT_PP_POP_WARNING
}

}
}

#endif
