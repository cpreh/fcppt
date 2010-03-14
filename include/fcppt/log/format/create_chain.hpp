//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_LOG_FORMAT_CREATE_CHAIN_HPP_INCLUDED
#define FCPPT_LOG_FORMAT_CREATE_CHAIN_HPP_INCLUDED

#include <fcppt/log/format/object_ptr.hpp>
#include <fcppt/symbol.hpp>

namespace fcppt
{
namespace log
{
namespace format
{

/// Factory for creating format::chain
/**
 * @see format::chain
*/
FCPPT_SYMBOL const_object_ptr const
create_chain(
	const_object_ptr parent,
	const_object_ptr child
);

}
}
}

#endif
