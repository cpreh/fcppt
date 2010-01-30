//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_LOG_CONTEXT_HPP_INCLUDED
#define FCPPT_LOG_CONTEXT_HPP_INCLUDED

#include <fcppt/log/context_fwd.hpp>
#include <fcppt/log/object_fwd.hpp>
#include <fcppt/log/location_fwd.hpp>
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
	FCPPT_NONCOPYABLE(context)
public:
	FCPPT_SYMBOL context();

	FCPPT_SYMBOL ~context();

	/// Adds a logger to a location
	/** The logger will call this indirectly if you provide a context in its parameters class.
	*/
	FCPPT_SYMBOL void
	add(
		location const &,
		object &
	);

	/// Removes the logger that is associated with a location.
	/* Loggers with a location set will indirectly call this on destruction.
	*/
	FCPPT_SYMBOL void
	remove(
		location const &
	);

	/// Finds a logger with a given location.
	/** @return 0 if the logger was not found
	*/
	FCPPT_SYMBOL object *
	find(
		location const &
	) const;

	/// apply a function to a location recursively
	FCPPT_SYMBOL void
	apply(
		location const &,
		tree_function const &
	);
private:
	detail::context_tree tree_;
};

}
}

#endif
