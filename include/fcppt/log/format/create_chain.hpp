//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_LOG_FORMAT_CREATE_CHAIN_HPP_INCLUDED
#define FCPPT_LOG_FORMAT_CREATE_CHAIN_HPP_INCLUDED

#include <fcppt/symbol.hpp>
#include <fcppt/log/format/function.hpp>


namespace fcppt
{
namespace log
{
namespace format
{

/// Factory for creating format::chain
/**
 * At least one of parent and child must not be zero
 * @see format::chain
*/
FCPPT_SYMBOL
fcppt::log::format::function const
create_chain(
	fcppt::log::format::function const &parent,
	fcppt::log::format::function const &child
);

}
}
}

#endif
