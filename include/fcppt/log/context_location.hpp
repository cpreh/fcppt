//          Copyright Carl Philipp Reh 2009 - 2011.
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
		log::context &,
		log::location const &
	);

	FCPPT_SYMBOL
	log::context &
	context() const;

	FCPPT_SYMBOL
	log::location const &
	location() const;
private:
	typedef fcppt::reference_wrapper<
		log::context
	> context_reference;

	context_reference context_;

	log::location location_;
};

}
}

#endif
