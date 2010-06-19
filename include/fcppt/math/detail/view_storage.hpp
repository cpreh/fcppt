//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DETAIL_VIEW_STORAGE_HPP_INCLUDED
#define FCPPT_MATH_DETAIL_VIEW_STORAGE_HPP_INCLUDED

namespace fcppt
{
namespace math
{
namespace detail
{

template<
	typename T,
	typename N
>
class view_storage
{
public:
	typedef T value_type;
	typedef typename N::value_type size_type;
	typedef T &reference;
	typedef T *pointer;

	view_storage(
		pointer,
		size_type index,
		size_type stride,
		size_type size
	);

	reference
	operator[](
		size_type
	) const;

	pointer
	data() const;

	size_type
	size() const;
private:
	pointer rep;

	size_type
		index,
		stride,
		sz;
};

}
}
}

#endif
