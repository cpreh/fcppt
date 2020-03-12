//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_EITHER_MAP_HPP_INCLUDED
#define FCPPT_EITHER_MAP_HPP_INCLUDED

#include <fcppt/move_if_rvalue.hpp>
#include <fcppt/either/failure_type.hpp>
#include <fcppt/either/is_object.hpp>
#include <fcppt/either/object_impl.hpp>
#include <fcppt/type_traits/remove_cv_ref_t.hpp>


namespace fcppt
{
namespace either
{

/**
\brief Maps over the success type of an either.

\ingroup fcppteither

If \a _either is set to success <code>s</code>, <code>r = _function(s)</code>
is called and the result is
<code>either<Either::failure,decltype(r)>(r)</code>. Otherwise, the failure in
\a _either is returned.

\tparam Function A function callable as <code>R (Either::success)</code> where
<code>R</code> is the result type
*/
template<
	typename Either,
	typename Function
>
auto
map(
	Either &&_either,
	Function const &_function
)
->
fcppt::either::object<
	fcppt::either::failure_type<
		fcppt::type_traits::remove_cv_ref_t<
			Either
		>
	>,
	decltype(
		_function(
			fcppt::move_if_rvalue<
				Either
			>(
				_either.get_success_unsafe()
			)
		)
	)
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
		fcppt::either::failure_type<
			fcppt::type_traits::remove_cv_ref_t<
				Either
			>
		>,
		decltype(
			_function(
				fcppt::move_if_rvalue<
					Either
				>(
					_either.get_success_unsafe()
				)
			)
		)
	>;

	return
		_either.has_success()
		?
			result_type(
				_function(
					fcppt::move_if_rvalue<
						Either
					>(
						_either.get_success_unsafe()
					)
				)
			)
		:
			result_type(
				fcppt::move_if_rvalue<
					Either
				>(
					_either.get_failure_unsafe()
				)
			)
		;
}

}
}

#endif
