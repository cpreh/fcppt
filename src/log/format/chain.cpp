//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/string.hpp>
#include <fcppt/log/format/chain.hpp>
#include <fcppt/log/format/function.hpp>


fcppt::string const
fcppt::log::format::chain(
	fcppt::log::format::function const &_parent,
	fcppt::log::format::function const &_child,
	fcppt::string const &_string
)
{
	return
		_parent(
			_child(
				_string
			)
		);
}
