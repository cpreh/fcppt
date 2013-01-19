//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/nonassignable.hpp>
#include <fcppt/string.hpp>
#include <fcppt/log/detail/context_tree.hpp>
#include <fcppt/log/detail/inner_context_node.hpp>
#include <fcppt/log/detail/outer_context_node.hpp>
#include <fcppt/src/log/inner_node_name.hpp>
#include <fcppt/variant/apply_unary.hpp>


namespace
{

class compare
{
	FCPPT_NONASSIGNABLE(
		compare
	);
public:
	typedef bool result_type;

	explicit
	compare(
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
	fcppt::string const &_name
)
:
	name_(
		_name
	)
{
}

fcppt::log::inner_node_name::result_type
fcppt::log::inner_node_name::operator()(
	fcppt::log::detail::context_tree const &_tree
) const
{
	return
		fcppt::variant::apply_unary(
			::compare(
				name_
			),
			_tree.value().get()
		);
}

namespace
{

compare::compare(
	fcppt::string const &_name
)
:
	name_(
		_name
	)
{
}

compare::result_type
compare::operator()(
	fcppt::log::detail::inner_context_node const &_inner_node
) const
{
	return
		_inner_node.name() == name_;
}

compare::result_type
compare::operator()(
	fcppt::log::detail::outer_context_node const &
) const
{
	return
		false;
}

}
