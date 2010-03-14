//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_LOG_LOCATION_HPP_INCLUDED
#define FCPPT_LOG_LOCATION_HPP_INCLUDED

#include <fcppt/log/location_fwd.hpp>
#include <fcppt/log/detail/location_vector.hpp>
#include <fcppt/string.hpp>
#include <fcppt/symbol.hpp>

namespace fcppt
{
namespace log
{

/// location of a logger in a context.
/**
 * A logger's location is the concatenation of its path in the context tree.
 * For example if a logger would inherit from another logger, it will be placed in a child node of the parent's location.
*/
class location
{
public:
	FCPPT_SYMBOL explicit location(
		fcppt::string const &
	);

	typedef detail::location_vector::const_iterator const_iterator;

	FCPPT_SYMBOL location &
	operator +=(
		fcppt::string const &
	);

	FCPPT_SYMBOL const_iterator
	begin() const;

	FCPPT_SYMBOL const_iterator
	end() const;

	/// Creates a string represenation of the location using :: as delimiter.
	FCPPT_SYMBOL fcppt::string const
	string() const;
private:
	detail::location_vector entries_;
};

FCPPT_SYMBOL location const
operator +(
	location,
	string const &
);

}
}

#endif
