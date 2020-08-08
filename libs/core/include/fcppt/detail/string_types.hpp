//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_DETAIL_STRING_TYPES_HPP_INCLUDED
#define FCPPT_DETAIL_STRING_TYPES_HPP_INCLUDED

#include <fcppt/detail/char_types.hpp>
#include <fcppt/config/external_begin.hpp>
#include <metal.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace detail
{

using
string_types
=
::metal::transform<
	::metal::lambda<
		std::add_pointer_t
	>,
	::metal::transform<
		::metal::lambda<
			std::add_const_t
		>,
		fcppt::detail::char_types
	>
>;

}
}

#endif
