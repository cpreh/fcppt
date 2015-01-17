//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/text.hpp>
#include <fcppt/io/ostream.hpp>
#include <fcppt/log/object.hpp>
#include <fcppt/log/optional_location.hpp>
#include <fcppt/log/tree_function.hpp>
#include <fcppt/src/log/print_locations_function.hpp>
#include <fcppt/config/external_begin.hpp>
#include <ostream>
#include <fcppt/config/external_end.hpp>


fcppt::log::tree_function
fcppt::log::print_locations_function(
	fcppt::io::ostream &_stream
)
{
	return
		[
			&_stream
		](
			fcppt::log::object const &_object
		)
		{
			_stream
				<< _object.location()->string()
				<< FCPPT_TEXT('\n');
		};
}
