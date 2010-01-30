//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_LOG_PARAMETERS_ROOT_HPP_INCLUDED
#define FCPPT_LOG_PARAMETERS_ROOT_HPP_INCLUDED

#include <fcppt/log/parameters/root_fwd.hpp>
#include <fcppt/log/parameters/all.hpp>
#include <fcppt/log/level.hpp>
#include <fcppt/log/context_fwd.hpp>
#include <fcppt/io/ostream.hpp>
#include <fcppt/string.hpp>
#include <fcppt/symbol.hpp>

namespace fcppt
{
namespace log
{
namespace parameters
{

/// A parameters class for a logger without parent.
/** At least the associated ostream has to be specified in the constructor.
 * The rest of the parameters can be specified with function calls to this object.
 * All of them have default parameters: 1) empty prefix, 2) not enabled, 3) level is warning
 * 4) no context
 * The create function has to be called last to make the actual parameters class.
*/
class root
{
public:
	FCPPT_SYMBOL explicit root(
		io::ostream &
	);

	FCPPT_SYMBOL root
	prefix(
		string const &
	);

	FCPPT_SYMBOL root
	enabled(
		bool
	);

	FCPPT_SYMBOL root
	level(
		log::level::type
	);

	FCPPT_SYMBOL root
	context(
		log::context &
	);

	FCPPT_SYMBOL all const
	create() const;
private:
	io::ostream &sink_;

	string prefix_;

	bool enabled_;

	log::level::type level_;

	log::context *context_;
};

}
}
}

#endif
