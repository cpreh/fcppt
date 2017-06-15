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
	fcppt::string const &_string
)
:
	string_(
		_string
	)
{
}

inline
fcppt::exception::exception(
	exception const &_exception
)
:
	std::exception(),
	string_(
		_exception.string_
	)
{
}

inline
fcppt::exception &
fcppt::exception::operator=(
	fcppt::exception const &_exception
)
{
	string_ = _exception.string_;

	return *this;
}

inline
fcppt::string const &
fcppt::exception::string() const
{
	return string_;
}

inline
char const *
fcppt::exception::what() const throw()
{
	return "what cannot be supplied by an fcppt::exception, do not catch fcppt::exception as std::exception";
}

inline
fcppt::exception::~exception() throw()
{
}

#endif
