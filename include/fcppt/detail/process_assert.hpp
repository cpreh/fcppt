//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_DETAIL_PROCESS_ASSERT_HPP_INCLUDED
#define FCPPT_DETAIL_PROCESS_ASSERT_HPP_INCLUDED

#include <fcppt/symbol.hpp>
#include <fcppt/string.hpp>

namespace fcppt
{
namespace detail
{

FCPPT_SYMBOL void
process_assert(
	string const &file,
	string const &line,
	string const &condition,
	string const &message 
);

}
}

#endif
