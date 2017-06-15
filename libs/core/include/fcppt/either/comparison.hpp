//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_EITHER_COMPARISON_HPP_INCLUDED
#define FCPPT_EITHER_COMPARISON_HPP_INCLUDED

#include <fcppt/either/object_impl.hpp>


namespace fcppt
{
namespace either
{

/**
\brief Compares two eithers for equality

\ingroup fcppteither
*/
template<
	typename Failure,
	typename Success
>
bool
operator==(
	fcppt::either::object<
		Failure,
		Success
	> const &_a,
	fcppt::either::object<
		Failure,
		Success
	> const &_b
)
{
	return
		_a.has_success()
		&&
		_b.has_success()
		?
			_a.get_success_unsafe()
			==
			_b.get_success_unsafe()
		:
			_a.has_failure()
			&&
			_b.has_failure()
			&&
			_a.get_failure_unsafe()
			==
			_b.get_failure_unsafe()
		;
}

/**
\brief Compares two eithers for inequality

\ingroup fcppteither
*/
template<
	typename Failure,
	typename Success
>
bool
operator!=(
	fcppt::either::object<
		Failure,
		Success
	> const &_a,
	fcppt::either::object<
		Failure,
		Success
	> const &_b
)
{
	return
		!(_a == _b);
}

}
}

#endif
