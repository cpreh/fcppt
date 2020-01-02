//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_PARSE_SPACE_SKIPPER_HPP_INCLUDED
#define FCPPT_PARSE_SPACE_SKIPPER_HPP_INCLUDED

#include <fcppt/parse/make_skipper.hpp>
#include <fcppt/parse/space.hpp>


namespace fcppt
{
namespace parse
{

inline
auto
space_skipper()
{
	return
		fcppt::parse::make_skipper(
			fcppt::parse::space()
		);
}

}
}

#endif
