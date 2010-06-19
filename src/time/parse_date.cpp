//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/time/parse_date.hpp>
#include <fcppt/char_type.hpp>
#include <istream>
#include <locale>
#include <iosfwd>

fcppt::io::istream &
fcppt::time::parse_date(
	io::istream &stream,
	std::tm &result
)
{
	io::istream::sentry cerberos(
		stream
	);

	if (!cerberos)
		return stream;

	std::ios_base::iostate err = std::ios_base::goodbit;

	std::use_facet<
		std::time_get<
			char_type
		>
	>(
		stream.getloc()
	)
	.get_date(
		stream,
		0,
		stream,
		err,
		&result
	);

	stream.setstate(
		err
	);

	return stream;
}
