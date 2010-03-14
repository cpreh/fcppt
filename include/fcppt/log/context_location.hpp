//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_LOG_CONTEXT_LOCATION_HPP_INCLUDED
#define FCPPT_LOG_CONTEXT_LOCATION_HPP_INCLUDED

#include <fcppt/log/context_location_fwd.hpp>
#include <fcppt/log/location.hpp>
#include <fcppt/log/context_fwd.hpp>
#include <fcppt/optional_impl.hpp>
#include <fcppt/symbol.hpp>

namespace fcppt
{
namespace log
{

/// Represents an optional location of a logger
/**
 * The supplied log::context can be 0
 * The location can be the empty location
*/
class context_location
{
public:
	FCPPT_SYMBOL context_location();

	FCPPT_SYMBOL context_location(
		log::context *,
		log::location const &
	);

	FCPPT_SYMBOL log::context *
	context() const;

	FCPPT_SYMBOL log::location const &
	location() const;
private:
	typedef optional<
		log::location
	> optional_location;

	log::context *context_;

	optional_location location_;
};

}
}

#endif
