//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/string.hpp>
#include <fcppt/text.hpp>
#include <fcppt/filesystem/replace_extension.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/filesystem/path.hpp>
#include <fcppt/config/external_end.hpp>


boost::filesystem::path
fcppt::filesystem::replace_extension(
	boost::filesystem::path const &_path,
	fcppt::string const &_ext
)
{
	return
		boost::filesystem::path(
			_path
		).replace_extension(
			FCPPT_TEXT(".")
			+
			_ext
		);
}
