//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_DETAIL_ENUM_SIZE_HPP_INCLUDED
#define FCPPT_DETAIL_ENUM_SIZE_HPP_INCLUDED

#include <fcppt/enum_is_empty.hpp>
#include <fcppt/enum_size_type.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <boost/utility/enable_if.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace detail
{

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

template<
	typename Type,
	typename Enable = void
>
struct enum_size;

template<
	typename Type
>
struct enum_size<
	Type,
	typename boost::enable_if<
		fcppt::enum_is_empty<
			Type
		>
	>::type
>
:
std::integral_constant<
	typename fcppt::enum_size_type<
		Type
	>::type,
	0
>
{
};

template<
	typename Type
>
struct enum_size<
	Type,
	typename boost::disable_if<
		fcppt::enum_is_empty<
			Type
		>
	>::type
>
:
std::integral_constant<
	typename fcppt::enum_size_type<
		Type
	>::type,
	static_cast<
		typename fcppt::enum_size_type<
			Type
		>::type
	>(
		Type::fcppt_maximum
	)
	+ 1u
>
{
};

FCPPT_PP_POP_WARNING

}
}

#endif
