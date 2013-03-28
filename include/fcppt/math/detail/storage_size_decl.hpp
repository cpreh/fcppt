//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DETAIL_STORAGE_SIZE_DECL_HPP_INCLUDED
#define FCPPT_MATH_DETAIL_STORAGE_SIZE_DECL_HPP_INCLUDED

#include <fcppt/nonassignable.hpp>
#include <fcppt/math/detail/storage_size_decl.hpp>


namespace fcppt
{
namespace math
{
namespace detail
{

template<
	typename Size
>
class storage_size
{
	FCPPT_NONASSIGNABLE(
		storage_size
	);
public:
	typedef Size size_type;

	explicit
	storage_size(
		size_type
	);

	size_type
	get() const;
private:
	size_type const size_;
};

}
}
}

#endif
