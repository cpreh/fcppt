//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/log/level_stream.hpp>
#include <fcppt/log/temporary_output.hpp>
#include <fcppt/log/format/create_chain.hpp>
#include <fcppt/log/format/object.hpp>

fcppt::log::level_stream::level_stream(
	io::ostream &dest_,
	format::const_object_ptr const formatter_
)
:
	dest_(dest_),
	formatter_(formatter_)
{}

fcppt::log::level_stream::~level_stream()
{}

void
fcppt::log::level_stream::log(
	temporary_output const &output,
	format::const_object_ptr const additional_formatter
)
{
	dest_
		<< format::create_chain(
			additional_formatter,
			formatter()
		)->format(
			output.result()
		);

	dest_.flush();
}

void
fcppt::log::level_stream::formatter(
	format::const_object_ptr const new_formatter
)
{
	formatter_ = new_formatter;
}

fcppt::log::format::const_object_ptr const
fcppt::log::level_stream::formatter() const
{
	return formatter_;
}
