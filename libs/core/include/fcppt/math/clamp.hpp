//          Copyright Carl Philipp Reh 2009 - 2016.
//          Copyright Philipp Middendorf 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_CLAMP_HPP_INCLUDED
#define FCPPT_MATH_CLAMP_HPP_INCLUDED

#include <fcppt/assert/pre.hpp>
#include <fcppt/config/external_begin.hpp>
#include <algorithm>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace math
{

/**
\brief Clamps a value into a range

\ingroup fcpptmath

\pre \p _vmin <= \p _vmax
*/
template<
	typename T
>
T
clamp(
	T const &_value,
	T const &_vmin,
	T const &_vmax
)
{
	FCPPT_ASSERT_PRE(
		_vmin <= _vmax
	);

	return
		std::max(
			std::min(
				_value,
				_vmax
			),
			_vmin
		);
}

}
}

#endif
