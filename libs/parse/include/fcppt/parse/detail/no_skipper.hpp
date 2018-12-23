//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_PARSE_DETAIL_NO_SKIPPER_HPP_INCLUDED
#define FCPPT_PARSE_DETAIL_NO_SKIPPER_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <iosfwd>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace parse
{
namespace detail
{

class no_skipper
{
public:
	void
	run(
		std::istream &
	) const
	{
	}
};

}
}
}

#endif
