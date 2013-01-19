//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/log/detail/outer_context_node.hpp>

fcppt::log::detail::outer_context_node::outer_context_node(
	log::object &_object
)
:
	object_(_object)
{}

fcppt::log::object &
fcppt::log::detail::outer_context_node::object() const
{
	return object_;
}
