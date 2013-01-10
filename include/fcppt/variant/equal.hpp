//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_VARIANT_EQUAL_HPP_INCLUDED
#define FCPPT_VARIANT_EQUAL_HPP_INCLUDED

#include <fcppt/variant/apply_unary.hpp>
#include <fcppt/variant/object_fwd.hpp>
#include <fcppt/variant/detail/compare.hpp>


namespace fcppt
{
namespace variant
{

/**
\brief Compares two variants for equality

\ingroup fcpptvariant

Compares \a _a and \a _b for equality. The two variants will be equal if they
hold the same type and the values compare equal. This function requires all
possible types of the variant to be equality comparable.

\param _a The first variant
\param _b The second variant
*/
template<
	typename Types
>
bool
operator==(
	fcppt::variant::object<
		Types
	> const &_a,
	fcppt::variant::object<
		Types
	> const &_b
)
{
	return
		fcppt::variant::apply_unary(
			fcppt::variant::detail::compare<
				Types
			>(
				_a
			),
			_b
		);
}

}
}

#endif
