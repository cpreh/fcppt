//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_TIME_TIME_GET_PARSE_HPP_INCLUDED
#define FCPPT_TIME_TIME_GET_PARSE_HPP_INCLUDED

#include "time_get.hpp"
#include <fcppt/io/istream.hpp>
#include <locale>
#include <istream>
#include <iosfwd>
#include <ctime>

namespace fcppt
{
namespace time
{

template<
	typename Function
>
fcppt::io::istream &
time_get_parse(
	io::istream &stream,
	std::tm &result,
	Function const &function
)
{
	io::istream::sentry cerberos(
		stream
	);

	if (!cerberos)
		return stream;

	std::ios_base::iostate err = std::ios_base::goodbit;

	(
		std::use_facet<
			time::time_get
		>(
			stream.getloc()
		)
		.*function
	)(
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

}
}

#endif
