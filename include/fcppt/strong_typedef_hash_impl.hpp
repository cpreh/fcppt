//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_STRONG_TYPEDEF_HASH_IMPL_HPP_INCLUDED
#define FCPPT_STRONG_TYPEDEF_HASH_IMPL_HPP_INCLUDED

#include <fcppt/strong_typedef_hash_decl.hpp>
#include <fcppt/strong_typedef_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstddef>
#include <functional>
#include <fcppt/config/external_end.hpp>


template<
	typename Type,
	typename Alias
>
std::size_t
fcppt::strong_typedef_hash<
	fcppt::strong_typedef<
		Type,
		Alias
	>
>::operator()(
	type const &_value
) const
{
	return
		std::hash<
			Type
		>()(
			_value.get()
		);
}

#endif
