//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/io/write.hpp>
#include <fcppt/endianness/format.hpp>
#include <sstream>

int main()
{
	std::ostringstream stream;

	fcppt::io::write(
		stream,
		42u,
		fcppt::endianness::format::big
	);
}
