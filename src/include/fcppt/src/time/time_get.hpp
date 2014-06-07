//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_SRC_TIME_TIME_GET_HPP_INCLUDED
#define FCPPT_SRC_TIME_TIME_GET_HPP_INCLUDED

#include <fcppt/char_type.hpp>
#include <fcppt/config/external_begin.hpp>
#include <locale>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace time
{

typedef std::time_get<
	fcppt::char_type
> time_get;

}
}

#endif
