//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_EITHER_MAP_FAILURE_HPP_INCLUDED
#define FCPPT_EITHER_MAP_FAILURE_HPP_INCLUDED

#include <fcppt/move_if_rvalue.hpp>
#include <fcppt/either/is_object.hpp>
#include <fcppt/either/object_impl.hpp>
#include <fcppt/either/success_type.hpp>
#include <fcppt/type_traits/remove_cv_ref_t.hpp>


namespace fcppt
{
namespace either
{

/**
\brief Maps over the failure type of an either.

\ingroup fcppteither

If \a _either is set to failure <code>f</code>, <code>r = _function(f)</code>
is called and the result is
<code>either<decltype(r),Either::success>(r)</code>.  Otherwise, the success in
\a _either is returned.

\tparam Function A function callable as <code>R (Either::failure)</code> where
<code>R</code> is the result type
*/
template<
	typename Either,
	typename Function
>
auto
map_failure(
	Either &&_either,
	Function const &_function
)
->
fcppt::either::object<
	decltype(
		_function(
			fcppt::move_if_rvalue<
				Either
			>(
				_either.get_failure_unsafe()
			)
		)
	),
	fcppt::either::success_type<
		fcppt::type_traits::remove_cv_ref_t<
			Either
		>
	>
>
{
	using
	either
	=
	fcppt::type_traits::remove_cv_ref_t<
		Either
	>;

	static_assert(
		fcppt::either::is_object<
			either
		>::value,
		"Either must be an either"
	);

	using
	result_type
	=
	fcppt::either::object<
		decltype(
			_function(
				fcppt::move_if_rvalue<
					Either
				>(
					_either.get_failure_unsafe()
				)
			)
		),
		fcppt::either::success_type<
			fcppt::type_traits::remove_cv_ref_t<
				Either
			>
		>
	>;

	return
		_either.has_failure()
		?
			result_type(
				_function(
					fcppt::move_if_rvalue<
						Either
					>(
						_either.get_failure_unsafe()
					)
				)
			)
		:
			result_type(
				fcppt::move_if_rvalue<
					Either
				>(
					_either.get_success_unsafe()
				)
			)
		;
}

}
}

#endif
