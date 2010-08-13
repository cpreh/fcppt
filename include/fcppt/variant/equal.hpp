//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_VARIANT_EQUAL_HPP_INCLUDED
#define FCPPT_VARIANT_EQUAL_HPP_INCLUDED

#include <fcppt/variant/detail/compare.hpp>
#include <fcppt/variant/object_fwd.hpp>
#include <fcppt/variant/apply_unary.hpp>

namespace fcppt
{
namespace variant
{

template<
	typename Types
>
bool
operator==(
	object<Types> const &_a,
	object<Types> const &_b
)
{
	if(
		_a.empty() || _b.empty()
	)
		return _a.empty() == _b.empty();

	return
		variant::apply_unary(
			detail::compare<
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
