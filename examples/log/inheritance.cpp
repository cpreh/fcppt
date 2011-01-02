//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


//[loginheritance
#include <fcppt/log/object.hpp>
#include <fcppt/log/headers.hpp>
#include <fcppt/log/parameters/root.hpp>
#include <fcppt/log/parameters/inherited.hpp>
#include <fcppt/log/level.hpp>
#include <fcppt/io/cout.hpp>
#include <fcppt/text.hpp>

int main()
{
	fcppt::log::object parent_(
		fcppt::log::parameters::root(
			fcppt::io::cout
		)
		.prefix(
			FCPPT_TEXT("parent")
		)
		.enabled(
			true
		)
		.level(
			fcppt::log::level::debug
		)
		.create()
	);

	fcppt::log::object child_(
		fcppt::log::parameters::inherited(
			parent_,
			FCPPT_TEXT("child")
		)
	);

	// Outputs: parent: child: Print from child.
	FCPPT_LOG_DEBUG(
		child_,
		fcppt::log::_
			<< FCPPT_TEXT("Print from child.")
	);
}
//]
