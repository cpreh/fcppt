//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/endianness/format.hpp>
#include <fcppt/endianness/host_format.hpp>
#include <fcppt/endianness/is_big_endian.hpp>


bool
fcppt::endianness::is_big_endian()
{
	return
		fcppt::endianness::host_format()
		==
		fcppt::endianness::format::big;
}
