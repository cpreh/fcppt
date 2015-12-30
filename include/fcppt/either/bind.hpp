//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_EITHER_BIND_HPP_INCLUDED
#define FCPPT_EITHER_BIND_HPP_INCLUDED

#include <fcppt/move_if_rvalue.hpp>
#include <fcppt/either/is_object.hpp>
#include <fcppt/either/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace either
{

/**
\brief Monadic bind on the success type of an either

\ingroup fcppteither

If \a _either is set to success <code>s</code>, then <code>_function(s)</code>
is returned. Otherwise, the failure in \a _either is returned.

\tparam Function A function callable as <code>either<Either::failure,R>
(Either::success)</code> where <code>R</code> is the result type
*/
template<
	typename Either,
	typename Function
>
auto
bind(
	Either &&_either,
	Function const &_function
)
->
decltype(
	_function(
		fcppt::move_if_rvalue<
			Either
		>(
			_either.get_success_unsafe()
		)
	)
)
{
	typedef
	typename
	std::decay<
		Either
	>::type
	either;

	static_assert(
		fcppt::either::is_object<
			either
		>::value,
		"Either must be an either"
	);

	typedef
	decltype(
		_function(
			fcppt::move_if_rvalue<
				Either
			>(
				_either.get_success_unsafe()
			)
		)
	)
	result_type;

	static_assert(
		fcppt::either::is_object<
			result_type
		>::value,
		"The result must be an either"
	);

	static_assert(
		std::is_same<
			typename
			result_type::failure,
			typename
			either::failure
		>::value,
		"failure types must be the same"
	);

	return
		_either.has_success()
		?
			_function(
				fcppt::move_if_rvalue<
					Either
				>(
					_either.get_success_unsafe()
				)
			)
		:
			result_type(
				_either.get_failure_unsafe()
			)
		;
}

}
}

#endif
