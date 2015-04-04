//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_DETAIL_IS_OPTIONAL_REFERENCE_HPP_INCLUDED
#define FCPPT_DETAIL_IS_OPTIONAL_REFERENCE_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace detail
{

template<
	typename Optional
>
using
is_optional_reference
=
std::is_lvalue_reference<
	typename
	std::remove_reference<
		typename
		std::remove_const<
			Optional
		>::type
	>::type::element_type
>;

}
}

#endif
