//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_VARIANT_DETAIL_TO_OPTIONAL_RESULT_HPP_INCLUDED
#define FCPPT_VARIANT_DETAIL_TO_OPTIONAL_RESULT_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/if.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace variant
{
namespace detail
{

template<
	typename Type,
	typename Variant
>
using
to_optional_result
=
typename
boost::mpl::if_<
	std::is_lvalue_reference<
		Variant
	>,
	typename
	std::add_lvalue_reference<
		typename
		boost::mpl::if_<
			std::is_const<
				typename
				std::remove_reference<
					Variant
				>::type
			>,
			typename
			std::add_const<
				Type
			>::type,
			Type
		>::type
	>::type,
	Type
>::type;

}
}
}

#endif
