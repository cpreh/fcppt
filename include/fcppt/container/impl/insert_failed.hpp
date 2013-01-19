//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_IMPL_INSERT_FAILED_HPP_INCLUDED
#define FCPPT_CONTAINER_IMPL_INSERT_FAILED_HPP_INCLUDED

inline
fcppt::container::insert_failed::insert_failed(
	fcppt::string const &_error
)
:
	container::exception(
		_error
	)
{}

#endif
