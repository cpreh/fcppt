//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONAL_DETAIL_ENABLE_REF_CONV_HPP_INCLUDED
#define FCPPT_OPTIONAL_DETAIL_ENABLE_REF_CONV_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace optional
{
namespace detail
{

template<
	typename Own,
	typename Other
>
using enable_ref_conv
=
typename
std::enable_if<
	std::is_const<
		Own
	>::value
	&&
	!std::is_const<
		Other
	>::value
>::type;

}
}
}

#endif
