//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/text.hpp>
#include <fcppt/filesystem/normalize.hpp>
#include <fcppt/filesystem/stem.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/filesystem/path.hpp>
#include <fcppt/config/external_end.hpp>


boost::filesystem::path
fcppt::filesystem::normalize(
	boost::filesystem::path const &_path
)
{
	return
		fcppt::filesystem::stem(
			_path
		)
		==
		FCPPT_TEXT(".")
		?
			boost::filesystem::path(
				_path
			).remove_filename()
		:
			_path
		;
}
