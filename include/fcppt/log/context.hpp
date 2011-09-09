//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_LOG_CONTEXT_HPP_INCLUDED
#define FCPPT_LOG_CONTEXT_HPP_INCLUDED

#include <fcppt/log/context_fwd.hpp>
#include <fcppt/log/location_fwd.hpp>
#include <fcppt/log/object_fwd.hpp>
#include <fcppt/log/optional_object_fwd.hpp>
#include <fcppt/log/tree_function.hpp>
#include <fcppt/log/detail/context_tree.hpp>
#include <fcppt/container/tree/object_decl.hpp>
#include <fcppt/variant/object_decl.hpp>
#include <fcppt/noncopyable.hpp>
#include <fcppt/symbol.hpp>

namespace fcppt
{
namespace log
{

/// The logger context class is used for finding loggers at runtime.
class context
{
	FCPPT_NONCOPYABLE(
		context
	);
public:
	FCPPT_SYMBOL
	context();

	FCPPT_SYMBOL
	~context();

	/// Adds a logger to a location
	/**
	 * The logger will call this indirectly if you provide a context in its parameters class.
	*/
	void
	add(
		log::location const &,
		log::object &
	);

	/// Removes the logger that is associated with a location.
	/**
	 * Loggers with a location set will indirectly call this on destruction.
	*/
	void
	remove(
		log::location const &
	);

	/// Finds a logger node with a given location
	/**
	 * @return 0 if the logger node was not found
	*/
	log::detail::context_tree const *
	find_node(
		log::location const &
	) const;

	/// Finds a logger with a given location.
	FCPPT_SYMBOL
	log::optional_object const
	find(
		log::location const &
	) const;

	/// Apply a function to a location recursively
	/**
	 * @throws log::no_such_location if the location doesn't exist
	*/
	FCPPT_SYMBOL
	void
	apply(
		log::location const &,
		log::tree_function const &
	);
private:
	detail::context_tree tree_;
};

}
}

#endif
