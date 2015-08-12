//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/format.hpp>
#include <fcppt/string.hpp>
#include <fcppt/log/format/inserter.hpp>
#include <fcppt/log/format/function.hpp>


fcppt::log::format::function
fcppt::log::format::inserter(
	fcppt::string const &_format
)
{
	return
		fcppt::log::format::function(
			[
				_format
			](
				fcppt::string const &_text
			)
			-> fcppt::string
			{
				return
					(
						fcppt::format(
							_format
						)
						%
						_text
					).str();
			}
		);
}
