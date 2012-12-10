//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/string.hpp>
#include <fcppt/log/detail/temporary_output.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


fcppt::log::detail::temporary_output::temporary_output()
:
	stream_(
		fcppt::make_unique_ptr<
			fcppt::io::ostringstream
		>()
	)
{
}

fcppt::log::detail::temporary_output::temporary_output(
	fcppt::log::detail::temporary_output &&_other
)
:
	stream_(
		std::move(
			_other.stream_
		)
	)
{
}


fcppt::string const
fcppt::log::detail::temporary_output::result() const
{
	return stream_->str();
}
