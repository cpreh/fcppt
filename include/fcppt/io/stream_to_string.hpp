//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_IO_STREAM_TO_STRING_HPP_INCLUDED
#define FCPPT_IO_STREAM_TO_STRING_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <istream>
#include <sstream>
#include <string>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace io
{

/// Extracts a string from @a _stream
template<
	typename Ch,
	typename Traits
>
std::basic_string<
	Ch,
	Traits
> const
stream_to_string(
	std::basic_istream<
		Ch,
		Traits
	> &_stream
)
{
	std::basic_stringstream<
		Ch,
		Traits
	> string_stream;

	string_stream << _stream.rdbuf();

	return string_stream.str();
}

}
}

#endif
