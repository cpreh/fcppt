//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_TYPE_TRAITS_REMOVE_CV_REF_HPP_INCLUDED
#define FCPPT_TYPE_TRAITS_REMOVE_CV_REF_HPP_INCLUDED

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

/**
\brief Removes references and cv qualifiers

\ingroup fcppttypetraits

Removes references and cv qualifiers from \a Type. It's the same as applying
<code>remove_reference</code>, followed by <code>remove_cv</code>.

\tparam Type Can be any type
*/
template<
	typename Type
>
struct remove_cv_ref
:
std::remove_cv<
	typename std::remove_reference<
		Type
	>::type
>
{
};

FCPPT_PP_POP_WARNING

}
}

#endif
