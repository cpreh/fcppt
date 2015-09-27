//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_BIT_TEST_HPP_INCLUDED
#define FCPPT_BIT_TEST_HPP_INCLUDED

#include <fcppt/literal.hpp>
#include <fcppt/bit/mask.hpp>


namespace fcppt
{
namespace bit
{

/**
\brief Tests a value against a bit mask

\ingroup fcpptbit
*/
template<
	typename Type
>
inline
bool
test(
	Type const _value,
	fcppt::bit::mask<
		Type
	> const _mask
)
{
	return
		(
			_value
			&
			_mask.get()
		)
		!=
		fcppt::literal<
			Type
		>(
			0
		);
}

}
}

#endif
