//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_REFERENCE_WRAPPER_HASH_IMPL_HPP_INCLUDED
#define FCPPT_REFERENCE_WRAPPER_HASH_IMPL_HPP_INCLUDED

#include <fcppt/reference_wrapper_impl.hpp>
#include <fcppt/reference_wrapper_hash_decl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstddef>
#include <functional>
#include <fcppt/config/external_end.hpp>


// \cond

template<
	typename Type
>
std::size_t
fcppt::reference_wrapper_hash<
	fcppt::reference_wrapper<
		Type
	>
>::operator()(
	type const &_value
) const
{
	return
		std::hash<
			Type *
		>()(
			_value.get_pointer()
		);
}

// \endcond

#endif
