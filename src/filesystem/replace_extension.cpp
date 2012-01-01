//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/text.hpp>
#include <fcppt/filesystem/replace_extension.hpp>


fcppt::filesystem::path const
fcppt::filesystem::replace_extension(
	filesystem::path const &_path,
	fcppt::string const &_ext
)
{
	return
		filesystem::path(
			_path
		).replace_extension(
			FCPPT_TEXT(".") + _ext
		);
}
