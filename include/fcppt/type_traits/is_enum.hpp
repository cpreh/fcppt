//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_TYPE_TRAITS_IS_ENUM_HPP_INCLUDED
#define FCPPT_TYPE_TRAITS_IS_ENUM_HPP_INCLUDED

#include <fcppt/detail/foreach_enumerator_var_fwd.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace type_traits
{

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

template<
	typename Type
>
struct is_enum
:
std::is_enum<
	Type
>
{
};

template<
	typename Enum
>
struct is_enum<
	fcppt::detail::foreach_enumerator_var<
		Enum
	>
>
:
std::true_type
{
};

FCPPT_PP_POP_WARNING

}
}

#endif
