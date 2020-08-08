//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_DETAIL_CHAR_TYPES_HPP_INCLUDED
#define FCPPT_DETAIL_CHAR_TYPES_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <metal.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace detail
{

using
char_types
=
::metal::list<
	char,
	wchar_t,
	char16_t,
	char32_t
>;

}
}

#endif
