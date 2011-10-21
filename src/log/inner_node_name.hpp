//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_LOG_INNER_NODE_NAME_HPP_INCLUDED
#define FCPPT_LOG_INNER_NODE_NAME_HPP_INCLUDED

#include <fcppt/nonassignable.hpp>
#include <fcppt/string.hpp>
#include <fcppt/log/detail/context_tree.hpp>


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

	explicit inner_node_name(
		string const &
	);

	result_type
	operator()(
		detail::context_tree const &
	) const;
private:
	string const name_;
};

}
}

#endif
