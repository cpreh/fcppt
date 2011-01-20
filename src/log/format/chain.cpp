//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/log/format/chain.hpp>
#include <fcppt/log/exception.hpp>
#include <fcppt/text.hpp>

fcppt::log::format::chain::chain(
	const_object_ptr const _parent,
	const_object_ptr const _child
)
:
	parent_(_parent),
	child_(_child)
{
	if(!parent_ || !child_)
		throw fcppt::log::exception(
			FCPPT_TEXT("format::chain(): one of the objects is zero!")
		);
}

fcppt::log::format::chain::~chain()
{}

fcppt::string const
fcppt::log::format::chain::format(
	string const &_str
) const
{
	return
		parent_->format(
			child_->format(
				_str
			)
		);
}
