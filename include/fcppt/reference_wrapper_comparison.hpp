//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_REFERENCE_WRAPPER_COMPARISON_HPP_INCLUDED
#define FCPPT_REFERENCE_WRAPPER_COMPARISON_HPP_INCLUDED

#include <fcppt/reference_wrapper_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <functional>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{

/**
\brief Compares two reference_wrappers for equality

\ingroup fcpptref

Compares \a _a and \a _b for equality. Two reference_wrappers are equal if they
refer to the same object.

\param _a The first reference_wrapper
\param _b The second reference_wrapper
*/
template<
	typename T
>
bool
operator==(
	fcppt::reference_wrapper<T> const &_a,
	fcppt::reference_wrapper<T> const &_b
)
{
	return
		_a.get_pointer()
		==
		_b.get_pointer();
}

/**
\brief Compares two reference_wrappers for inequality

\ingroup fcpptref

Compares \a _a and \a _b for inequality. Equal to <code>!(_a == _b)</code>.

\param _a The first reference_wrapper
\param _b The second reference_wrapper
*/
template<
	typename T
>
bool
operator!=(
	fcppt::reference_wrapper<T> const &_a,
	fcppt::reference_wrapper<T> const &_b
)
{
	return
		!(_a == _b);
}

/**
\brief Compares two reference_wrappers lexicographically

\ingroup fcpptref

Compares \a _a and \a _b lexicographically by comparing the stored pointers via
<code>std::less</code>.

\param _a The first reference_wrapper
\param _b The second reference_wrapper
*/
template<
	typename T
>
bool
operator<(
	fcppt::reference_wrapper<T> const &_a,
	fcppt::reference_wrapper<T> const &_b
)
{
	return
		std::less<
			T *
		>()(
			_a.get_pointer(),
			_b.get_pointer()
		);
}

}

#endif
