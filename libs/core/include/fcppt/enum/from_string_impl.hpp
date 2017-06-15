//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ENUM_FROM_STRING_IMPL_HPP_INCLUDED
#define FCPPT_ENUM_FROM_STRING_IMPL_HPP_INCLUDED

#include <fcppt/string.hpp>
#include <fcppt/enum/from_string_impl_fwd.hpp>
#include <fcppt/enum/index_of_array.hpp>
#include <fcppt/enum/names.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace enum_
{

/**
\brief Customization point to convert a string to an enum.

\ingroup fcpptenum

The default implementation uses \link fcppt::enum_names\endlink.

\tparam Enum Must be an enum type
*/
template<
	typename Enum,
	typename Enable
>
struct from_string_impl
{
	static_assert(
		std::is_enum<
			Enum
		>::value,
		"Enum must be an enum type"
	);

	static
	fcppt::optional::object<
		Enum
	>
	get(
		fcppt::string const &_string
	)
	{
		return
			fcppt::enum_::index_of_array(
				fcppt::enum_::names<
					Enum
				>(),
				_string
			);
	}
};

}
}

#endif
