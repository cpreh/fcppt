//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_IMPL_EXCEPTION_HPP_INCLUDED
#define FCPPT_IMPL_EXCEPTION_HPP_INCLUDED

#include <fcppt/string.hpp>
#include <fcppt/config/external_begin.hpp>
#include <exception>
#include <fcppt/config/external_end.hpp>


inline
fcppt::exception::exception(
	fcppt::string &&_string
)
:
	string_(
		std::move(
			_string
		)
	)
{
}

inline
fcppt::exception::exception(
	exception const &
)
= default;

inline
fcppt::exception::exception(
	exception &&
)
= default;

inline
fcppt::exception &
fcppt::exception::operator=(
	fcppt::exception const &
)
= default;

inline
fcppt::exception &
fcppt::exception::operator=(
	fcppt::exception &&
)
= default;

inline
fcppt::string const &
fcppt::exception::string() const
{
	return
		string_;
}

inline
char const *
fcppt::exception::what() const noexcept
{
	return "what cannot be supplied by an fcppt::exception, do not catch fcppt::exception as std::exception";
}

inline
fcppt::exception::~exception() noexcept
{
}

#endif
