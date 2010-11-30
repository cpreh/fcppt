//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_LOG_FORMAT_INSERTER_HPP_INCLUDED
#define FCPPT_LOG_FORMAT_INSERTER_HPP_INCLUDED

#include <fcppt/log/format/object.hpp>
#include <fcppt/string.hpp>
#include <fcppt/symbol.hpp>

namespace fcppt
{
namespace log
{
namespace format
{

/// A formatter that inserts text using fcppt::format
class FCPPT_CLASS_SYMBOL inserter
:
	public object
{
public:
	FCPPT_SYMBOL explicit inserter(
		string const &format_string
	);

	FCPPT_SYMBOL string const
	format(
		string const &
	) const;
private:
	string const format_string_;
};

}
}
}

#endif
