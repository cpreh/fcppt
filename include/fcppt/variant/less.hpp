//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_VARIANT_LESS_HPP_INCLUDED
#define FCPPT_VARIANT_LESS_HPP_INCLUDED

#include <fcppt/variant/apply_unary.hpp>
#include <fcppt/variant/object_fwd.hpp>
#include <fcppt/variant/detail/less.hpp>


namespace fcppt
{
namespace variant
{

/**
\brief Tests if one variant is less than another

\ingroup fcpptvariant

Tests if \a _left is less than \a _right. Let val_left be the value stored in
\a _left and val_right the value stored in \a _right. \a _left is less than \a
_right iff <code>(_left.type_index(), val_left)</code> is lexicographically
before <code>(_right.type_index(), val_right)</code>. This also implies that
every type of the variant must be less comparable.

\param _left The first variant
\param _right The second variant
*/
template<
	typename Types
>
bool
operator<(
	fcppt::variant::object<
		Types
	> const &_left,
	fcppt::variant::object<
		Types
	> const &_right
)
{
	return
		_left.type_index()
		==
		_right.type_index()
		?
			fcppt::variant::apply_unary(
				fcppt::variant::detail::less<
					Types
				>(
					_left
				),
				_right
			)
		:
			_left.type_index()
			<
			_right.type_index()
		;
}

}
}

#endif
