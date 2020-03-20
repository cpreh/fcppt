//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/container/find_opt_iterator.hpp>
#include <fcppt/container/get_or_insert.hpp>
#include <fcppt/optional/maybe_void.hpp>
#include <fcppt/preprocessor/disable_clang_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/signal/auto_connection.hpp>
#include <fcppt/signal/object.hpp>
#include <fcppt/signal/unregister/base.hpp>
#include <fcppt/signal/unregister/function.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstdlib>
#include <exception>
#include <iostream>
#include <unordered_map>
#include <string>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace
{

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_CLANG_WARNING(-Wglobal-constructors)
FCPPT_PP_DISABLE_CLANG_WARNING(-Wexit-time-destructors)

// ![global_map]
using signal_type =
fcppt::signal::object<
	void(),
	fcppt::signal::unregister::base
>;

using name_to_signal =
std::unordered_map<
	std::string,
	signal_type
>;

// NOLINTNEXTLINE(fuchsia-statically-constructed-objects)
name_to_signal global_name_to_signal{};

// This function will be called whenever a connection dies. It receives the
// signal's name.
void remove_function(std::string const &_name)
{
	std::cout << "Goodbye, " << _name << "!\n";

	fcppt::optional::maybe_void(
		fcppt::container::find_opt_iterator(
			global_name_to_signal,
			_name
		),
		[](name_to_signal::iterator const _pos)
		{
			// "empty" returns true if there are connections attached to the signal.
			if(_pos->second.empty())
			{
				global_name_to_signal.erase(_pos);
			}
		}
	);
}
// ![global_map]

FCPPT_PP_POP_WARNING

// ![register]
fcppt::signal::auto_connection
register_named_signal(
	std::string const &_name,
	fcppt::signal::unregister::function &&_function
)
{
	signal_type &signal{
		fcppt::container::get_or_insert(
			global_name_to_signal,
			_name,
			[](std::string const &)
			{
				return
					signal_type();
			}
		)
	};

	return
		signal.connect(
			std::move(_function),
			// Add our remove function as the disconnect handler (see above)
			fcppt::signal::unregister::function{
				[_name]{
					remove_function(
						_name
					);
				}
			}
		);
}
// ![register]

}

int
main()
try
{
// ![main]
	fcppt::signal::auto_connection const hello_connection(
		register_named_signal(
			"hello",
			fcppt::signal::unregister::function{
				[]{
					std::cout << "hello!\n";
				}
			}
		)
	);

	// Will print "goodbye"
	global_name_to_signal["hello"]();

	{
		fcppt::signal::auto_connection const goodbye_connection(
			register_named_signal(
				"goodbye",
				fcppt::signal::unregister::function{
					[]{
						std::cout << "goodbye!\n";
					}
				}
			)
		);

		// Will print "goodbye!"
		global_name_to_signal["goodbye"]();

		// Will print "Goodbye goodbye!" at end of scope
	}

	// Will print "Goodbye hello!" at end of scope
// ![main]
	return
		EXIT_SUCCESS;
}
catch(
	std::exception const &_error
)
{
	std::cerr
		<<
		_error.what()
		<<
		'\n';

	return
		EXIT_FAILURE;
}
