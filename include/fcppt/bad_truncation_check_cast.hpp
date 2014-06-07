//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_BAD_TRUNCATION_CHECK_CAST_HPP_INCLUDED
#define FCPPT_BAD_TRUNCATION_CHECK_CAST_HPP_INCLUDED

#include <fcppt/exception.hpp>
#include <fcppt/string.hpp>
#include <fcppt/config/external_begin.hpp>
#include <typeindex>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{

/**
\brief May be thrown by \link fcppt::truncation_check_cast \endlink if the
conversion truncates

\ingroup fcpptcasts

This class provides type information about the source and the destination
types, stored as std::type_index.

\see fcppt::truncation_check_cast
*/
class bad_truncation_check_cast
:
	public fcppt::exception
{
public:
	/**
	\brief Constructs a bad_truncation_check_cast exception

	\param source_value The value to cast from

	\param source The source type information

	\param dest The destination type information
	*/
	bad_truncation_check_cast(
		fcppt::string const &source_value,
		std::type_index const &source,
		std::type_index const &dest
	);

	/**
	\brief Returns the source type information
	*/
	std::type_index const &
	source() const;

	/**
	\brief Returns the destination type information
	*/
	std::type_index const &
	destination() const;
private:
	std::type_index
		source_,
		destination_;
};

}

#include <fcppt/impl/bad_truncation_check_cast.hpp>

#endif
