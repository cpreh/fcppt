//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/string.hpp>
#include <fcppt/type_name.hpp>
#include <fcppt/type_name_from_info.hpp>
#include <fcppt/config/external_begin.hpp>
#include <typeinfo>
#include <fcppt/config/external_end.hpp>


fcppt::string
fcppt::type_name_from_info(
	std::type_info const &_info
)
{
	return
		fcppt::type_name(
			_info.name()
		);
}
