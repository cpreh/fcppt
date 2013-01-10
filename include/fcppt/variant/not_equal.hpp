//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_VARIANT_NOT_EQUAL_HPP_INCLUDED
#define FCPPT_VARIANT_NOT_EQUAL_HPP_INCLUDED

#include <fcppt/variant/equal.hpp>
#include <fcppt/variant/object_fwd.hpp>


namespace fcppt
{
namespace variant
{

/**
\brief Compares two variants for inequality

\ingroup fcpptvariant

Compares \a _a and \a _b for inequality. Equal to <code>!(_a == _b)</code>.
This function requires all possible types of the variant to be equality
comparable.

\param _a The first variant
\param _b The second variant
*/
template<
	typename Types
>
bool
operator!=(
	fcppt::variant::object<
		Types
	> const &_a,
	fcppt::variant::object<
		Types
	> const &_b
)
{
	return
		!(_a == _b);
}

}
}

#endif
