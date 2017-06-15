//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/signal/auto_connection.hpp>
#include <fcppt/signal/object.hpp>
#include <fcppt/signal/unregister/base.hpp>
#include <fcppt/signal/unregister/function.hpp>
#include <fcppt/config/external_begin.hpp>
#include <functional>
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace
{

// ![global_map]
typedef
fcppt::signal::object<
	void(),
	fcppt::signal::unregister::base
>
signal_type;

typedef
std::map<
	std::string,
	signal_type
>
name_to_signal;

name_to_signal global_name_to_signal;

// This function will be called whenever a connection dies. It receives the
// signal's name.
void
remove_function(
	std::string const &_name
)
{
	std::cout
		<< "Goodbye, "
		<< _name
		<< "!\n";

	// Signal has "empty" to test if there are connections attached to it.
	if(
		global_name_to_signal.find(
			_name
		)->second.empty()
	)
		global_name_to_signal.erase(
			_name
		);
}
// ![global_map]

// ![register]
fcppt::signal::auto_connection
register_named_signal(
	std::string const &_name,
	fcppt::signal::unregister::function const &_function
)
{
	// If the signal doesn't exist, add it to the map.
	if(
		global_name_to_signal.find(
			_name
		)
		==
		global_name_to_signal.end()
	)
		global_name_to_signal.insert(
			std::make_pair(
				_name,
				signal_type()
			)
		);

	return
		global_name_to_signal.find(
			_name
		)->second.connect(
			_function,
			// Add our remove function as the disconnect handler (see above)
			fcppt::signal::unregister::function{
				std::bind(
					&remove_function,
					_name
				)
			}
		);
}
// ![register]

}

// ![main]
int
main()
{
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
	global_name_to_signal.find(
		"hello"
	)->second();

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
		global_name_to_signal.find(
			"goodbye"
		)->second();

		// Will print "Goodbye goodbye!" at end of scope
	}

	// Will print "Goodbye hello!" at end of scope
}
// ![main]
