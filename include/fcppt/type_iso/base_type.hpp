//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_TYPE_ISO_BASE_TYPE_HPP_INCLUDED
#define FCPPT_TYPE_ISO_BASE_TYPE_HPP_INCLUDED

#include <fcppt/type_iso/detail/base_type.hpp>


namespace fcppt
{
namespace type_iso
{

template<
	typename Type
>
using base_type
=
typename
fcppt::type_iso::detail::base_type<
	Type
>::type;

}
}

#endif
