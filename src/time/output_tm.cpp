//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/io/ostream.hpp>
#include <fcppt/time/output_tm.hpp>
#include <fcppt/config/external_begin.hpp>
#include <ctime>
#include <iterator>
#include <locale>
#include <ostream>
#include <fcppt/config/external_end.hpp>


fcppt::io::ostream &
fcppt::time::output_tm(
	io::ostream &_stream,
	std::tm const &_tm
)
{
	io::ostream::sentry cerberos(
		_stream
	);

	if(
		!cerberos
	)
		return _stream;

	std::use_facet<
		std::time_put<
			fcppt::io::ostream::char_type,
			std::ostreambuf_iterator<
				fcppt::io::ostream::char_type,
				fcppt::io::ostream::traits_type
			>
		>
	>(
		_stream.getloc()
	).put(
		_stream,
		_stream,
		_stream.fill(),
		&_tm,
		'c'
	);

	return _stream;
}
