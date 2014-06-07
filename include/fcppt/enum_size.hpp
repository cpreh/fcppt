//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ENUM_SIZE_HPP_INCLUDED
#define FCPPT_ENUM_SIZE_HPP_INCLUDED

#include <fcppt/enum_size_fwd.hpp>
#include <fcppt/detail/enum_size.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

/**
\brief The number of enumerators in an enum

\ingroup fcpptenum

This class defines the number of enumerators in the enum denoted by \a Type.
The default behavior is to set it to use <code>fcppt::enum_max_value<Type> +
1</code>. Specialize this class to change that.

\note Unfortunately, there is no way to automatically retrieve the number of
enumerators in an enum in C++.

\tparam Type Must be an enum type
*/
template<
	typename Type
>
struct enum_size
:
fcppt::detail::enum_size<
	Type
>
{
	static_assert(
		std::is_enum<
			Type
		>::value,
		"Type must be an enum type"
	);
};

FCPPT_PP_POP_WARNING

}

#endif
