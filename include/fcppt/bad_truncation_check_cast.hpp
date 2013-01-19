//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_BAD_TRUNCATION_CHECK_CAST_HPP_INCLUDED
#define FCPPT_BAD_TRUNCATION_CHECK_CAST_HPP_INCLUDED

#include <fcppt/exception.hpp>
#include <fcppt/string.hpp>
#include <fcppt/type_info.hpp>


namespace fcppt
{

/**
\brief May be thrown by \link fcppt::truncation_check_cast \endlink if the
conversion truncates

\ingroup fcpptcasts

This class provides type information about the source and the destination
types, stored as \link fcppt::type_info \endlink.

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
		fcppt::type_info const &source,
		fcppt::type_info const &dest
	);

	/**
	\brief Returns the source type information
	*/
	fcppt::type_info const &
	source() const;

	/**
	\brief Returns the destination type information
	*/
	fcppt::type_info const &
	destination() const;
private:
	fcppt::type_info
		source_,
		destination_;
};

}

#include <fcppt/impl/bad_truncation_check_cast.hpp>

#endif
