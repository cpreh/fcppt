//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_VARIANT_COMPARE_HPP_INCLUDED
#define FCPPT_VARIANT_COMPARE_HPP_INCLUDED

#include <fcppt/variant/apply_unary.hpp>
#include <fcppt/variant/object_fwd.hpp>
#include <fcppt/variant/detail/compare.hpp>


namespace fcppt
{
namespace variant
{

/**
\brief Compares two variants using a Compare function

\ingroup fcpptvariant

Compares \a _a and \a _b using \a _compare. The two variants are equal if they
hold the same type <code>T</code> and <code>_compare(_a.get<T>(),
_b.get<T>())</code> holds.

\param _a The first variant
\param _b The second variant
\param _compare The function to use for comparison
*/
template<
	typename Types,
	typename Compare
>
bool
compare(
	fcppt::variant::object<
		Types
	> const &_a,
	fcppt::variant::object<
		Types
	> const &_b,
	Compare const &_compare
)
{
	return
		fcppt::variant::apply_unary(
			fcppt::variant::detail::compare<
				Types,
				Compare
			>(
				_a,
				_compare
			),
			_b
		);
}

}
}

#endif
