//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_PARSE_IS_PARSER_HPP_INCLUDED
#define FCPPT_PARSE_IS_PARSER_HPP_INCLUDED

#include <fcppt/parse/tag.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace parse
{

template<
	typename Type
>
using
is_parser
=
std::is_base_of<
	fcppt::parse::tag,
	Type
>;

}
}

#endif
