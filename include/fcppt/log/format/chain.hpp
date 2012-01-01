//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_LOG_FORMAT_CHAIN_HPP_INCLUDED
#define FCPPT_LOG_FORMAT_CHAIN_HPP_INCLUDED

#include <fcppt/noncopyable.hpp>
#include <fcppt/string.hpp>
#include <fcppt/symbol.hpp>
#include <fcppt/log/format/const_object_ptr.hpp>
#include <fcppt/log/format/object.hpp>


namespace fcppt
{
namespace log
{
namespace format
{

/// A formatter chain that applies two formatters
/**
 * The parent formatter is used first, and the child formatter second
*/
class FCPPT_CLASS_SYMBOL chain
:
	public format::object
{
	FCPPT_NONCOPYABLE(
		chain
	);
public:
	FCPPT_SYMBOL
	chain(
		format::const_object_ptr parent,
		format::const_object_ptr child
	);

	FCPPT_SYMBOL
	~chain();

	FCPPT_SYMBOL
	fcppt::string const
	format(
		fcppt::string const &
	) const;
private:
	format::const_object_ptr const
		parent_,
		child_;
};

}
}
}

#endif
