//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_PARSE_SKIPPER_SPACE_HPP_INCLUDED
#define FCPPT_PARSE_SKIPPER_SPACE_HPP_INCLUDED

#include <fcppt/parse/space_set.hpp>
#include <fcppt/parse/skipper/char_set.hpp>
#include <fcppt/parse/skipper/operators/repetition.hpp>


namespace fcppt
{
namespace parse
{
namespace skipper
{

inline
auto
space()
{
	return
		*
		fcppt::parse::skipper::char_set{
			fcppt::parse::space_set<
				char
			>()
		};
}

}
}
}

#endif
