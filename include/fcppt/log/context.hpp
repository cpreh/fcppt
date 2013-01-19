//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_LOG_CONTEXT_HPP_INCLUDED
#define FCPPT_LOG_CONTEXT_HPP_INCLUDED

#include <fcppt/noncopyable.hpp>
#include <fcppt/symbol.hpp>
#include <fcppt/log/context_fwd.hpp>
#include <fcppt/log/location_fwd.hpp>
#include <fcppt/log/object_fwd.hpp>
#include <fcppt/log/optional_object_fwd.hpp>
#include <fcppt/log/tree_function.hpp>
#include <fcppt/log/detail/auto_context_fwd.hpp>
#include <fcppt/log/detail/context_tree.hpp>


namespace fcppt
{
namespace log
{

/**
\brief The logger context class is used for finding loggers at runtime.

\ingroup fcpptlog

An object of this class should be declared as static inside a function. This
ensures that it is available before every global logger gets constructed. The
context object can be passed using
fcppt::log::parameters::object::context_location. Logger objects can then later
be queried providing their location using this class.
*/
class context
{
	FCPPT_NONCOPYABLE(
		context
	);
public:
	/**
	\brief Constructs a context with no locations
	*/
	FCPPT_SYMBOL
	context();

	/**
	\brief Destroys a context

	It is important that all the logger objects that are associated with
	this context are already destroyed.

	\warning The behaviour is undefined if this context still has
	associated logger objects.
	*/
	FCPPT_SYMBOL
	~context();

	/**
	\brief Searches for a logger with a given location.

	Searches for a logger whose location is \a location.

	\param location The location to search

	\return If the logger is found, it will be returned, otherwise an empty
	fcppt::log::optional_object will be returned.
	*/
	FCPPT_SYMBOL
	fcppt::log::optional_object const
	find(
		fcppt::log::location const &location
	) const;

	/**
	\brief Applies a function to all logers given a location recursively

	Applies \a function to the loggers at \a location and below.

	\throw fcppt::log::no_such_location if the location doesn't exist
	*/
	FCPPT_SYMBOL
	void
	apply(
		fcppt::log::location const &location,
		fcppt::log::tree_function const &function
	);
private:
	friend class fcppt::log::detail::auto_context;

	fcppt::log::detail::context_tree &
	add(
		fcppt::log::location const &,
		fcppt::log::object &
	);

	void
	remove(
		fcppt::log::detail::context_tree &
	);

	fcppt::log::detail::context_tree tree_;
};

}
}

#endif
