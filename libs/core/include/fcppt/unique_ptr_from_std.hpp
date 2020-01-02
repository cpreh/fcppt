//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_UNIQUE_PTR_FROM_STD_HPP_INCLUDED
#define FCPPT_UNIQUE_PTR_FROM_STD_HPP_INCLUDED

#include <fcppt/unique_ptr_impl.hpp>
#include <fcppt/optional/make_if.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <memory>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{

/**
\brief Converts a <code>std::unique_ptr</code> to an fcppt unique ptr.

\ingroup fcpptsmartptr
*/
template<
	typename Type
>
fcppt::optional::object<
	fcppt::unique_ptr<
		Type
	>
>
unique_ptr_from_std(
	std::unique_ptr<
		Type
	> &&_ptr
)
{
	return
		fcppt::optional::make_if(
			_ptr.get()
			!=
			nullptr,
			[
				&_ptr
			]{
				return
					fcppt::unique_ptr<
						Type
					>(
						_ptr.release()
					);
			}
		);
}

}

#endif
