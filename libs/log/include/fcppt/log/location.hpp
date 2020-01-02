//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_LOG_LOCATION_HPP_INCLUDED
#define FCPPT_LOG_LOCATION_HPP_INCLUDED

#include <fcppt/string.hpp>
#include <fcppt/log/location_fwd.hpp>
#include <fcppt/log/name_fwd.hpp>
#include <fcppt/log/detail/location_vector.hpp>
#include <fcppt/log/detail/symbol.hpp>


namespace fcppt
{
namespace log
{

/**
\brief A location of a logger in a context.

\ingroup fcpptlog

A logger's location is represented by a vector of strings. Each entry in the
vector describes an edge in the tree. The nodes of the tree are notated by
double colons, so for example a location of <code>"::root::child"</code>
denotes a logger that is below the child level, which in turn is below the root
level.
*/
class location
{
public:
	/**
	\brief Constructs an empty location
	*/
	FCPPT_LOG_DETAIL_SYMBOL
	location();

	/**
	\brief Constructs a location with one element

	Constructs a location with one element given by \a root

	\param root The root element
	*/
	FCPPT_LOG_DETAIL_SYMBOL
	explicit
	location(
		fcppt::log::name root
	);

	/**
	\brief The iterator type

	A typedef to an iterator type over #fcppt::string
	*/
	typedef
	fcppt::log::detail::location_vector::const_iterator
	const_iterator;

	/**
	\brief Adds a new element to this location

	Adds \a name to this location
	*/
	FCPPT_LOG_DETAIL_SYMBOL
	fcppt::log::location &
	operator /=(
		fcppt::log::name name
	);

	/**
	\brief Returns an iterator to the beginning
	*/
	FCPPT_LOG_DETAIL_SYMBOL
	const_iterator
	begin() const;

	/**
	\brief Returns an iterator to one past the end
	*/
	FCPPT_LOG_DETAIL_SYMBOL
	const_iterator
	end() const;

	/**
	\brief Creates a string represenation of the location using :: as
	delimiter.
	*/
	FCPPT_LOG_DETAIL_SYMBOL
	fcppt::string
	string() const;
private:
	fcppt::log::detail::location_vector entries_;
};

/**
\brief Forms a new location by appending a name

Forms a new location from \a location and \a name.
*/
FCPPT_LOG_DETAIL_SYMBOL
fcppt::log::location
operator /(
	fcppt::log::location location,
	fcppt::log::name element
);

}
}

#endif
