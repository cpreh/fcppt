//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/string.hpp>
#include <fcppt/log/format/function.hpp>
#include <fcppt/log/format/inserter.hpp>
#include <fcppt/log/format/prefix_string.hpp>
#include <fcppt/log/format/suffix_string.hpp>


fcppt::log::format::function
fcppt::log::format::inserter(
	fcppt::log::format::prefix_string const &_prefix,
	fcppt::log::format::suffix_string const &_suffix
)
{
	return
		fcppt::log::format::function(
			[
				_prefix,
				_suffix
			](
				fcppt::string const &_text
			)
			-> fcppt::string
			{
				return
					_prefix.get()
					+
					_text
					+
					_suffix.get();
			}
		);
}
