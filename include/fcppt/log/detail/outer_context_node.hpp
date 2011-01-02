//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_LOG_DETAIL_OUTER_CONTEXT_NODE_HPP_INCLUDED
#define FCPPT_LOG_DETAIL_OUTER_CONTEXT_NODE_HPP_INCLUDED

#include <fcppt/log/object_fwd.hpp>
#include <fcppt/nonassignable.hpp>

namespace fcppt
{
namespace log
{
namespace detail
{

class outer_context_node
{
	FCPPT_NONASSIGNABLE(outer_context_node)
public:
	explicit outer_context_node(
		log::object &
	);

	log::object &
	object() const;
private:
	log::object &object_;
};

}
}
}

#endif
