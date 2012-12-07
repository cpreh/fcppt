//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/assert/pre.hpp>
#include <fcppt/log/format/chain.hpp>
#include <fcppt/log/format/create_chain.hpp>
#include <fcppt/log/format/function.hpp>
#include <fcppt/config/external_begin.hpp>
#include <functional>
#include <fcppt/config/external_end.hpp>


fcppt::log::format::function const
fcppt::log::format::create_chain(
	fcppt::log::format::function const &_parent,
	fcppt::log::format::function const &_child
)
{
	FCPPT_ASSERT_PRE(
		_parent
		||
		_child
	);

	if(
		!_parent
	)
		return _child;

	if(
		!_child
	)
		return _parent;

	return
		fcppt::log::format::function(
			std::bind(
				fcppt::log::format::chain,
				_parent,
				_child,
				std::placeholders::_1
			)
		);
}
