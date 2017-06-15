//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/string.hpp>
#include <fcppt/text.hpp>
#include <fcppt/filesystem/extension.hpp>
#include <fcppt/filesystem/extension_without_dot.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/filesystem/path.hpp>
#include <fcppt/config/external_end.hpp>


fcppt::string
fcppt::filesystem::extension_without_dot(
	boost::filesystem::path const &_path
)
{
	fcppt::string ret(
		fcppt::filesystem::extension(
			_path
		)
	);

	if(
		!ret.empty()
		&& ret[0] == FCPPT_TEXT('.')
	)
		ret.erase(
			ret.begin()
		);

	return
		ret;
}
