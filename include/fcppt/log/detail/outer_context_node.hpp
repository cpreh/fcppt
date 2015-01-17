//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_LOG_DETAIL_OUTER_CONTEXT_NODE_HPP_INCLUDED
#define FCPPT_LOG_DETAIL_OUTER_CONTEXT_NODE_HPP_INCLUDED

#include <fcppt/nonassignable.hpp>
#include <fcppt/log/object_fwd.hpp>
#include <fcppt/log/detail/outer_context_node_fwd.hpp>


namespace fcppt
{
namespace log
{
namespace detail
{

class outer_context_node
{
	FCPPT_NONASSIGNABLE(
		outer_context_node
	);
public:
	explicit
	outer_context_node(
		fcppt::log::object &
	);

	fcppt::log::object &
	object() const;
private:
	fcppt::log::object &object_;
};

}
}
}

#endif
