//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONAL_COMPARISON_HPP_INCLUDED
#define FCPPT_OPTIONAL_COMPARISON_HPP_INCLUDED

#include <fcppt/optional/object_impl.hpp>


namespace fcppt
{
namespace optional
{

/**
\brief Compares two optionals for equality

\ingroup fcpptoptional

Compares \a _a and \a _b for equality. Two optionals are equal if they are
either both empty or if they are both not empty and their elements compare
equal. This function requires \a T to be equality comparable.

\param _a The first optional
\param _b The second optional
*/
template<
	typename T
>
bool
operator==(
	fcppt::optional::object<
		T
	> const &_a,
	fcppt::optional::object<
		T
	> const &_b
)
{
	return
		_a.has_value() && _b.has_value()
		?
			_a.get_unsafe() == _b.get_unsafe()
		:
			_a.has_value() == _b.has_value()
		;
}

/**
\brief Compares two optionals for inequality

\ingroup fcpptoptional

Compares \a _a and \a _b for inequality. Equal to <code>!(_a == _b)</code>.
This function requires \a T to be equality comparable.

\param _a The first optional
\param _b The second optional
*/
template<
	typename T
>
bool
operator!=(
	fcppt::optional::object<
		T
	> const &_a,
	fcppt::optional::object<
		T
	> const &_b
)
{
	return
		!(_a == _b);
}

/**
\brief Compares two optionals lexicographically

\ingroup fcpptoptional

Compares \a _a and \a _b lexicographically. If one or both of them are empty,
returns <code>_a.has_value() < _b.has_value()</code>, otherwise returns
<code>_a.get_unsafe() < _b.get_unsafe()</code>.
\param _a The first optional
\param _b The second optional
*/
template<
	typename T
>
bool
operator<(
	fcppt::optional::object<
		T
	> const &_a,
	fcppt::optional::object<
		T
	> const &_b
)
{
	return
		_a.has_value() && _b.has_value()
		?
			_a.get_unsafe() < _b.get_unsafe()
		:
			_a.has_value() < _b.has_value()
		;
}

}
}

#endif
