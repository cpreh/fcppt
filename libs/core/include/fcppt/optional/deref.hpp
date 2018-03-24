//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONAL_DEREF_HPP_INCLUDED
#define FCPPT_OPTIONAL_DEREF_HPP_INCLUDED

#include <fcppt/reference_impl.hpp>
#include <fcppt/optional/map.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace optional
{

/**
\brief Dereferences the contents of an optional

\ingroup fcpptoptional

If the optional is set to <code>x</code>, <code>make_(c)ref(*x)</code> is
returned.  For example, this is useful as a shortcut for optionals containing
iterators or unique pointers.
*/
template<
	typename Element
>
inline
fcppt::optional::object<
	fcppt::reference<
		std::remove_reference_t<
			decltype(
				*std::declval<
					Element
				>()
			)
		>
	>
>
deref(
	fcppt::optional::object<
		Element
	> const &_optional
)
{
	return
		fcppt::optional::map(
			_optional,
			[](
				Element const &_element
			)
			{
				return
					fcppt::reference<
						std::remove_reference_t<
							decltype(
								*std::declval<
									Element
								>()
							)
						>
					>(
						*_element
					);
			}
		);
}

}
}

#endif
