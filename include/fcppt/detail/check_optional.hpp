//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_DETAIL_CHECK_OPTIONAL_HPP_INCLUDED
#define FCPPT_DETAIL_CHECK_OPTIONAL_HPP_INCLUDED

#include <fcppt/is_optional.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace detail
{

template<
	typename Type
>
using
check_optional
=
fcppt::is_optional<
	typename
	std::remove_const<
		typename
		std::remove_reference<
			Type
		>::type
	>::type
>;

}
}

#endif
