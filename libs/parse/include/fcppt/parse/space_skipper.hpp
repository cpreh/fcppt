//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_PARSE_SPACE_SKIPPER_HPP_INCLUDED
#define FCPPT_PARSE_SPACE_SKIPPER_HPP_INCLUDED

#include <fcppt/parse/make_ignore.hpp>
#include <fcppt/parse/space.hpp>
#include <fcppt/parse/operators/repetition.hpp>


namespace fcppt
{
namespace parse
{

inline
auto
space_skipper()
{
	return
		fcppt::parse::make_ignore(
			*fcppt::parse::space()
		);
}

}
}

#endif
