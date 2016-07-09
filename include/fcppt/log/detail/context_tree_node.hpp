//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_LOG_DETAIL_CONTEXT_TREE_NODE_HPP_INCLUDED
#define FCPPT_LOG_DETAIL_CONTEXT_TREE_NODE_HPP_INCLUDED

#include <fcppt/string.hpp>
#include <fcppt/log/setting.hpp>
#include <fcppt/log/detail/context_tree_node_fwd.hpp>


namespace fcppt
{
namespace log
{
namespace detail
{

class context_tree_node
{
public:
	context_tree_node(
		fcppt::string,
		fcppt::log::setting const &
	);

	fcppt::string const &
	location_string() const;

	fcppt::log::setting const &
	setting() const;

	void
	setting(
		fcppt::log::setting const &
	);
private:
	fcppt::string location_string_;

	fcppt::log::setting setting_;
};

}
}
}

#endif
