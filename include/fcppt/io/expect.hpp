//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_IO_EXPECT_HPP_INCLUDED
#define FCPPT_IO_EXPECT_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <ios>
#include <istream>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace io
{

/**
\brief Fails a stream if it does not read the expected value

\ingroup fcpptio

Tries to read a value of type \a Type from \a _stream. If the value read is
unequal to \a _value, the failbit is set for \a _stream.

\tparam Type Must be a fundamental type
*/
template<
	typename Ch,
	typename Traits,
	typename Type
>
inline
std::basic_istream<
	Ch,
	Traits
> &
expect(
	std::basic_istream<
		Ch,
		Traits
	> &_stream,
	Type const &_value
)
{
	Type temp;

	if(
		_stream
			>> temp
		&&
		temp
		!=
		_value
	)
		_stream.setstate(
			std::ios_base::failbit
		);

	return
		_stream;
}

}
}

#endif
