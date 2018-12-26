//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_PARSE_DETAIL_SINGLE_CHAR_HPP_INCLUDED
#define FCPPT_PARSE_DETAIL_SINGLE_CHAR_HPP_INCLUDED

#include <fcppt/parse/basic_char_set_fwd.hpp>
#include <fcppt/parse/basic_literal_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace parse
{
namespace detail
{

template<
	typename
>
struct single_char
:
std::false_type
{
};

template<
	typename Ch
>
struct single_char<
	fcppt::parse::basic_literal<
		Ch
	>
>
:
std::true_type
{
};

template<
	typename Ch
>
struct single_char<
	fcppt::parse::basic_char_set<
		Ch
	>
>
:
std::true_type
{
};

}
}
}

#endif
