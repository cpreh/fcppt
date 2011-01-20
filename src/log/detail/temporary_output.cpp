//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/log/detail/temporary_output.hpp>
#include <fcppt/make_shared_ptr.hpp>

fcppt::log::detail::temporary_output::temporary_output()
:
	os(
		make_shared_ptr<
			io::ostringstream
		>()
	)
{}

fcppt::string const
fcppt::log::detail::temporary_output::result() const
{
	return os->str();
}
