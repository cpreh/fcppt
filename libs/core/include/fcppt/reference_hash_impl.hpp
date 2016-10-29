//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_REFERENCE_HASH_IMPL_HPP_INCLUDED
#define FCPPT_REFERENCE_HASH_IMPL_HPP_INCLUDED

#include <fcppt/reference_hash_decl.hpp>
#include <fcppt/reference_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstddef>
#include <functional>
#include <fcppt/config/external_end.hpp>


template<
	typename Type
>
std::size_t
fcppt::reference_hash<
	fcppt::reference<
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
			&_value.get()
		);
}

#endif
