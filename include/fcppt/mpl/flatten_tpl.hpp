//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MPL_FLATTEN_TPL_HPP_INCLUDED
#define FCPPT_MPL_FLATTEN_TPL_HPP_INCLUDED

#include <fcppt/mpl/detail/flatten.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>


namespace fcppt
{
namespace mpl
{

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

/**
\brief Flattens an MPL sequence

\ingroup fcpptmpl
*/
template<
	typename Type
>
struct flatten_tpl
:
fcppt::mpl::detail::flatten<
	Type
>
{
};

FCPPT_PP_POP_WARNING

}
}

#endif
