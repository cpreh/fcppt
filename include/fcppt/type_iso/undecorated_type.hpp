//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_TYPE_ISO_UNDECORATED_TYPE_HPP_INCLUDED
#define FCPPT_TYPE_ISO_UNDECORATED_TYPE_HPP_INCLUDED

#include <fcppt/type_iso/detail/undecorated_type.hpp>


namespace fcppt
{
namespace type_iso
{

/**
\brief The undecorated type

Undecorates \a Type by removing all (nested) type constructors.

\ingroup fcppttypeiso
*/
template<
	typename Type
>
using undecorated_type
=
typename
fcppt::type_iso::detail::undecorated_type<
	Type
>::type;

}
}

#endif
