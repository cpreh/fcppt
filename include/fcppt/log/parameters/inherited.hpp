//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_LOG_PARAMETERS_INHERITED_HPP_INCLUDED
#define FCPPT_LOG_PARAMETERS_INHERITED_HPP_INCLUDED

#include <fcppt/log/parameters/all.hpp>
#include <fcppt/log/object_fwd.hpp>
#include <fcppt/string.hpp>
#include <fcppt/symbol.hpp>

namespace fcppt
{
namespace log
{
namespace parameters
{

/// Constructs parameters for an inherited logger.
/**
 * @param parent The logger's parent class.
 * @param sub_location The logger's associated string.
*/
FCPPT_SYMBOL all const
inherited(
	object &parent,
	string const &sub_location
);

}
}
}

#endif
