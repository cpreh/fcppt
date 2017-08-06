//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/string.hpp>
#include <fcppt/text.hpp>
#include <fcppt/algorithm/fold.hpp>
#include <fcppt/log/location.hpp>
#include <fcppt/log/name.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


fcppt::log::location::location()
:
	entries_()
{
}

fcppt::log::location::location(
	fcppt::log::name _initial
)
:
	entries_(
		1u,
		std::move(
			_initial.get()
		)
	)
{
}

fcppt::log::location &
fcppt::log::location::operator /=(
	fcppt::log::name _string
)
{
	entries_.push_back(
		std::move(
			_string.get()
		)
	);

	return
		*this;
}

fcppt::log::location::const_iterator
fcppt::log::location::begin() const
{
	return
		entries_.begin();
}

fcppt::log::location::const_iterator
fcppt::log::location::end() const
{
	return
		entries_.end();
}

fcppt::string
fcppt::log::location::string() const
{
	return
		fcppt::algorithm::fold(
			*this,
			fcppt::string(),
			[](
				fcppt::string const &_state,
				fcppt::string const &_elem
			)
			{
				return
					_state
					+
					FCPPT_TEXT("::")
					+
					_elem
					;
			}
		);
}

fcppt::log::location
fcppt::log::operator /(
	log::location _location,
	fcppt::log::name _string
)
{
	return
		_location /=
			std::move(
				_string
			);
}
