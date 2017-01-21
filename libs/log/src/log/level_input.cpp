//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/string.hpp>
#include <fcppt/io/extract.hpp>
#include <fcppt/io/istream_fwd.hpp>
#include <fcppt/log/level.hpp>
#include <fcppt/log/level_input.hpp>
#include <fcppt/log/level_from_string.hpp>
#include <fcppt/optional/maybe.hpp>
#include <fcppt/optional/maybe_void.hpp>
#include <fcppt/config/external_begin.hpp>
#include <ios>
#include <fcppt/config/external_end.hpp>


fcppt::io::istream &
fcppt::log::operator>>(
	fcppt::io::istream &_stream,
	fcppt::log::level &_level
)
{
	fcppt::optional::maybe_void(
		fcppt::io::extract<
			fcppt::string
		>(
			_stream
		),
		[
			&_level,
			&_stream
		](
			fcppt::string const &_value
		)
		{
			fcppt::optional::maybe(
				fcppt::log::level_from_string(
					_value
				),
				[
					&_stream
				]{
					_stream.setstate(
						std::ios_base::failbit
					);
				},
				[
					&_level
				](
					fcppt::log::level const _result
				)
				{
					_level =
						_result;
				}
			);
		}
	);

	return
		_stream;
}
