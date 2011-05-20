//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/filesystem/readlink.hpp>
#include <fcppt/filesystem/config.hpp>
#ifdef FCPPT_USE_FILESYSTEM_V3
#include <boost/filesystem/operations.hpp>
#else
#include <fcppt/filesystem/exception.hpp>
#include <fcppt/text.hpp>
#include <fcppt/platform.hpp>
#ifdef FCPPT_POSIX_PLATFORM
#include <fcppt/container/raw_vector_impl.hpp>
#include <fcppt/error/strerrno.hpp>
#include <fcppt/from_std_string.hpp>
#include <fcppt/to_std_string.hpp>
#include <unistd.h>
#include <cerrno>
#endif
#endif

fcppt::filesystem::path const
fcppt::filesystem::readlink(
#if defined(FCPPT_POSIX_PLATFORM) || defined(FCPPT_USE_FILESYSTEM_V3)
	fcppt::filesystem::path const &_link
#else
	fcppt::filesystem::path const &
#endif
)
{
#ifdef FCPPT_USE_FILESYSTEM_V3
	return
		boost::filesystem::read_symlink(
			_link
		);
#else
#ifdef FCPPT_POSIX_PLATFORM
	typedef
	container::raw_vector<
		char
	> buffer_type;

	buffer_type buf;

	buf.reserve(
		512
	);

	for (;;)
	{
		ssize_t const ret(
			::readlink(
				fcppt::to_std_string(
					_link.string()
				).c_str(),
				buf.data(),
				buf.capacity()
			)
		);

		if(ret == -1)
		{
			switch(
				errno
			)
			{
			case EINVAL:
				return path();
			case ENAMETOOLONG:
				buf.reserve(
					buf.capacity() * 2
				);
				continue;
			default:
				throw fcppt::filesystem::exception(
					FCPPT_TEXT("readlink failed: ")
					+ error::strerrno()
				);
			}
		}

		buf.resize_uninitialized(
			static_cast<
				buffer_type::size_type
			>(
				ret
			)
		);

		buf.push_back(0);

		return
			fcppt::filesystem::path(
				fcppt::from_std_string(
					buf.data()
				)
			);
	}
#else
	throw fcppt::filesystem::exception(
		FCPPT_TEXT("readlink not supported!")
	);
#endif
#endif
}
