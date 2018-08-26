//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ASSERT_IMPL_EXCEPTION_HPP_INCLUDED
#define FCPPT_ASSERT_IMPL_EXCEPTION_HPP_INCLUDED

#include <fcppt/exception.hpp>
#include <fcppt/assert/information.hpp>
#include <fcppt/assert/make_message.hpp>


inline
fcppt::assert_::exception::exception(
	fcppt::assert_::information const &_information
)
:
	fcppt::exception(
		fcppt::assert_::make_message(
			_information
		)
	),
	information_(
		_information
	)
{
}

inline
fcppt::assert_::information const &
fcppt::assert_::exception::information() const
{
	return
		information_;
}

inline
fcppt::assert_::exception::~exception() noexcept
{
}

#endif
