//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_TYPE_ISO_DETAIL_UNDECORATED_TYPE_HPP_INCLUDED
#define FCPPT_TYPE_ISO_DETAIL_UNDECORATED_TYPE_HPP_INCLUDED

#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/type_iso/transform.hpp>
#include <fcppt/type_iso/detail/is_terminal.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace type_iso
{
namespace detail
{

template<
	typename Type,
	typename Enable = void
>
struct undecorated_type;

template<
	typename Type
>
struct undecorated_type<
	Type,
	typename
	std::enable_if<
		fcppt::type_iso::detail::is_terminal<
			Type
		>::value
	>::type
>
{
	typedef
	Type
	type;
};

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

template<
	typename Type
>
struct undecorated_type<
	Type,
	typename
	std::enable_if<
		!fcppt::type_iso::detail::is_terminal<
			Type
		>::value
	>::type
>
:
fcppt::type_iso::detail::undecorated_type<
	typename
	fcppt::type_iso::transform<
		Type
	>::undecorated_type
>
{
};

FCPPT_PP_POP_WARNING

}
}
}

#endif
