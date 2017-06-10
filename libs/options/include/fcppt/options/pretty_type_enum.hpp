//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONS_PRETTY_TYPE_ENUM_HPP_INCLUDED
#define FCPPT_OPTIONS_PRETTY_TYPE_ENUM_HPP_INCLUDED

#include <fcppt/enum_names.hpp>
#include <fcppt/insert_to_fcppt_string.hpp>
#include <fcppt/container/output.hpp>
#include <fcppt/options/pretty_type_impl_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/utility/enable_if.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace options
{

/**
\brief Specialization for enums that uses \link fcppt::enum_names\endlink.

\ingroup fcpptoptions
*/
template<
	typename Enum
>
struct pretty_type_impl<
	Enum,
	typename
	boost::enable_if<
		std::is_enum<
			Enum
		>
	>::type
>
{
	static
	fcppt::string
	get()
	{
		return
			fcppt::insert_to_fcppt_string(
				fcppt::container::output(
					fcppt::enum_names<
						Enum
					>()
				)
			);
	}
};

}
}

#endif
