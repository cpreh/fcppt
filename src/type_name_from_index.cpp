//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/string.hpp>
#include <fcppt/type_name.hpp>
#include <fcppt/type_name_from_index.hpp>
#include <fcppt/config/external_begin.hpp>
#include <typeindex>
#include <fcppt/config/external_end.hpp>


fcppt::string
fcppt::type_name_from_index(
	std::type_index const &_index
)
{
	return
		fcppt::type_name(
			_index.name()
		);
}
