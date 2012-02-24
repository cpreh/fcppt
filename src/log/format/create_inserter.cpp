//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/string.hpp>
#include <fcppt/log/format/create_inserter.hpp>
#include <fcppt/log/format/function.hpp>
#include <fcppt/log/format/inserter.hpp>
#include <fcppt/tr1/functional.hpp>


fcppt::log::format::function const
fcppt::log::format::create_inserter(
	fcppt::string const &_format
)
{
	return
		fcppt::log::format::function(
			std::tr1::bind(
				fcppt::log::format::inserter,
				_format,
				std::tr1::placeholders::_1
			)
		);
}
