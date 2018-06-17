//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/options/option_name.hpp>
#include <fcppt/options/option_name_hash.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstddef>
#include <functional>
#include <fcppt/config/external_end.hpp>


std::size_t
fcppt::options::option_name_hash(
	fcppt::options::option_name const &_option_name
)
{
	// TODO: Add boolean as well here
	return
		std::hash<
			fcppt::string
		>{}(
			_option_name.name_
		);
}
