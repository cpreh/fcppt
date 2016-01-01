//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONAL_DETAIL_ENABLE_VALUE_CONV_HPP_INCLUDED
#define FCPPT_OPTIONAL_DETAIL_ENABLE_VALUE_CONV_HPP_INCLUDED

#include <fcppt/type_traits/remove_cv_ref.hpp>
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
	typename Other,
	typename Result
>
using enable_value_conv
=
typename
std::enable_if<
	std::is_reference<
		Other
	>::value
	&&
	std::is_same<
		Own,
		typename
		fcppt::type_traits::remove_cv_ref<
			Other
		>::type
	>::value
>::type;

}
}
}

#endif
