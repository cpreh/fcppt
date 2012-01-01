//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/string.hpp>
#include <fcppt/text.hpp>
#include <fcppt/assert/pre_message.hpp>
#include <fcppt/log/format/chain.hpp>
#include <fcppt/log/format/const_object_ptr.hpp>


fcppt::log::format::chain::chain(
	format::const_object_ptr const _parent,
	format::const_object_ptr const _child
)
:
	parent_(_parent),
	child_(_child)
{
	FCPPT_ASSERT_PRE_MESSAGE(
		parent_ && child_,
		FCPPT_TEXT("format::chain(): one of the objects is zero!")
	);
}

fcppt::log::format::chain::~chain()
{
}

fcppt::string const
fcppt::log::format::chain::format(
	fcppt::string const &_str
) const
{
	return
		parent_->format(
			child_->format(
				_str
			)
		);
}
