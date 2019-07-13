//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONS_PRETTY_TYPE_ENUM_HPP_INCLUDED
#define FCPPT_OPTIONS_PRETTY_TYPE_ENUM_HPP_INCLUDED

#include <fcppt/output_to_fcppt_string.hpp>
#include <fcppt/container/output.hpp>
#include <fcppt/enum/names.hpp>
#include <fcppt/options/pretty_type_impl_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace options
{

/**
\brief Specialization for enums that uses #fcppt::enum_::names.

\ingroup fcpptoptions
*/
template<
	typename Enum
>
struct pretty_type_impl<
	Enum,
	std::enable_if_t<
		std::is_enum<
			Enum
		>::value
	>
>
{
	static
	fcppt::string
	get()
	{
		return
			fcppt::output_to_fcppt_string(
				fcppt::container::output(
					fcppt::enum_::names<
						Enum
					>()
				)
			);
	}
};

}
}

#endif
