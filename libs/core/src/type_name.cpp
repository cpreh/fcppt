//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/type_name.hpp>
#include <fcppt/impl/private_config.hpp>
#if defined(FCPPT_HAVE_GCC_DEMANGLE)
#include <fcppt/c_deleter.hpp>
#include <fcppt/unique_ptr.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cxxabi.h>
#include <fcppt/config/external_end.hpp>
#endif
#include <fcppt/config/external_begin.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>


std::string
fcppt::type_name(
	char const *const _name
)
{
#if defined(FCPPT_HAVE_GCC_DEMANGLE)
	int status;

	fcppt::unique_ptr<
		char,
		fcppt::c_deleter
	> name(
		abi::__cxa_demangle(
			_name,
			nullptr,
			nullptr,
			&status
		)
	);

	return
		status != 0
		?
			std::string{
				_name
			}
		:
			std::string{
				name.get_pointer()
			}
		;
#else
	return
		std::string{
			_name
		};
#endif
}
