//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DETAIL_HASH_DECL_HPP_INCLUDED
#define FCPPT_MATH_DETAIL_HASH_DECL_HPP_INCLUDED

#include <fcppt/math/detail/hash_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstddef>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace math
{
namespace detail
{

template<
	typename Type
>
struct hash
{
	std::size_t
	operator()(
		Type const &
	) const;
};

}
}
}

#endif
