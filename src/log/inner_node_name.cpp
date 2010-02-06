//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include "inner_node_name.hpp"
#include <fcppt/log/detail/inner_context_node.hpp>
#include <fcppt/log/detail/outer_context_node.hpp>
#include <fcppt/variant/apply_unary.hpp>
#include <fcppt/variant/object_impl.hpp>
#include <fcppt/container/tree/object_impl.hpp>
#include <fcppt/string.hpp>
#include <fcppt/nonassignable.hpp>

namespace
{

class compare
{
	FCPPT_NONASSIGNABLE(compare)
public:
	typedef bool result_type;

	explicit compare(
		fcppt::string const &
	);

	result_type
	operator()(
		fcppt::log::detail::inner_context_node const &
	) const;

	result_type
	operator()(
		fcppt::log::detail::outer_context_node const &
	) const;
private:
	fcppt::string const name_;
};

}

fcppt::log::inner_node_name::inner_node_name(
	string const &name_
)
:
	name_(name_)
{}

fcppt::log::inner_node_name::result_type
fcppt::log::inner_node_name::operator()(
	detail::context_tree const &tree_
) const
{
	return variant::apply_unary(
		compare(
			name_
		),
		tree_.value()
	);
}

namespace
{

compare::compare(
	fcppt::string const &name_
)
:
	name_(name_)
{}

compare::result_type
compare::operator()(
	fcppt::log::detail::inner_context_node const &inner_node_
) const
{
	return inner_node_.name() == name_;
}

compare::result_type
compare::operator()(
	fcppt::log::detail::outer_context_node const &
) const
{
	return false;
}

}
