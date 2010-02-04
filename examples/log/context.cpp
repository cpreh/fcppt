//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


//[logcontext
#include <fcppt/log/object.hpp>
#include <fcppt/log/headers.hpp>
#include <fcppt/log/parameters/root.hpp>
#include <fcppt/log/parameters/inherited.hpp>
#include <fcppt/log/context.hpp>
#include <fcppt/log/level.hpp>
#include <fcppt/io/cout.hpp>
#include <fcppt/function/object.hpp>
#include <fcppt/tr1/functional.hpp>
#include <fcppt/text.hpp>

int main()
{
	fcppt::log::context context_;

	fcppt::log::object parent_(
		fcppt::log::parameters::root(
			fcppt::io::cout
		)
		.prefix(
			FCPPT_TEXT("root")
		)
		.context(
			context_
		)
		.create()
	);

	fcppt::log::object child_(
		fcppt::log::parameters::inherited(
			parent_,
			FCPPT_TEXT("child")
		)
	);

	context_.apply(
		fcppt::log::location(
			FCPPT_TEXT("root")
		)
		+ FCPPT_TEXT("child"),
		std::tr1::bind(
			&fcppt::log::object::enable,
			std::tr1::placeholders::_1,
			true
		)
	);

	FCPPT_LOG_WARNING(
		child_,
		fcppt::log::_
			<< FCPPT_TEXT("Print from child.")
	);
}
//]
