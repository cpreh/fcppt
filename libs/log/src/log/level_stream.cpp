//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/const.hpp>
#include <fcppt/identity.hpp>
#include <fcppt/make_ref.hpp>
#include <fcppt/io/ostream_fwd.hpp>
#include <fcppt/log/level_stream.hpp>
#include <fcppt/log/detail/temporary_output.hpp>
#include <fcppt/log/format/chain.hpp>
#include <fcppt/log/format/optional_function.hpp>
#include <fcppt/optional/from.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


fcppt::log::level_stream::level_stream(
	fcppt::io::ostream &_dest,
	fcppt::log::format::optional_function &&_formatter
)
:
	dest_(
		_dest
	),
	formatter_(
		std::move(
			_formatter
		)
	)
{
}

void
fcppt::log::level_stream::log(
	fcppt::log::detail::temporary_output const &_output,
	fcppt::log::format::optional_function const &_additional_formatter
) const
{
	dest_.get()
		<<
		fcppt::optional::from(
			fcppt::log::format::chain(
				_additional_formatter,
				this->formatter()
			),
			fcppt::const_(
				fcppt::log::format::function(
					fcppt::identity{}
				)
			)
		)(
			_output.result()
		);

	dest_.get().flush();
}

void
fcppt::log::level_stream::sink(
	fcppt::io::ostream &_stream
)
{
	dest_ =
		fcppt::make_ref(
			_stream
		);
}

fcppt::io::ostream &
fcppt::log::level_stream::get()
{
	return
		dest_.get();
}

fcppt::log::format::optional_function const &
fcppt::log::level_stream::formatter() const
{
	return
		formatter_;
}
