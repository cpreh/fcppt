//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONS_MAKE_DEFAULT_VALUE_HPP_INCLUDED
#define FCPPT_OPTIONS_MAKE_DEFAULT_VALUE_HPP_INCLUDED

#include <fcppt/optional/is_object.hpp>
#include <fcppt/options/default_value.hpp>
#include <fcppt/type_traits/remove_cv_ref_t.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace options
{

/**
\brief Creates a default value

\ingroup fcpptoptions

\tparam Type Must be an #fcppt::optional::object.
*/
template<
	typename Type
>
inline
fcppt::options::default_value<
	fcppt::type_traits::remove_cv_ref_t<
		Type
	>
>
make_default_value(
	Type &&_value
)
{
	using
	value_type
	=
	fcppt::type_traits::remove_cv_ref_t<
		Type
	>;

	static_assert(
		fcppt::optional::is_object<
			value_type
		>::value,
		"Type must be an fcppt::optional::object"
	);

	return
		fcppt::options::default_value<
			value_type
		>{
			std::forward<
				Type
			>(
				_value
			)
		};

}

}
}

#endif
