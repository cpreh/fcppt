//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_TYPE_TRAITS_REMOVE_CV_REF_T_HPP_INCLUDED
#define FCPPT_TYPE_TRAITS_REMOVE_CV_REF_T_HPP_INCLUDED

#include <fcppt/type_traits/remove_cv_ref.hpp>


namespace fcppt
{
namespace type_traits
{

/**
\brief Removes references and cv qualifiers. Version without typename.

\ingroup fcppttypetraits
*/
template<
	typename Type
>
using
remove_cv_ref_t
=
typename
fcppt::type_traits::remove_cv_ref<
	Type
>::type;

}
}

#endif
