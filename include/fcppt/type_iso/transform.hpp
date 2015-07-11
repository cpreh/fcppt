//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_TYPE_ISO_TRANSFORM_HPP_INCLUDED
#define FCPPT_TYPE_ISO_TRANSFORM_HPP_INCLUDED

#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/type_iso/transform_fwd.hpp>
#include <fcppt/type_iso/detail/terminal_tag.hpp>


namespace fcppt
{
namespace type_iso
{

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

template<
	typename Type,
	typename Enable
>
struct transform
:
fcppt::type_iso::detail::terminal_tag
{
};

FCPPT_PP_POP_WARNING

}
}

#endif
