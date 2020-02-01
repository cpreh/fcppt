//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/string.hpp>
#include <fcppt/system.hpp>
#include <fcppt/config/platform.hpp>
#include <fcppt/optional/object_impl.hpp>
#if defined(FCPPT_CONFIG_POSIX_PLATFORM)
#include <fcppt/exception.hpp>
#include <fcppt/text.hpp>
#include <fcppt/to_std_string.hpp>
#include <fcppt/optional/make_if.hpp>
#include <fcppt/optional/to_exception.hpp>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#elif defined(FCPPT_CONFIG_WINDOWS_PLATFORM)
#include <fcppt/const.hpp>
#include <fcppt/public_config.hpp>
#include <fcppt/optional/make_if.hpp>
#include <stdlib.h>
#endif


fcppt::optional::object<
	int
>
fcppt::system(
	fcppt::string const &_command
)
{
#if defined(FCPPT_CONFIG_POSIX_PLATFORM)
	int const result{
		::system(
			fcppt::optional::to_exception(
				fcppt::to_std_string(
					_command
				),
				[
					&_command
				]{
					return
						fcppt::exception{
							FCPPT_TEXT("Failed to convert command \"")
							+
							_command
							+
							FCPPT_TEXT("\" for fcppt::system!")
						};
				}
			).c_str()
		)
	};

	return
		fcppt::optional::make_if(
			WIFEXITED(
				result
			),
			[
				result
			]{
				return
					WEXITSTATUS(
						result
					);
			}
		);
#elif defined(FCPPT_CONFIG_WINDOWS_PLATFORM)
	int const result{
#if defined(FCPPT_NARROW_STRING)
		::system(
#else
		_wsystem(
#endif
			_command.c_str()
		)
	};

	return
		fcppt::optional::make_if(
			result
			!=
			-1,
			fcppt::const_(
				result
			)
		);
#else
#error "Implement me!"
#endif
}
