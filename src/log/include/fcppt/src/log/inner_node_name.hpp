//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_SRC_LOG_INNER_NODE_NAME_HPP_INCLUDED
#define FCPPT_SRC_LOG_INNER_NODE_NAME_HPP_INCLUDED

#include <fcppt/nonassignable.hpp>
#include <fcppt/string.hpp>
#include <fcppt/log/detail/context_tree_fwd.hpp>


namespace fcppt
{
namespace log
{

class inner_node_name
{
	FCPPT_NONASSIGNABLE(
		inner_node_name
	);
public:
	typedef bool result_type;

	explicit
	inner_node_name(
		fcppt::string const &
	);

	result_type
	operator()(
		fcppt::log::detail::context_tree const &
	) const;
private:
	fcppt::string const name_;
};

}
}

#endif
