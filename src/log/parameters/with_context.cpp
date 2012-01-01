//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/io/ostream.hpp>
#include <fcppt/log/context_fwd.hpp>
#include <fcppt/log/context_location.hpp>
#include <fcppt/log/location_fwd.hpp>
#include <fcppt/log/parameters/all.hpp>
#include <fcppt/log/parameters/with_context.hpp>


fcppt::log::parameters::all
fcppt::log::parameters::with_context(
	log::context &_context,
	io::ostream &_stream,
	log::location const &_location
)
{
	return
		log::parameters::all(
			_stream
		)
		.context_location(
			log::context_location(
				_context,
				_location
			)
		);
}
