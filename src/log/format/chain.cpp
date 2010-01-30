//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/log/format/chain.hpp>
#include <fcppt/text.hpp>
#include <fcppt/exception.hpp>

fcppt::log::format::chain::chain(
	const_object_ptr const parent,
	const_object_ptr const child
)
:
	parent(parent),
	child(child)
{
	if(!parent || !child)
		throw exception(
			FCPPT_TEXT("format::chain(): one of the objects is zero!")
		);
}

fcppt::log::format::chain::~chain()
{}

fcppt::string const
fcppt::log::format::chain::format(
	string const &str
) const
{
	return parent->format(
		child->format(
			str
		)
	);
}
