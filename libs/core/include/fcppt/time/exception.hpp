//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_TIME_EXCEPTION_HPP_INCLUDED
#define FCPPT_TIME_EXCEPTION_HPP_INCLUDED

#include <fcppt/exception.hpp>
#include <fcppt/string.hpp>
#include <fcppt/detail/symbol.hpp>
#include <fcppt/symbol/class.hpp>
#include <fcppt/time/exception_fwd.hpp>


namespace fcppt
{
namespace time
{

/**
\brief The exception base class for time exceptions

\ingroup fcppttime
*/
class FCPPT_SYMBOL_CLASS exception
:
	public fcppt::exception
{
public:
	/**
	\brief Constructs the exception given an error message

	Constructs the exception give \a message

	\param message The message of the exception
	*/
	FCPPT_DETAIL_SYMBOL
	explicit
	exception(
		fcppt::string &&message
	);

	FCPPT_DETAIL_SYMBOL
	exception(
		exception const &
	);

	FCPPT_DETAIL_SYMBOL
	exception(
		exception &&
	)
	noexcept;

	FCPPT_DETAIL_SYMBOL
	exception &
	operator=(
		exception const &
	);

	FCPPT_DETAIL_SYMBOL
	exception &
	operator=(
		exception &&
	)
	noexcept;

	FCPPT_DETAIL_SYMBOL
	~exception() noexcept
	override;
};

}
}

#endif
