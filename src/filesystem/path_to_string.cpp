//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/string.hpp>
#include <fcppt/config/warnings.hpp>
#include <fcppt/filesystem/path_to_string.hpp>
#include <fcppt/preprocessor/disable_vc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/filesystem/path.hpp>
#include <fcppt/config/external_end.hpp>


fcppt::string const
fcppt::filesystem::path_to_string(
	boost::filesystem::path const &_path
)
{
FCPPT_PP_PUSH_WARNING
#if defined(FCPPT_CONFIG_HAVE_4347_WARNING)
FCPPT_PP_DISABLE_VC_WARNING(4347)
#endif
	return
		_path.string<
			fcppt::string
		>();
FCPPT_PP_POP_WARNING
}
