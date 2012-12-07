//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_SRC_TIME_TIME_GET_PARSE_HPP_INCLUDED
#define FCPPT_SRC_TIME_TIME_GET_PARSE_HPP_INCLUDED

#include <fcppt/io/istream.hpp>
#include <fcppt/src/time/time_get.hpp>
#include <fcppt/config/external_begin.hpp>
#include <ctime>
#include <iosfwd>
#include <istream>
#include <locale>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace time
{

template<
	typename Function
>
fcppt::io::istream &
time_get_parse(
	fcppt::io::istream &_stream,
	std::tm &_result,
	Function const &_function
)
{
	fcppt::io::istream::sentry cerberos(
		_stream
	);

	if(
		!cerberos
	)
		return _stream;

	std::ios_base::iostate err(
		std::ios_base::goodbit
	);

	(
		std::use_facet<
			fcppt::time::time_get
		>(
			_stream.getloc()
		)
		.*_function
	)(
		_stream,
		0,
		_stream,
		err,
		&_result
	);

	_stream.setstate(
		err
	);

	return _stream;
}

}
}

#endif
