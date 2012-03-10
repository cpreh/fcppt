//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_NULL_PTR_T_HPP_INCLUDED
#define FCPPT_NULL_PTR_T_HPP_INCLUDED

#include <fcppt/config/warnings.hpp>
#if defined(FCPPT_CONFIG_HAVE_ZERO_AS_NULL_POINTER_CONSTANT_WARNING)
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#endif

namespace fcppt
{

/**
\brief A class that is implicitly convertible to null pointers

\ingroup fcpptvarious

This class is returned by fcppt::null_ptr to emulate C++11's
<code>nullptr</code>.
*/
struct null_ptr_t
{
#if defined(FCPPT_CONFIG_HAVE_ZERO_AS_NULL_POINTER_CONSTANT_WARNING)
FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Wzero-as-null-pointer-constant)
#endif
	template<
		typename T
	>
	operator T*() const
	{
		return 0;
	}
#if defined(FCPPT_CONFIG_HAVE_ZERO_AS_NULL_POINTER_CONSTANT_WARNING)
FCPPT_PP_POP_WARNING
#endif
};

}

#endif
