//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_PARSE_POSITION_HPP_INCLUDED
#define FCPPT_PARSE_POSITION_HPP_INCLUDED

#include <fcppt/optional/object_impl.hpp>
#include <fcppt/parse/line_number.hpp>
#include <fcppt/config/external_begin.hpp>
#include <istream>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace parse
{

template<
	typename Ch
>
using
position
=
std::pair<
	typename
	std::basic_istream<
		Ch
	>::pos_type,
	fcppt::optional::object<
		fcppt::parse::line_number
	>
>;

}
}

#endif
