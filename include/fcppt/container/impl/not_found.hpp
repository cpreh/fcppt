//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_IMPL_NOT_FOUND_HPP_INCLUDED
#define FCPPT_CONTAINER_IMPL_NOT_FOUND_HPP_INCLUDED

inline
fcppt::container::not_found::not_found(
	fcppt::string const &_error
)
:
	container::exception(
		_error
	)
{}

#endif
