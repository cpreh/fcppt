//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_TYPE_TRAITS_REMOVE_CV_REF_HPP_INCLUDED
#define FCPPT_TYPE_TRAITS_REMOVE_CV_REF_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace type_traits
{

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
using remove_cv_ref
=
std::remove_cv<
	std::remove_reference_t<
		Type
	>
>;

}
}

#endif
