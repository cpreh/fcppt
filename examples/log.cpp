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


#include <fcppt/log/context.hpp>
#include <fcppt/log/object.hpp>
#include <fcppt/log/global_context.hpp>
#include <fcppt/log/global.hpp>
#include <fcppt/log/parameters/root.hpp>
#include <fcppt/log/parameters/inherited.hpp>
#include <fcppt/log/headers.hpp>
#include <fcppt/function/object.hpp>
#include <fcppt/io/cout.hpp>
#include <fcppt/io/cerr.hpp>
#include <fcppt/tr1/functional.hpp>
#include <fcppt/optional_impl.hpp>
#include <fcppt/exception.hpp>
#include <fcppt/text.hpp>
#include <fcppt/assert.hpp>
#include <cstdlib>

int main()
try
{
	fcppt::log::context context_;

	fcppt::log::object logger(
		fcppt::log::parameters::root(
			fcppt::io::cout
		)
		.enabled(
			true
		)
		.context(
			context_
		)
		.prefix(
			FCPPT_TEXT("fcppt")
		)
		.level(
			fcppt::log::level::debug
		)
		.create()
	);

	fcppt::log::object child_logger(
		fcppt::log::parameters::inherited(
			logger,
			FCPPT_TEXT("child")
		)
	);

	fcppt::log::object *const ref(
		context_.find(
			logger.context_location().location()
		)
	);

	FCPPT_ASSERT(ref);

	FCPPT_LOG_INFO(
		*ref,
		fcppt::log::_
			<< FCPPT_TEXT("test output!")
	);

	fcppt::log::object *const child_ref(
		context_.find(
			fcppt::log::location(
				FCPPT_TEXT("fcppt")
			)
			+ FCPPT_TEXT("child")
		)
	);

	FCPPT_ASSERT(child_ref);

	fcppt::io::cout
		<< FCPPT_TEXT("location of child: ")
		<< child_ref->context_location().location().string()
		<< FCPPT_TEXT('\n');

	FCPPT_LOG_INFO(
		*child_ref,
		fcppt::log::_
			<< FCPPT_TEXT("child output!")
	);

	context_.apply(
		logger.context_location().location(),
		std::tr1::bind(
			&fcppt::log::object::enable,
			std::tr1::placeholders::_1,
			false
		)
	);

	FCPPT_LOG_INFO(
		*child_ref,
		fcppt::log::_
			<< FCPPT_TEXT("shouldn't be shown!")
	);

	fcppt::log::global();

	fcppt::log::object *const global_ref(
		fcppt::log::global_context().find(
			fcppt::log::location(
				FCPPT_TEXT("fcppt")
			)
		)
	);

	FCPPT_ASSERT(global_ref);

	FCPPT_LOG_WARNING(
		*global_ref,
		fcppt::log::_
			<< FCPPT_TEXT("Test global warning log!")
	);
}
catch(
	fcppt::exception const &e
)
{
	fcppt::io::cerr
		<< e.string()
		<< FCPPT_TEXT('\n');
	
	return EXIT_FAILURE;
}
