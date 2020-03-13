//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CAST_BAD_DYNAMIC_HPP_INCLUDED
#define FCPPT_CAST_BAD_DYNAMIC_HPP_INCLUDED

#include <fcppt/exception.hpp>
#include <fcppt/cast/bad_dynamic_fwd.hpp>
#include <fcppt/detail/symbol.hpp>
#include <fcppt/symbol/class.hpp>
#include <fcppt/config/external_begin.hpp>
#include <typeindex>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace cast
{

/**
\brief May be thrown by #fcppt::cast::dynamic  if the cast fails

\ingroup fcpptcasts

This class provides more type information than <code>std::bad_cast</code> does.
It stores an std::type_index for the source and the destination type.

\see fcppt::cast::dynamic
*/
class FCPPT_SYMBOL_CLASS bad_dynamic
:
	public fcppt::exception
{
public:
	/**
	\brief Constructs a bad_dynamic_cast exception

	\param source The source type information

	\param dest The destination type information
	*/
	FCPPT_DETAIL_SYMBOL
	bad_dynamic(
		std::type_index const &source,
		std::type_index const &dest
	);

	FCPPT_DETAIL_SYMBOL
	bad_dynamic(
		bad_dynamic const &
	);

	FCPPT_DETAIL_SYMBOL
	bad_dynamic(
		bad_dynamic &&
	)
	noexcept;

	FCPPT_DETAIL_SYMBOL
	bad_dynamic &
	operator=(
		bad_dynamic const &
	);

	FCPPT_DETAIL_SYMBOL
	bad_dynamic &
	operator=(
		bad_dynamic &&
	)
	noexcept;

	FCPPT_DETAIL_SYMBOL
	~bad_dynamic() noexcept
	override;

	/**
	\brief Returns the source type information
	*/
	[[nodiscard]]
	FCPPT_DETAIL_SYMBOL
	std::type_index const &
	source() const;

	/**
	\brief Returns the destination type information
	*/
	[[nodiscard]]
	FCPPT_DETAIL_SYMBOL
	std::type_index const &
	destination() const;
private:
	std::type_index
		source_,
		destination_;
};

}
}

#endif
