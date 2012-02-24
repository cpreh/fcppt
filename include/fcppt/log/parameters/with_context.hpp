//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_LOG_PARAMETERS_WITH_CONTEXT_HPP_INCLUDED
#define FCPPT_LOG_PARAMETERS_WITH_CONTEXT_HPP_INCLUDED

#include <fcppt/symbol.hpp>
#include <fcppt/log/context_fwd.hpp>
#include <fcppt/log/location_fwd.hpp>
#include <fcppt/log/parameters/object.hpp>


namespace fcppt
{
namespace log
{
namespace parameters
{

FCPPT_SYMBOL
fcppt::log::parameters::object
with_context(
	fcppt::log::context &,
	fcppt::log::location const &
);

}
}
}

#endif
