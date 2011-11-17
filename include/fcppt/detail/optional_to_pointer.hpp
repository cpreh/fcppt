//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_DETAIL_OPTIONAL_TO_POINTER_HPP_INCLUDED
#define FCPPT_DETAIL_OPTIONAL_TO_POINTER_HPP_INCLUDED

#include <fcppt/null_ptr.hpp>
#include <fcppt/optional_fwd.hpp>


namespace fcppt
{
namespace detail
{

template<
	typename T
>
typename fcppt::optional<T>::pointer
optional_to_pointer(
	fcppt::optional<T> const &_opt
)
{
	return
		_opt.has_value()
		?
			&*_opt
		:
			fcppt::null_ptr
		;
}

}
}

#endif
