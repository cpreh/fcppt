//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_LOG_CONTEXT_LOCATION_HPP_INCLUDED
#define FCPPT_LOG_CONTEXT_LOCATION_HPP_INCLUDED

#include <fcppt/reference_wrapper.hpp>
#include <fcppt/symbol.hpp>
#include <fcppt/log/context_fwd.hpp>
#include <fcppt/log/context_location_fwd.hpp>
#include <fcppt/log/location.hpp>


namespace fcppt
{
namespace log
{

/// Represents a location of a logger
class context_location
{
public:
	FCPPT_SYMBOL
	context_location(
		fcppt::log::context &,
		fcppt::log::location const &
	);

	FCPPT_SYMBOL
	fcppt::log::context &
	context() const;

	FCPPT_SYMBOL
	fcppt::log::location const &
	location() const;
private:
	typedef fcppt::reference_wrapper<
		fcppt::log::context
	> context_reference;

	context_reference context_;

	fcppt::log::location location_;
};

}
}

#endif
