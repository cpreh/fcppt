//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_LOG_PARAMETERS_WITH_CONTEXT_HPP_INCLUDED
#define FCPPT_LOG_PARAMETERS_WITH_CONTEXT_HPP_INCLUDED

#include <fcppt/symbol.hpp>
#include <fcppt/io/ostream.hpp>
#include <fcppt/log/context_fwd.hpp>
#include <fcppt/log/location_fwd.hpp>
#include <fcppt/log/parameters/all.hpp>


namespace fcppt
{
namespace log
{
namespace parameters
{

FCPPT_SYMBOL
parameters::all
with_context(
	log::context &,
	io::ostream &,
	log::location const &
);

}
}
}

#endif
