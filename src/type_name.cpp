//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/from_std_string.hpp>
#include <fcppt/string.hpp>
#include <fcppt/type_name.hpp>
#include <fcppt/private_config.hpp>
#if defined(FCPPT_HAVE_GCC_DEMANGLE)
#include <fcppt/c_deleter.hpp>
#include <fcppt/scoped_ptr.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cxxabi.h>
#include <fcppt/config/external_end.hpp>
#endif


fcppt::string
fcppt::type_name(
	char const *const _name
)
{
#if defined(FCPPT_HAVE_GCC_DEMANGLE)
	int status;

	fcppt::scoped_ptr<
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

	// demangling failed?
	return
		status
		?
			fcppt::from_std_string(
				_name
			)
		:
			fcppt::from_std_string(
				name.get()
			);
#else
	return
		fcppt::from_std_string(
			_name
		);
#endif
}
