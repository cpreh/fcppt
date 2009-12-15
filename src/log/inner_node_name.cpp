/*
spacegameengine is a portable easy to use game engine written in C++.
Copyright (C) 2006-2009 Carl Philipp Reh (sefi@s-e-f-i.de)

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/


#include "inner_node_name.hpp"
#include <fcppt/log/detail/inner_context_node.hpp>
#include <fcppt/log/detail/outer_context_node.hpp>
#include <fcppt/variant/apply_unary.hpp>
#include <fcppt/variant/object_impl.hpp>
#include <fcppt/container/tree_impl.hpp>
#include <fcppt/string.hpp>

namespace
{

class compare {
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
