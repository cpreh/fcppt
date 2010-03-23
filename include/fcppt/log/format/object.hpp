//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_LOG_FORMAT_OBJECT_HPP_INCLUDED
#define FCPPT_LOG_FORMAT_OBJECT_HPP_INCLUDED

#include <fcppt/string.hpp>
#include <fcppt/symbol.hpp>
#include <fcppt/class_symbol.hpp>
#include <fcppt/noncopyable.hpp>

namespace fcppt
{
namespace log
{
namespace format
{

/// The base formatter class
/**
 * Every formatter has a function `string format(string)`
 * that is used to format the given text.
*/
class FCPPT_CLASS_SYMBOL object
{
	FCPPT_NONCOPYABLE(object)
protected:
	FCPPT_SYMBOL object();
public:
	virtual string const
	format(
		string const &
	) const = 0;

	FCPPT_SYMBOL virtual ~object();
};

}
}
}

#endif
