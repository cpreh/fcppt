//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_TYPE_TRAITS_IS_RAW_POINTER_HPP_INCLUDED
#define FCPPT_TYPE_TRAITS_IS_RAW_POINTER_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/and.hpp>
#include <boost/mpl/contains.hpp>
#include <boost/mpl/vector/vector10.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace type_traits
{

template<
	typename Type
>
using is_raw_pointer
=
boost::mpl::and_<
	std::is_pointer<
		Type
	>,
	boost::mpl::contains<
		boost::mpl::vector2<
			char,
			unsigned char
		>,
		typename
		std::remove_cv<
			typename
			std::remove_pointer<
				Type
			>::type
		>::type
	>
>;

}
}

#endif
