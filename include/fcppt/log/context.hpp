//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_LOG_CONTEXT_HPP_INCLUDED
#define FCPPT_LOG_CONTEXT_HPP_INCLUDED

#include <fcppt/noncopyable.hpp>
#include <fcppt/symbol.hpp>
#include <fcppt/container/tree/object_decl.hpp>
#include <fcppt/log/context_fwd.hpp>
#include <fcppt/log/location_fwd.hpp>
#include <fcppt/log/object_fwd.hpp>
#include <fcppt/log/optional_object_fwd.hpp>
#include <fcppt/log/tree_function.hpp>
#include <fcppt/log/detail/auto_context_fwd.hpp>
#include <fcppt/log/detail/context_tree.hpp>
#include <fcppt/log/detail/context_tree_node.hpp>
#include <fcppt/variant/object_decl.hpp>


namespace fcppt
{
namespace log
{

/*
\brief The logger context class is used for finding loggers at runtime.

*/
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

	/**
	\brief Finds a logger with a given location.
	*/
	FCPPT_SYMBOL
	fcppt::log::optional_object const
	find(
		fcppt::log::location const &
	) const;

	/**
	\brief Apply a function to locations recursively

	\throw fcppt::log::no_such_location if the location doesn't exist
	*/
	FCPPT_SYMBOL
	void
	apply(
		fcppt::log::location const &,
		fcppt::log::tree_function const &
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
