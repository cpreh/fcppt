//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ASSIGN_DETAIL_ARRAY_HPP_INCLUDED
#define FCPPT_ASSIGN_DETAIL_ARRAY_HPP_INCLUDED

#include <fcppt/container/array.hpp>
#include <cstddef>

namespace fcppt
{
namespace assign
{
namespace detail
{

template<
	typename T,
	std::size_t N
>
class array
{
public:
	typedef fcppt::container::array<T,N> container_type;

	array(
		T const &
	);

	array(
		array<T,N-1> const &,
		T const &
	);

	array<T,N+1> operator()(T const &);

	operator container_type() const;

	container_type const &
	container() const;
private:
	friend class array<T,N+1>;

	container_type a;
};

}
}
}

#endif
