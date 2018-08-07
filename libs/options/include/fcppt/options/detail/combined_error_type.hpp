//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONS_DETAIL_COMBINED_ERROR_TYPE_HPP_INCLUDED
#define FCPPT_OPTIONS_DETAIL_COMBINED_ERROR_TYPE_HPP_INCLUDED

#include <fcppt/options/detail/combined_error_type_impl.hpp>


namespace fcppt
{
namespace options
{
namespace detail
{

template<
	typename T1,
	typename T2
>
using
combined_error_type
=
typename
fcppt::options::detail::combined_error_type_impl<
	T1,
	T2
>::type;

}
}
}

#endif
