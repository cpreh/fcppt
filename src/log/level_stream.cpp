//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/io/ostream.hpp>
#include <fcppt/log/level_stream.hpp>
#include <fcppt/log/detail/temporary_output.hpp>
#include <fcppt/log/format/create_chain.hpp>
#include <fcppt/log/format/function.hpp>


fcppt::log::level_stream::level_stream(
	fcppt::io::ostream &_dest,
	fcppt::log::format::function const &_formatter
)
:
	dest_(
		_dest
	),
	formatter_(
		_formatter
	)
{
}

fcppt::log::level_stream::~level_stream()
{
}

void
fcppt::log::level_stream::log(
	fcppt::log::detail::temporary_output const &_output,
	fcppt::log::format::function const &_additional_formatter
)
{
	dest_
		<<
		fcppt::log::format::create_chain(
			_additional_formatter,
			this->formatter()
		)(
			_output.result()
		);

	dest_.flush();
}

void
fcppt::log::level_stream::formatter(
	fcppt::log::format::function const &_formatter
)
{
	formatter_ = _formatter;
}

fcppt::log::format::function const &
fcppt::log::level_stream::formatter() const
{
	return formatter_;
}
