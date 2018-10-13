//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_VARIANT_EXCEPTION_HPP_INCLUDED
#define FCPPT_VARIANT_EXCEPTION_HPP_INCLUDED

#include <fcppt/string.hpp>
#include <fcppt/exception.hpp>
#include <fcppt/detail/symbol.hpp>
#include <fcppt/symbol/class.hpp>
#include <fcppt/variant/exception_fwd.hpp>


namespace fcppt
{
namespace variant
{

/**
\brief The base exception class for variant exceptions

\ingroup fcpptvariant
*/
class FCPPT_SYMBOL_CLASS exception
:
	public fcppt::exception
{
public:
	FCPPT_DETAIL_SYMBOL
	explicit
	exception(
		fcppt::string &&
	);

	FCPPT_DETAIL_SYMBOL
	exception(
		exception const &
	);

	FCPPT_DETAIL_SYMBOL
	exception(
		exception &&
	);

	FCPPT_DETAIL_SYMBOL
	exception &
	operator=(
		exception const &
	);

	FCPPT_DETAIL_SYMBOL
	exception &
	operator=(
		exception &&
	);

	FCPPT_DETAIL_SYMBOL
	~exception() noexcept
	override;
};

}
}

#endif
