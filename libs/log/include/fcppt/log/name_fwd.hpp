//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_LOG_NAME_FWD_HPP_INCLUDED
#define FCPPT_LOG_NAME_FWD_HPP_INCLUDED

#include <fcppt/make_strong_typedef.hpp>
#include <fcppt/string.hpp>


namespace fcppt
{
namespace log
{

/**
\brief The name of a logger

\ingroup fcpptlog
*/
FCPPT_MAKE_STRONG_TYPEDEF(
	fcppt::string,
	name
);

}
}

#endif
