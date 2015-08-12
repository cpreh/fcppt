//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/maybe_void.hpp>
#include <fcppt/text.hpp>
#include <fcppt/io/ostream.hpp>
#include <fcppt/log/location.hpp>
#include <fcppt/log/object.hpp>
#include <fcppt/log/optional_location.hpp>
#include <fcppt/log/tree_function.hpp>
#include <fcppt/log/impl/print_locations_function.hpp>
#include <fcppt/config/external_begin.hpp>
#include <ostream>
#include <fcppt/config/external_end.hpp>


fcppt::log::tree_function
fcppt::log::impl::print_locations_function(
	fcppt::io::ostream &_stream
)
{
	return
		fcppt::log::tree_function{
			[
				&_stream
			](
				fcppt::log::object const &_object
			)
			{
				fcppt::maybe_void(
					_object.location(),
					[
						&_stream
					](
						fcppt::log::location const &_location
					)
					{
						_stream
							<< _location.string()
							<< FCPPT_TEXT('\n');
					}
				);
			}
		};
}
