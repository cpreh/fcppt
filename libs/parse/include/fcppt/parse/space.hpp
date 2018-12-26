//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_PARSE_SPACE_HPP_INCLUDED
#define FCPPT_PARSE_SPACE_HPP_INCLUDED

#include <fcppt/parse/char_set.hpp>


namespace fcppt
{
namespace parse
{

// TODO: Should this be inline?
inline
fcppt::parse::char_set
space()
{
	return
		fcppt::parse::char_set{
			' ',
			'\n',
			'\t'
		};
}

}
}

#endif
