//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONS_EXCEPTION_HPP_INCLUDED
#define FCPPT_OPTIONS_EXCEPTION_HPP_INCLUDED

#include <fcppt/exception.hpp>
#include <fcppt/string.hpp>
#include <fcppt/options/exception_fwd.hpp>
#include <fcppt/options/detail/symbol.hpp>
#include <fcppt/symbol/class.hpp>


namespace fcppt
{
namespace options
{

class FCPPT_SYMBOL_CLASS exception
:
	public fcppt::exception
{
public:
	FCPPT_OPTIONS_DETAIL_SYMBOL
	explicit
	exception(
		fcppt::string &&
	);

	FCPPT_OPTIONS_DETAIL_SYMBOL
	exception(
		exception const &
	);

	FCPPT_OPTIONS_DETAIL_SYMBOL
	exception(
		exception &&
	);

	FCPPT_OPTIONS_DETAIL_SYMBOL
	exception &
	operator=(
		exception const &
	);

	FCPPT_OPTIONS_DETAIL_SYMBOL
	exception &
	operator=(
		exception &&
	);

	FCPPT_OPTIONS_DETAIL_SYMBOL
	~exception() noexcept
	override;
};

}
}

#endif
