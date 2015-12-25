//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONAL_DEREF_HPP_INCLUDED
#define FCPPT_OPTIONAL_DEREF_HPP_INCLUDED

#include <fcppt/optional_impl.hpp>
#include <fcppt/optional_map.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{

/**
\brief Dereferences the contents of an optional

\ingroup fcpptoptional

If the optional is set to <code>x</code>, <code>*x</code> is returned.
For example, this is useful as a shortcut for optionals containing iterators or
unique pointers.
*/
template<
	typename Element
>
inline
fcppt::optional<
	decltype(
		*std::declval<
			Element
		>()
	)
>
optional_deref(
	fcppt::optional<
		Element
	> const &_optional
)
{
	return
		fcppt::optional_map(
			_optional,
			[](
				Element const &_element
			)
			->
			decltype(
				*std::declval<
					Element
				>()
			)
			{
				return
					*_element;
			}
		);
}

}

#endif
