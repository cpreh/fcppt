//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_TYPE_ISO_DETAIL_UNDECORATED_TYPE_HPP_INCLUDED
#define FCPPT_TYPE_ISO_DETAIL_UNDECORATED_TYPE_HPP_INCLUDED

#include <fcppt/not.hpp>
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
	std::enable_if_t<
		fcppt::type_iso::detail::is_terminal<
			Type
		>::value
	>
>
{
	using
	type
	=
	Type;
};

template<
	typename Type
>
struct undecorated_type<
	Type,
	std::enable_if_t<
		fcppt::not_(
			fcppt::type_iso::detail::is_terminal<
				Type
			>::value
		)
	>
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

}
}
}

#endif
