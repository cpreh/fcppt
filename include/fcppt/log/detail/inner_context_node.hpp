//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_LOG_DETAIL_INNER_CONTEXT_NODE_HPP_INCLUDED
#define FCPPT_LOG_DETAIL_INNER_CONTEXT_NODE_HPP_INCLUDED

#include <fcppt/log/detail/inner_context_node_fwd.hpp>
#include <fcppt/string.hpp>


namespace fcppt
{
namespace log
{
namespace detail
{

class inner_context_node
{
public:
	explicit
	inner_context_node(
		fcppt::string const &name
	);

	fcppt::string const &
	name() const;
private:
	fcppt::string name_;
};

}
}
}

#endif
