//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ASSERT_EXCEPTION_HPP_INCLUDED
#define FCPPT_ASSERT_EXCEPTION_HPP_INCLUDED

#include <fcppt/exception.hpp>
#include <fcppt/assert/exception_fwd.hpp>
#include <fcppt/assert/information.hpp>
#include <fcppt/detail/symbol.hpp>
#include <fcppt/symbol/class.hpp>


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
class FCPPT_SYMBOL_CLASS exception
:
	public fcppt::exception
{
public:
	FCPPT_DETAIL_SYMBOL
	explicit
	exception(
		fcppt::assert_::information const &
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

	[[nodiscard]]
	FCPPT_DETAIL_SYMBOL
	fcppt::assert_::information const &
	information() const;
private:
	fcppt::assert_::information information_;
};

}
}

#endif
