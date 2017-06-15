//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_IS_STRONG_TYPEDEF_HPP_INCLUDED
#define FCPPT_IS_STRONG_TYPEDEF_HPP_INCLUDED

#include <fcppt/strong_typedef_fwd.hpp>
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
\brief Tests if a type is a strong typedef

\ingroup fcpptstrongtypedef
*/
template<
	typename T
>
struct is_strong_typedef
:
std::false_type
{
};

template<
	typename Type,
	typename Tag
>
struct is_strong_typedef<
	fcppt::strong_typedef<
		Type,
		Tag
	>
>
:
std::true_type
{
};

FCPPT_PP_POP_WARNING

}

#endif
