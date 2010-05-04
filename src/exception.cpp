//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/exception.hpp>

fcppt::exception::exception(
	fcppt::string const &s
)
:
	s(s)
{}

fcppt::exception::exception(
	exception const &e
)
:
	s(e.s)
{}

fcppt::exception &
fcppt::exception::operator=(
	exception const &e
)
{
	s = e.s;
	return *this;
}

fcppt::string const &
fcppt::exception::string() const
{
	return s;
}

char const *
fcppt::exception::what() const throw()
{
	return "what cannot be supplied by an fcppt::exception, do not catch fcppt::exception as std::exception";
}

fcppt::exception::~exception() throw()
{}
