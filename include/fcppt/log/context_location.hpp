//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_LOG_CONTEXT_LOCATION_HPP_INCLUDED
#define FCPPT_LOG_CONTEXT_LOCATION_HPP_INCLUDED

#include <fcppt/reference_wrapper_impl.hpp>
#include <fcppt/log/context_fwd.hpp>
#include <fcppt/log/context_location_fwd.hpp>
#include <fcppt/log/location.hpp>
#include <fcppt/log/detail/symbol.hpp>


namespace fcppt
{
namespace log
{

/**
\brief Represents a location of a logger in a context

\ingroup fcpptlog

Represents an \link fcppt::log::location \endlink in an \link
fcppt::log::context \endlink. An object of this class can be used as a
parameter to \link fcppt::log::parameters::context_location \endlink.
*/
class context_location
{
public:
	/**
	\brief Constructs a context location

	Constructs a context location for \a context and \a location.

	\param context The context to associate with

	\param location The location in the context
	*/
	FCPPT_LOG_DETAIL_SYMBOL
	context_location(
		fcppt::log::context &context,
		fcppt::log::location const &location
	);

	/**
	\brief Returns the associated context
	*/
	FCPPT_LOG_DETAIL_SYMBOL
	fcppt::log::context &
	context() const;

	/**
	\brief Returns the location in the context
	*/
	FCPPT_LOG_DETAIL_SYMBOL
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
