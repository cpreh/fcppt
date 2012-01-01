//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/make_shared_ptr.hpp>
#include <fcppt/log/detail/temporary_output.hpp>


fcppt::log::detail::temporary_output::temporary_output()
:
	stream_(
		fcppt::make_shared_ptr<
			io::ostringstream
		>()
	)
{}

fcppt::string const
fcppt::log::detail::temporary_output::result() const
{
	return stream_->str();
}
