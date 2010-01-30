//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_TIME_SLEEP_INTERRUPTED_HPP_INCLUDED
#define FCPPT_TIME_SLEEP_INTERRUPTED_HPP_INCLUDED

#include <fcppt/time/exception.hpp>
#include <fcppt/string.hpp>
#include <fcppt/symbol.hpp>
#include <fcppt/class_symbol.hpp>

namespace fcppt
{
namespace time
{

class FCPPT_CLASS_SYMBOL sleep_interrupted
:
	public time::exception
{
public:
	FCPPT_SYMBOL sleep_interrupted();
};

}
}

#endif
