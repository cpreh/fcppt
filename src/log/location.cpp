//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/log/location.hpp>
#include <fcppt/text.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/spirit/home/phoenix/core/argument.hpp>
#include <boost/spirit/home/phoenix/operator/arithmetic.hpp>
#include <numeric>
#include <fcppt/config/external_end.hpp>

fcppt::log::location::location()
:
	entries_()
{
}

fcppt::log::location::location(
	fcppt::string const &_initial
)
:
	entries_(
		1u,
		_initial
	)
{}

fcppt::log::location &
fcppt::log::location::operator +=(
	fcppt::string const &_string
)
{
	entries_.push_back(
		_string
	);

	return *this;
}

fcppt::log::location::const_iterator
fcppt::log::location::begin() const
{
	return entries_.begin();
}

fcppt::log::location::const_iterator
fcppt::log::location::end() const
{
	return entries_.end();
}

fcppt::string const
fcppt::log::location::string() const
{
	return
		std::accumulate(
			begin(),
			end(),
			fcppt::string(),
			boost::phoenix::arg_names::arg1
			+ fcppt::string(
				FCPPT_TEXT("::")
			)
			+ boost::phoenix::arg_names::arg2
		);
}

fcppt::log::location const
fcppt::log::operator +(
	log::location _location,
	string const &_string
)
{
	return
		_location += _string;
}
