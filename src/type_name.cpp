//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/type_name.hpp>
#include <fcppt/iconv.hpp>
#ifdef FCPPT_HAS_GNU_DEMANGLE
#include <cxxabi.h>
#include <fcppt/scoped_ptr.hpp>
#include <fcppt/c_deleter.hpp>
#endif

fcppt::string const
fcppt::type_name(
	fcppt::type_info const &ti)
{
#ifdef FCPPT_HAS_GNU_DEMANGLE
	int status;

	scoped_ptr<
		char,
		c_deleter
	> name(
		abi::__cxa_demangle(
			ti.get().name(),
			0,
			0,
			&status
		)
	);

	// demangling failed?
	return status
		? iconv(ti.get().name())
		: iconv(name.get());
#else
	return iconv(
		ti.get().name()
	);
#endif
}
