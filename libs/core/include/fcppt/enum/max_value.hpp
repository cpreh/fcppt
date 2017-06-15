//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ENUM_MAX_VALUE_HPP_INCLUDED
#define FCPPT_ENUM_MAX_VALUE_HPP_INCLUDED

#include <fcppt/enum/max_value_fwd.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace enum_
{

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

/**
\brief The maximum enumerator in an enum

This class defines the maximum enumerator (the enumerator with the biggest
integral value) in the enum denoted by \a Type. The default behaviour is to use
<code>Type::fcppt_maximum</code>. Specialize this class to change that.

\ingroup fcpptenum

\note Unfortunately, there is no way to automatically retrieve the maximum
enumerator in an enum in C++.

\tparam Type Must be an enum type
*/
template<
	typename Type
>
struct max_value
:
std::integral_constant<
	Type,
	Type::fcppt_maximum
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
}

#endif
