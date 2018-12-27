//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_DETAIL_STRING_LITERAL_HPP_INCLUDED
#define FCPPT_DETAIL_STRING_LITERAL_HPP_INCLUDED

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
	char const *
>
string_literal(
	char const *const _literal,
	wchar_t const *
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
	wchar_t const *
>
string_literal(
	char const *,
	wchar_t const *const _literal
)
{
	return
		_literal;
}

}
}

#endif
