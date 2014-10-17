//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_LOG_LOCATION_HPP_INCLUDED
#define FCPPT_LOG_LOCATION_HPP_INCLUDED

#include <fcppt/string.hpp>
#include <fcppt/log/location_fwd.hpp>
#include <fcppt/log/symbol.hpp>
#include <fcppt/log/detail/location_vector.hpp>


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
	FCPPT_LOG_SYMBOL
	location();

	/**
	\brief Constructs a location with one element

	Constructs a location with one element given by \a root

	\param root The root element
	*/
	FCPPT_LOG_SYMBOL
	explicit
	location(
		fcppt::string const &root
	);

	/**
	\brief The iterator type

	A typedef to an iterator type over \link fcppt::string \endlink
	*/
	typedef fcppt::log::detail::location_vector::const_iterator const_iterator;

	/**
	\brief Adds a new element to this location

	Adds \a element to this location

	\param element The new element
	*/
	FCPPT_LOG_SYMBOL
	fcppt::log::location &
	operator /=(
		fcppt::string const &element
	);

	/**
	\brief Returns an iterator to the beginning
	*/
	FCPPT_LOG_SYMBOL
	const_iterator
	begin() const;

	/**
	\brief Returns an iterator to one past the end
	*/
	FCPPT_LOG_SYMBOL
	const_iterator
	end() const;

	/**
	\brief Creates a string represenation of the location using :: as
	delimiter.
	*/
	FCPPT_LOG_SYMBOL
	fcppt::string
	string() const;
private:
	fcppt::log::detail::location_vector entries_;
};

/**
\brief Concatenates a location and an element

Concatenates \a location and \a element.

\param location The location to concatenate to

\param element The element to concatenate

\return A new location that is the concatenation of \a location and \a element
*/
FCPPT_LOG_SYMBOL
fcppt::log::location
operator /(
	fcppt::log::location location,
	fcppt::string const &element
);

}
}

#endif
