//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_DETAIL_CHAR_LITERAL_HPP_INCLUDED
#define FCPPT_DETAIL_CHAR_LITERAL_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace detail
{

template<
	typename Type
>
inline
std::enable_if_t<
	std::is_same_v<
		Type,
		char
	>,
	char
>
char_literal(
	char const _literal,
	wchar_t
)
{
	return
		_literal;
}

template<
	typename Type
>
inline
std::enable_if_t<
	std::is_same_v<
		Type,
		wchar_t
	>,
	wchar_t
>
char_literal(
	char,
	wchar_t const _literal
)
{
	return
		_literal;
}

}
}

#endif
