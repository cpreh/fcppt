//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALGORITHM_JOIN_STRINGS_HPP_INCLUDED
#define FCPPT_ALGORITHM_JOIN_STRINGS_HPP_INCLUDED

#include <fcppt/string.hpp>
#include <boost/foreach.hpp>

namespace fcppt
{
namespace algorithm
{
template<typename Range>
string const join_strings(
	Range const &r,
	string const &delim)
{
	string s;
	BOOST_FOREACH(string const &n,r)
		s += n+delim;
	s.erase(s.length()-delim.length());
	return s;
}
}
}

#endif
