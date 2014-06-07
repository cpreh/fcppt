//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_TYPE_TRAITS_IS_RAW_POINTER_HPP_INCLUDED
#define FCPPT_TYPE_TRAITS_IS_RAW_POINTER_HPP_INCLUDED

#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/contains.hpp>
#include <boost/mpl/vector/vector10.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace type_traits
{

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

template<
	typename Type
>
struct is_raw_pointer
:
std::false_type
{
};

template<
	typename Type
>
struct is_raw_pointer<
	Type *
>
:
boost::mpl::contains<
	boost::mpl::vector2<
		char,
		unsigned char
	>,
	typename
	std::remove_cv<
		Type
	>::type
>
{
};

FCPPT_PP_POP_WARNING

}
}

#endif
