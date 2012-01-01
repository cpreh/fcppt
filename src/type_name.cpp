//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/type_name.hpp>
#include <fcppt/from_std_string.hpp>
#include <fcppt/config.hpp>
#ifdef FCPPT_HAVE_GCC_DEMANGLE
#include <fcppt/config/external_begin.hpp>
#include <cxxabi.h>
#include <fcppt/config/external_end.hpp>
#include <fcppt/scoped_ptr.hpp>
#include <fcppt/c_deleter.hpp>
#endif

fcppt::string const
fcppt::type_name(
	fcppt::type_info const &_info
)
{
#ifdef FCPPT_HAVE_GCC_DEMANGLE
	int status;

	fcppt::scoped_ptr<
		char,
		fcppt::c_deleter
	> name(
		abi::__cxa_demangle(
			_info.get().name(),
			0,
			0,
			&status
		)
	);

	// demangling failed?
	return
		status
		?
			fcppt::from_std_string(
				_info.get().name()
			)
		:
			fcppt::from_std_string(
				name.get()
			);
#else
	return
		fcppt::from_std_string(
			_info.get().name()
		);
#endif
}
