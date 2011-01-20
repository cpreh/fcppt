//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/log/format/create_chain.hpp>
#include <fcppt/log/format/chain.hpp>
#include <fcppt/make_shared_ptr.hpp>

fcppt::log::format::const_object_ptr const
fcppt::log::format::create_chain(
	const_object_ptr const parent,
	const_object_ptr const child
)
{
	if(!parent)
		return child;

	if(!child)
		return parent;

	return
		make_shared_ptr<
			chain
		>(
			parent,
			child
		);
}
