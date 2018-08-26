//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_TYPE_ISO_DETAIL_IS_TERMINAL_HPP_INCLUDED
#define FCPPT_TYPE_ISO_DETAIL_IS_TERMINAL_HPP_INCLUDED

#include <fcppt/type_iso/transform_fwd.hpp>
#include <fcppt/type_iso/detail/terminal_tag.hpp>
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
	typename Type
>
using is_terminal
=
std::is_base_of<
	fcppt::type_iso::detail::terminal_tag,
	fcppt::type_iso::transform<
		Type
	>
>;

}
}
}

#endif
