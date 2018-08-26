//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_IS_ZERO_LITERAL_HPP_INCLUDED
#define FCPPT_MATH_IS_ZERO_LITERAL_HPP_INCLUDED

#include <fcppt/literal.hpp>
#include <fcppt/math/is_zero_impl_fwd.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>


namespace fcppt
{
namespace math
{

template<
	typename T,
	typename Enable
>
struct is_zero_impl
{
	static
	constexpr
	bool
	get(
		T const &_value
	)
	{
FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Wfloat-equal)
		return
			_value
			==
			fcppt::literal<
				T
			>(
				0
			);
FCPPT_PP_POP_WARNING
	}
};

}
}

#endif
