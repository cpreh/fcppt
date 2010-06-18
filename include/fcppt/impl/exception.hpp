//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_IMPL_EXCEPTION_HPP_INCLUDED
#define FCPPT_IMPL_EXCEPTION_HPP_INCLUDED

inline 
fcppt::exception::exception(
	fcppt::string const &s
)
:
	s(s)
{}

inline 
fcppt::exception::exception(
	exception const &e
)
:
	std::exception(),
	s(e.s)
{}

inline 
fcppt::exception &
fcppt::exception::operator=(
	exception const &e
)
{
	s = e.s;
	return *this;
}

inline 
fcppt::string const &
fcppt::exception::string() const
{
	return s;
}

inline 
char const *
fcppt::exception::what() const throw()
{
	return "what cannot be supplied by an fcppt::exception, do not catch fcppt::exception as std::exception";
}

inline 
fcppt::exception::~exception() throw()
{}

#endif
