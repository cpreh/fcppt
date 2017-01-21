//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/string.hpp>
#include <fcppt/text.hpp>
#include <fcppt/options/custom_pretty_type.hpp>
#include <fcppt/config/external_begin.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>


fcppt::string
fcppt::options::custom_pretty_type<
	std::string
>::get()
{
	return
		FCPPT_TEXT("string");
}

fcppt::string
fcppt::options::custom_pretty_type<
	std::wstring
>::get()
{
	return
		FCPPT_TEXT("string");
}
