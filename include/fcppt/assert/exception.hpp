//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ASSERT_EXCEPTION_HPP_INCLUDED
#define FCPPT_ASSERT_EXCEPTION_HPP_INCLUDED

#include <fcppt/assert/information.hpp>
#include <fcppt/exception.hpp>

namespace fcppt
{
namespace assert_
{

/**
\brief An exception class that can be used with throwing assertions

\ingroup fcpptassert

This class can be used with throwing assertions if you don't want to define
your own exception type. It takes an fcppt::assert_::information in its
constructor.
*/
class exception
:
	public fcppt::exception
{
public:
	/**
	\brief Constructs the exception

	Constructs the exception from \a information.

	\param information The assert information
	*/
	explicit
	exception(
		fcppt::assert_::information const &information
	);

	/**
	\brief Returns the assert information
	*/
	fcppt::assert_::information const &
	information() const;

	/**
	\brief Destroys the exception
	*/
	~exception() throw();
private:
	fcppt::assert_::information information_;
};

}
}

#include <fcppt/assert/impl/exception.hpp>

#endif
